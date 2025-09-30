#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

struct StackNode {
    int ogrenciID;
    string ogrenciAd;
    int kitapID;
    string kitapAd;
    StackNode* next;
};

class IadeYigini {
private:
    StackNode* top;

public:
    IadeYigini();
    ~IadeYigini();
    void push(int ogrID, string ogrAd, int kitapID, string kitapAd);
    void pop();
    void listele();
    bool isEmpty();
    StackNode* peek();
};

#endif
