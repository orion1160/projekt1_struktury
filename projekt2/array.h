#ifndef ARRAY_H
#define ARRAY_H

class arrayQueue{
    public:
        arrayQueue(int size);
        ~arrayQueue();

        void insert(int war, float prio);
        void extractMax();
        element findMax();
        void modify(int war, float newPrio);
        int printSize();
        
    private:
        int size;
        int capacity;
        element **tab;
        void resize(int newCapacity);
};

struct element{
    int wartosc;
    int priorytet;
};

#endif