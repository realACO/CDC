#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    list<int> l;
    int size=0;
    int ms;
    MyCircularQueue(int k) {
        ms=k;
    }
    
    bool enQueue(int value) {
        if(size<ms){
            l.push_back(value);
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size!=0){
            l.pop_front();
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(size!=0)return l.front();
        return -1;
    }
    
    int Rear() {
        if(size!=0)return l.back();
        return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==ms;
    }
};
