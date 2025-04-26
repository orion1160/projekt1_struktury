#include "heap.h"
#include <iostream>

using namespace std;

heapQueue::heapQueue(int pojemnosc){
    size = 0;
    capacity = pojemnosc;
    tab = new element*[capacity];
};

heapQueue::~heapQueue(){
    for (int i = 0; i < size; ++i)
        delete tab[i];             //usuniecie struktur
    delete[] tab;
};

void heapQueue::heapifyUp(int index){
    int rodzic = (index-1)/2; //wyznaczenie rodzica

    if(index > 0 && tab[index]->priorytet > tab[rodzic]->priorytet){ //jezeli index jest wiekszy od 0 i priorytet jest mniejszy
        swap(tab[index], tab[rodzic]); //zamiana miejscami
        heapifyUp(rodzic);             //rekurencyjne przywracanie wlasnosci kopca
    }
}

void heapQueue::heapifyDown(int index){
    int indexMax = index;                //ustawienie inedksu rodzica na maksymalny
    int leweDziecko = 2*index+1;         //wyznaczenie lewego dziecka
    int praweDziecko = 2*index+2;        //wyznaczenie prawego dziecka

    if(leweDziecko < size && tab[leweDziecko]->priorytet > tab[indexMax]->priorytet)
        indexMax = leweDziecko;          //jezeli lewe dziecko jest w tablicy i ma wiekszy priorytet, zamieniamy
    if (praweDziecko < size && tab[praweDziecko]->priorytet > tab[indexMax]->priorytet)
        indexMax = praweDziecko;         //jezeli prawe dziecko jest w tablicy i ma wiekszy priorytet, zamieniamy
   
    if(indexMax != index){               //jezeli index sie zmienil
        swap(tab[index], tab[indexMax]); //zamiana miejscami
        heapifyDown(indexMax);           //rekurencyjne przywracanie wlasnosci kopca
    }
}

void heapQueue::insert(int war, float prio){
    if(size == capacity)
        resize(capacity*2);

    element* newElement = new element;
    newElement->wartosc = war;
    newElement->priorytet = prio;

    tab[size] = newElement;         //dodanie nowego elementu na koniec tablicy
    size++;       
    heapifyUp(size-1);                //przywrocenie wlasnoci kopca po dodaniu elementu                 
}

element heapQueue::extractMax(){
    if(size == 0)
        throw runtime_error("pusta kolejka"); //obsluga wyjatku

    element* maxElement = tab[0];   //zapamietujemy maksymalny element/korzen
    element wynik = *maxElement;    //zapisujemy wartosc elementu

    delete tab[0];
    tab[0] = tab[size-1];          //zamiana korzenia z ostatnim elementem
    size--;
    heapifyDown(0);                //przywracanie wlasnosci kopca

    return wynik;                 //zwracamy wartosc elementu
}

element heapQueue::findMax(){
    if(size == 0)
        throw runtime_error("pusta kolejka"); //obsluga wyjatku

    return *tab[0];                  //zwracamy pierwszy element
}

void heapQueue::modify(int war, float prio){
    int index = -1; 
    for(int i = 0; i < size; i++)    //szukamy czy wylosowamy element istnieje, zapisujemy indeks
        if(tab[i]->wartosc == war){
            index = i;
            break;
        }
    
    if(index == -1 || tab[index]->priorytet == prio)
        return;    //jezeli nie znajdziemy elementu/priorytet sie nie zmienil to nic nie robimy

    float oldPrio = tab[index]->priorytet; //zapamietujemy stary priorytet
    tab[index]->priorytet = prio;     //zmieniamy priorytet
    if(prio > oldPrio){                   //jezeli nowy priorytet jest wiekszy
        heapifyUp(index);                 //przywracanie wlasnosci kopca
    }
    else{                                 //jezeli nowy priorytet jest mniejszy
        heapifyDown(index);               //przywracanie wlasnosci kopca
    }
}

int heapQueue::printSize(){
    return size;                        //zwracamy rozmiar
}

void heapQueue::resize(int newCapacity){
    element** tmp = new element*[newCapacity];   //nowa tablica o podwojonej pojemnosci
    for(int i = 0; i < size; i++)
        tmp[i] = tab[i];                         //przepisanie elementow
    
    delete[] tab;                                //usuniecie starej tablicy
    tab = tmp;                                   //przypisanie nowej tablicy tmp do tab
    capacity = newCapacity;                      //zmiana pojemnosci
}