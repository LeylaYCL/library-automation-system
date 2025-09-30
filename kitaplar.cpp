#include "kitaplar.h"
#include <iostream>
#include <fstream>

KitapListesi::KitapListesi() {
    head = nullptr;
}

void KitapListesi::kitapEkle(int id, string ad, string yazar, int adet) {
    Kitap* yeni = new Kitap{ id, ad, yazar, adet, nullptr };
    if (!head) {
        head = yeni;
    } else {
        Kitap* tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = yeni;
    }
}

//Burda tüm kitapların listelenmesi için fonksiyon ile kitapları listeledim
void KitapListesi::kitaplariListele() {
    Kitap* tmp = head;
    while (tmp) {
        cout << tmp->id << " | " << tmp->ad << " | " << tmp->yazar << " | Stok: " << tmp->adet << endl;
        tmp = tmp->next;
    }
}

//Burda kitap arama kısmını yaptım ama bu fonksiyona girmiyor hatayı çözemedim
Kitap* KitapListesi::kitapAra(int id) {
    Kitap* tmp = head;
    while (tmp) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}
//Kitap ödünç verme işleminde stok durumu için arttırma azaltma foksiyonları kullandım
void KitapListesi::kitapAdetAzalt(int id) {
    Kitap* kitap = kitapAra(id);
    if (kitap && kitap->adet > 0) kitap->adet--;
}

void KitapListesi::kitapAdetArttir(int id) {
    Kitap* kitap = kitapAra(id);
    if (kitap) kitap->adet++;
}

//kitaplar.txt dosyasından verileri çekme işlemini yaptım

void KitapListesi::kitaplariYukle(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya) {
        cerr << "Kitaplar.txt dosyasi acilamadi!" << endl;
        return;
    }

    int id, adet;
    string ad, yazar;

    while (dosya >> id) {
        dosya.ignore();
        getline(dosya, ad, '\t');
        getline(dosya, yazar, '\t');
        dosya >> adet;
        dosya.ignore();
        kitapEkle(id, ad, yazar, adet);
    }

    dosya.close();
}

//kitap ödünç alma işlemi

void KitapListesi::oduncAl(int ogrID, string ogrAd, int kitapID, OduncKuyrugu& kuyruk) {
    Kitap* kitap = kitapAra(kitapID);
    if (!kitap) return;
    if (kitap->adet > 0) {
        kitapAdetAzalt(kitapID);
        cout << ogrAd << " -> " << kitap->ad << " odunc aldi.\n";
    } else {
        kuyruk.enQueue(ogrID, ogrAd, kitapID, kitap->ad);
    }
}

//kitap iadesi

void KitapListesi::iadeEt(int ogrID, string ogrAd, int kitapID, IadeYigini& yigin) {
    Kitap* kitap = kitapAra(kitapID);
    if (!kitap) return;
    kitapAdetArttir(kitapID);
    yigin.push(ogrID, ogrAd, kitapID, kitap->ad);
}

void KitapListesi::kitapOduncVer(OduncKuyrugu& kuyruk) {
    while (!kuyruk.isEmpty()) {
        QueueNode* node = kuyruk.peek();
        Kitap* kitap = kitapAra(node->kitapID);
        if (kitap && kitap->adet > 0) {
            kitapAdetAzalt(kitap->id);
            cout << node->ogrenciAd << " (Kuyrukta) -> " << kitap->ad << " odunc aldi.\n";
            kuyruk.deQueue();
        } else break;
    }
}

void KitapListesi::kitapIadeAl(IadeYigini& yigin) {
    if (yigin.isEmpty()) {
        cout << "İade yigini bos.\n";
        return;
    }
    StackNode* top = yigin.peek(); //stack yapısı ile kuyrukta beklenen öğrenci işlemleri
    kitapAdetArttir(top->kitapID);
    cout << top->ogrenciAd << " -> " << top->kitapAd << "kitabini iade etti.\n";
    yigin.pop();
}
