#ifndef CHAIN_HASH_H
#define CHAIN_HASH_H

struct Pair{
    int key;
    int value;
};

struct Node{
    Pair data;
    Node* next;
};


class ChainHash{
    public:
        ChainHash(int size);
        ~ChainHash();
        void insert(int key, int value);
        void remove(int key);

    private:
        Node** table;
        int capacity;

        int hash(int key);
};



#endif