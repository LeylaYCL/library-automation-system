#include "ogrenciler.h"
#include <fstream>
#include <iostream>

OgrenciListesi::OgrenciListesi() {
    head = nullptr;
}

OgrenciListesi::~OgrenciListesi() {
    while (head) {
        Ogrenci* tmp = head;
        head = head->next;
        delete tmp;
    }
}

//bu fonksiyon listedeki öğrenci bilgileri için 

void OgrenciListesi::ogrenciEkle(int id, string ad) {
    Ogrenci* yeni = new Ogrenci{ id, ad, nullptr };
    if (!head) {
        head = yeni;
    } else {
        Ogrenci* tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = yeni;
    }
}

Ogrenci* OgrenciListesi::ogrenciAra(int id) {
    Ogrenci* tmp = head;
    while (tmp) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

//aşağıda kullanılan cerr yapısı hata mesaı için cout da önbelleğe kaydeder ama bu yapıda anında hata mesajı bastırılır
void OgrenciListesi::ogrencileriYukle(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya) {
        cerr << "Ogrenciler.txt dosyasi acilamadi!" << endl;
        return;
    }

    int id, kitapID, islem;
    string ad;

    while (dosya >> id >> ws && getline(dosya, ad, '\t') && dosya >> kitapID >> islem) {
        ogrenciEkle(id, ad);
        dosya.ignore();
    }

    dosya.close();
}