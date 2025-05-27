#include "chain_hash.h"
#include <vector>

ChainHash::ChainHash(int size){
    capacity = size;
    table = new Node*[capacity];   
    for(int i = 0; i < capacity; i++){
        table[i] = nullptr;
    }
}

ChainHash::~ChainHash(){
    for(int i = 0; i < capacity; i++){
        Node* head = table[i];
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    delete[] table;
}

int ChainHash::hash(int key){
    return key % capacity;
}

void ChainHash::insert(int key, int value){
    int index = hash(key);
    Node* newNode = new Node();
    newNode->data.key = key;
    newNode->data.value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

void ChainHash::remove(int key){
    int index = hash(key);
    Node* head = table[index];
    Node* prev = nullptr;

    while(head != nullptr && head->data.key != key){ //szukaym poprzednika
        prev = head;
        head = head->next;
    }

    if(head == nullptr) //zwrot jeżeli nie ma takiego klucza
        return; 

    if(prev == nullptr){
        table[index] = head->next; //poczatek listy
    }else{
        prev->next = head->next; //z srodka lub konca
    }
    
    delete head;
}

