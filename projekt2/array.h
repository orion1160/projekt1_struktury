#ifndef ARRAY_H
#define ARRAY_H

struct elementArray{
    int wartosc;
    int priorytet;
};

class arrayQueue{
    public:
        arrayQueue(int size);
        ~arrayQueue();

        void insert(int war, float prio);
        elementArray extractMax();
        elementArray findMax();
        void modify(int war, float newPrio);
        int printSize();
        
    private:
        int size;
        int capacity;
        elementArray **tab;
        void resize(int newCapacity);
};



#endif