#include "array.h"
#include <iostream>
using namespace std;

arrayQueue::arrayQueue(int pojemnosc){
    size = 0;
    capacity = pojemnosc;
    tab = new element*[capacity];
};

arrayQueue::~arrayQueue(){
    for (int i = 0; i < size; ++i)
        delete tab[i];             //usuniecie struktur
    delete[] tab;
};

void arrayQueue::insert(int war, float prio){
    if(size == capacity)
        resize(capacity*2);

    element* newElement = new element;
    newElement->wartosc = war;
    newElement->priorytet = prio;

    int i = size - 1;
    while(i >= 0 && tab[i]->priorytet < prio){
        tab[i + 1] = tab[i];        //dopoki priorytet jest mniejszy przesuwamy element  w prawo
        i--;
    }

    tab[i+1] = newElement;
    size++;
}

element arrayQueue::extractMax(){
    if(size == 0)
        throw runtime_error("pusta kolejka"); //obsluga wyjatku
    
    element* maxElement = tab[0];   //pierwszy element ma najwiekszy prioytet
    element wynik = *maxElement;    //zapisujemy wartosc elementu
    for(int i = 1; i < size; i++){
        tab[i-1] = tab[i];          //przesuwamy elementy w lewo
    }
    delete maxElement;              //zwalniamy pamiec
    return wynik;                   //zwracamy wartosc elementu
    size--;
}

element arrayQueue::findMax(){
    if(size == 0)
        throw runtime_error("pusta kolejka"); //obsluga wyjatku
    
    return *tab[0];                  //zwracamy pierwszy element
}

void arrayQueue::modify(int war,float prio){
    int index = -1; 
    for(int i = 0; i < size; i++)    //szukamy czy wylosowamy element istnieje, zapisujemy indeks
        if(tab[i]->wartosc == war){
            index = i;
            break;
        }
    
    if(index == -1 || tab[index]->priorytet == prio)
        return;    //jezeli nie znajdziemy elementu/priorytet sie nie zmienil to nic nie robimy

    float oldPrio = tab[index]->priorytet; //zapamietujemy stary priorytet
   
    if(prio > oldPrio){
        while(index < size -1 && tab[index +1]->priorytet < prio){  //dopoki prio wieksze niz poprzednie przesuwamy
            swap(tab[index], tab[index + 1]);                       //"przesuwamy" elementy w prawo
            index++;
        }
    }else if(prio < oldPrio){
        while(index > 0 && tab[index -1]->priorytet > prio){
            swap(tab[index], tab[index - 1]);                       //"przesuwamy" elementy w lewo
            index--;
        }
    }
}

int arrayQueue::printSize(){
   return size;
}

void arrayQueue::resize(int newCapacity){
    element** tmp = new element*[newCapacity];   //nowa tablica o podwojonej pojemnosci
    for(int i = 0; i < size; i++)
        tmp[i] = tab[i];                         //przepisanie elementow
    
    delete[] tab;                                //usuniecie starej tablicy
    tab = tmp;                                   //przypisanie nowej tablicy tmp do tab
    capacity = newCapacity;                      //zmiana pojemnosci
}