#ifndef ARRAY_H
#define ARRAY_H

class arrayQueue{
    public:
        arrayQueue(int size);
        ~arrayQueue();

        void insert(int war, int prio);
        void extractMax();
        void findMax();
        void modify(int index, int newPrio);
        void printSize();
};


#endif

