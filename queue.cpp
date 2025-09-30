#include "queue.h"
#include <iostream>

//başlangiçta boş yapı için
OduncKuyrugu::OduncKuyrugu() {
    front = rear = nullptr;
}

//kuyruğu yıkmak ve belleği temizlemek için
OduncKuyrugu::~OduncKuyrugu() {
    while (!isEmpty())
        deQueue();
}

//kuyruğa yeni bir öğrenci veya kitap ödünç talebi için
void OduncKuyrugu::enQueue(int ogrID, string ogrAd, int kitapID, string kitapAd) {
    QueueNode* yeni = new QueueNode{ ogrID, ogrAd, kitapID, kitapAd, nullptr };
    if (rear == nullptr) {
        front = rear = yeni;
    } else {
        rear->next = yeni;
        rear = yeni;
    }
}

//kuyrukta yeni olan bir öğrenciyi çıkarmak için
void OduncKuyrugu::deQueue() {
    if (isEmpty()) return;

    QueueNode* tmp = front;
    front = front->next;
    delete tmp;

    if (front == nullptr)
        rear = nullptr;
}
//kuyrukta tüm seçimleri listelemek için
void OduncKuyrugu::listele() {
    if (isEmpty()) {
        cout << "odunc alma kuyrugu bos.\n";
        return;
    }

    QueueNode* tmp = front;
    while (tmp) {
        cout << tmp->ogrenciID << " | " << tmp->ogrenciAd
             << " | Kitap ID: " << tmp->kitapID
             << " | " << tmp->kitapAd << endl;
        tmp = tmp->next;
    }
}

//kuyruğun boş mu dolu mu olduğunu kontrol etmek için
bool OduncKuyrugu::isEmpty() {
    return front == nullptr;
}

QueueNode* OduncKuyrugu::peek() {
    return front;
}
