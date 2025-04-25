#ifndef HEAP_H
#define HEAP_H

class heapQueue{
    public:
        heapQueue(int size);
        ~heapQueue();

        void insert(int war, int prio);
        void extractMax();
        void findMax();
        void modify(int index, int newPrio);
        void printSize();

};

#endif