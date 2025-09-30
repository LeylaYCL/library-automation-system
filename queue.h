#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct QueueNode {
    int ogrenciID;
    string ogrenciAd;
    int kitapID;
    string kitapAd;
    QueueNode* next;
};

class OduncKuyrugu {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    OduncKuyrugu();
    ~OduncKuyrugu();
    void enQueue(int ogrID, string ogrAd, int kitapID, string kitapAd);
    void deQueue();
    void listele();
    bool isEmpty();
    QueueNode* peek();
};

#endif
