#include "stack.h"
#include <iostream>

IadeYigini::IadeYigini() {
    top = nullptr;
}

IadeYigini::~IadeYigini() {
    while (!isEmpty())
        pop();
}

//yeni bir iade kaydı yığına eklenir
void IadeYigini::push(int ogrID, string ogrAd, int kitapID, string kitapAd) {
    StackNode* yeni = new StackNode{ ogrID, ogrAd, kitapID, kitapAd, top };
    top = yeni;
}
//yığının en üstteki elemanı çıkarmak için
void IadeYigini::pop() {
    if (isEmpty()) return;

    StackNode* tmp = top;
    top = top->next;  //bir alttaki elemanı top yapmak için
    delete tmp;
}

//yığındaki tüm iade kayıtlarını yazdırmak için
void IadeYigini::listele() {
    if (isEmpty()) {
        cout << "İade edilen kitaplar yigini bos.\n";
        return;
    }

    StackNode* tmp = top;
    while (tmp) {
        cout << tmp->ogrenciID << " | " << tmp->ogrenciAd
             << " | Kitap ID: " << tmp->kitapID
             << " | " << tmp->kitapAd << endl;
        tmp = tmp->next;
    }
}

bool IadeYigini::isEmpty() {
    return top == nullptr;
}

StackNode* IadeYigini::peek() {
    return top;
}
