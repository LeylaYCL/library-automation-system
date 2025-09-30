#ifndef KITAPLAR_H
#define KITAPLAR_H

#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Kitap {
    int id;
    string ad;
    string yazar;
    int adet;
    Kitap* next;
};

class KitapListesi {  //bu sınıfla yukarıdaki struct verilerin adreslerini çektik
private:
    Kitap* head;

public:
    KitapListesi();
    void kitapEkle(int id, string ad, string yazar, int adet);
    void kitaplariListele();
    Kitap* kitapAra(int id);
    void kitapAdetArttir(int id);
    void kitapAdetAzalt(int id);
    void kitaplariYukle(const string& dosyaAdi);
    void oduncAl(int ogrID, string ogrAd, int kitapID, OduncKuyrugu& kuyruk);
    void iadeEt(int ogrID, string ogrAd, int kitapID, IadeYigini& yigin);
    void kitapOduncVer(OduncKuyrugu& kuyruk);
    void kitapIadeAl(IadeYigini& yigin);
};

#endif
