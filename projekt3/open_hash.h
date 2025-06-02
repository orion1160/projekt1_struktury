#ifndef OPEN_HASH_H
#define OPEN_HASH_H
#include <vector>

struct Pair_open {
    int key;
    int value;
};

class OpenHash{
    public:
        OpenHash(int size);
        ~OpenHash();
        void insert(int key, int value);
        void remove(int key);
        void resize();
        int get_prime_size(float min_size);


    private:
        static const std::vector<int> primes;
        int capacity;
        Pair_open* table; //tablica 
        int hash(int key);
        float load_factor_count = 0; //obciazenie - licznik

};

#endif