#ifndef HEAP_H
#define HEAP_H

class heapQueue{
    public:
        heapQueue(int size);
        ~heapQueue();

        void insert(int war, float prio);
        element extractMax();
        element findMax();
        void modify(int war, float newPrio);
        int printSize();
       
        
    private:
        int size;
        int capacity;
        element **tab;
        void resize(int newCapacity);
        void heapifyUp(int index);
        void heapifyDown(int index);
};

struct element{
    int wartosc;
    int priorytet;
};

#endif