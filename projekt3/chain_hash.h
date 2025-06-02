#ifndef CHAIN_HASH_H
#define CHAIN_HASH_H

struct Pair_chain{
    int key;
    int value;
};

struct Node{
    Pair_chain data;
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