#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "kitaplar.h"
#include "queue.h"
#include "stack.h"
#include "ogrenciler.h"
using namespace std;

void menu() {
    cout << "\nKutuphane Otomasyon Sistemi" << endl;
    cout << "1. Kitaplari Listele" << endl;
    cout << "2. Odunc Kuyrugunu Göster" << endl;
    cout << "3. İade Edilen Kitaplari Goster" << endl;
    cout << "4. Kitap Odunc Ver" << endl;
    cout << "5. Kitap İade Al" << endl;
    cout << "6. Cikis" << endl;
    cout << "Seciminiz: ";
}

int main() {
    SetConsoleOutputCP(65001);

//burda txt dosyalarından verileri aldık

    KitapListesi kitaplar;
    kitaplar.kitaplariYukle("Kitaplar.txt");

    OgrenciListesi ogrListesi;
    ogrListesi.ogrencileriYukle("Ogrenciler.txt");

    OduncKuyrugu kuyruk;
    IadeYigini yigin;

    int secim;  //menü oluşumu için caselere fonksiyonları çağırarak yapıldı
    do {
        menu();
        cin >> secim;
        cin.ignore();

        switch (secim) {
            case 1:
                kitaplar.kitaplariListele();
                break;

            case 2:
                kuyruk.listele();
                break;

            case 3:
                yigin.listele();
                break;

            case 4: {
                int ogrID, kitapID;
                cout << "ogrenci ID: ";
                cin >> ogrID;
                cin.ignore();
                Ogrenci* ogr = ogrListesi.ogrenciAra(ogrID);
                if (!ogr) {
                    cout << "HATA: Bu ID'ye sahip ogrenci bulunamadi!" << endl;
                    break;
                }
                cout << "Kitap ID: ";
                cin >> kitapID;
                kitaplar.oduncAl(ogr->id, ogr->ad, kitapID, kuyruk);
                break;
            }

            case 5: {
                int ogrID, kitapID;
                cout << "ogrenci ID: ";
                cin >> ogrID;
                cin.ignore();
                Ogrenci* ogr = ogrListesi.ogrenciAra(ogrID);
                if (!ogr) {
                    cout << "HATA: Bu ID'ye sahip ogrenci bulunamadi!" << endl;
                    break;
                }
                cout << "Kitap ID: ";
                cin >> kitapID;
                kitaplar.iadeEt(ogr->id, ogr->ad, kitapID, yigin);
                break;
            }

            case 6:
                cout << "Cikis yapiliyor..." << endl;
                break;

            default:
                cout << "Gecersiz secim!" << endl;
        }

    } while (secim != 6);

    return 0;
}