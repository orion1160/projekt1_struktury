#include "open_hash.h"
#include <vector>

OpenHash::OpenHash(int size){
    table = new Pair_open[size]; 
    capacity = size;
    load_factor_count = 0; //obciazenie
    for(int i = 0; i < capacity; i++){
        table[i].key = -1; //klucze na -1, pusta komorka
        table[i].value = 0;
    }
}

OpenHash::~OpenHash(){
    delete[] table; //zwalniamy pamiec
}

int OpenHash::hash(int key){
    return key % capacity; 
}

void OpenHash::insert(int key, int value){
    int index = hash(key);
    while(table[index].key != -1 && table[index].key != -2 && table[index].key != key) {
        index = (index + 1) % capacity; //szukamy kolejnej wolnej komorki
    }

    if(table[index].key == key) { //jezeli klucz już istnieje, nadpisujemy
        table[index].value = value;
        return;
    }

    table[index].key = key; //wstawiamy klucz
    table[index].value = value; //wstawiamy wartosc

    load_factor_count += 1;
    if(load_factor_count / float(capacity) > 0.75){ //sprawdzamy obciazenie
        resize();
    }
}

void OpenHash::resize(){
    int new_size = get_prime_size(capacity * 1.9); //podwojenie rozmiaru
    load_factor_count = 0; //resetujemy obciazenie
    Pair_open* new_table = new Pair_open[new_size];
    
    for(int i = 0; i < new_size; i++){
        new_table[i].key = -1; //inicjalizacja nowej tablicy
        new_table[i].value = 0;
    }

    for(int i = 0; i < capacity; i++){
        if(table[i].key >= 0){   //przenosimy tylko zajete komorki
            int index = table[i].key % new_size;        //rehashujemy
            while(new_table[index].key != -1) {
                index = (index + 1) % new_size;
            }
            new_table[index] = table[i]; 
            load_factor_count += 1; //aktualizujemy obciazenie
        }
    }

    delete[] table; 
    table = new_table; 
    capacity = new_size; 
}

//przygotowane rozmiary jako liczbhy pierwsze dla ewentualnego powiekszania rozmiaru
const std::vector<int> OpenHash::primes = {
    6151,      12289,     24593,
    49157,     98317,     196613,    393241,    786433,
    1572869,   3145739,   6291469,   12582917,  25165843,
    50331653,  100663319, 201326611, 402653189, 805306457, 
    1610612741
};

int OpenHash::get_prime_size(float min_size) {
    for(int prime : primes){  
        if(prime >= min_size) //niejawne konwersja i sprawdzenie, szukamy następnej ok. 2x większej
            return prime;
    }
    return primes.back();
}

void OpenHash::remove(int key){
    int index = hash(key);
    while(table[index].key != -1) {
        if(table[index].key == key) {
            table[index].key = -2; //oznaczamy jako usuniete | -2 zeby przy innych sprawdzaniach nie przerywac ciagu szukania
            table[index].value = 0; //wartosc zerujemy
            load_factor_count -= 1; //zmniejszamy obciazenie
            return;
        }
        index = (index + 1) % capacity; //szukamy kolejnej komorki
    }
}