#ifndef OGRENCILER_H
#define OGRENCILER_H //txt dosya tanımlama

#include <string>
using namespace std;

struct Ogrenci {
    int id;
    string ad;
    Ogrenci* next;
};

class OgrenciListesi {
private:
    Ogrenci* head;

public:
    OgrenciListesi();
    ~OgrenciListesi();
    void ogrenciEkle(int id, string ad);
    Ogrenci* ogrenciAra(int id);
    void ogrencileriYukle(const string& dosyaAdi);
};

#endif//ifndef yapısını kapatmak için
