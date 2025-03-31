 #include "struktury.h"

 int dynamicArray::printRozmiar() const{//sprawdzenie rozmiaru
     return size;
 }

 int dynamicArray::printPojemnosc() const{ //sprawdzenie max pojemnosci
     return capacity;
 }

 dynamicArray::dynamicArray(){//wartosci poczatkowe
    size = 0;
    capacity = 100;
    tab = new int[capacity];
 }

 dynamicArray::~dynamicArray(){
    delete[] tab; //wyczyszczenie pamieci
}

void dynamicArray::addFront(int war){
    if(size == capacity)
        resize(capacity*2); //podwojenie pojemnosci w razie koniecznosci
    
    for(int i = size; i > 0; i--)
        tab[i] = tab[i-1];  //przesuniecie elementow w prawo

    tab[0] = war;           //dodanie elementu na poczatek
    size++;                 //zwiekszenie rozmiaru
}

void dynamicArray::addBack(int war){
    if(size == capacity)
        resize(capacity*2); //podwojenie pojemnosci w razie koniecznosci
    
    tab[size] = war;        //dodanie elementu z tylu
    size++;                 //zwiekszenie rozmiaru
}

void dynamicArray::addAt(int index, int war){
    if(index < 0 || index > size)
        return;             //jesli index jest poza zakresem nie robimy nic
    
    if(size == capacity)
        resize(capacity*2); //podwojenie pojemnosci w razie koniecznosci
    
    for(int i = size; i > index; i--)
        tab[i] = tab[i-1];  //przesuniecie elementow w prawo, zrobienie miejsca na wstawienie
    
    tab[index] = war;       //dodanie nowego elementu
    size++;                 //zwiekszenie rozmiaru
}

void dynamicArray::removeFront(){
    if(size == 0)
        return;             //jesli tablica pusta nie robimy nic
    
    for(int i = 0; i < size-1; i++)
        tab[i] = tab[i+1];  //przesuniecie elementow w lewo
    
    size--;                 //zmniejszenie rozmiaru
}

void dynamicArray::removeBack(){
    if(size == 0)
        return;             //jesli tablica pusta nie robimy nic
    
    size--;                 //zmniejszenie rozmiaru
}

void dynamicArray::removeAt(int index){
    if(index < 0 || index >= size)
        return;             //jesli index poza zakresem nie robimy nic

    for(int i = index; i < size-1; i++)
        tab[i] = tab[i+1];  //dosuniecie elementow
    
    size--;                 //zmniejszenie rozmiaru
}

bool dynamicArray::find(int war){
    for(int i = 0; i < size; i++)
        if(tab[i] == war)
            return true;    //jesli znaleziono element zwracamy true
    
    return false;           //jesli nie znaleziono zwracamy false
}

void dynamicArray::resize(int newCapacity){
    int* tmp = new int[newCapacity]; //nowa tablica
    for(int i = 0; i < size; i++)
        tmp[i] = tab[i]; //przepisanie elementow
    
    delete[] tab;   //usuniecie starej tablicy
    tab = tmp;      //przypisanie nowej tablicy
    capacity = newCapacity; //zmiana pojemnosci
}