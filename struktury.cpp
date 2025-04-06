#include "struktury.h"
#pragma region tablica dynamiczna
 int dynamicArray::printRozmiar() const{    //sprawdzenie rozmiaru
     return size;
 }

 int dynamicArray::printPojemnosc() const{  //sprawdzenie max pojemnosci
     return capacity;
 }

 dynamicArray::dynamicArray(){  //wartosci poczatkowe
    size = 0;
    capacity = 10;
    tab = new int[capacity];
 }

 dynamicArray::~dynamicArray(){
    delete[] tab;               //wyczyszczenie pamieci
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
        tab[i] = tab[i+1];  //przesuniecie elementow w lewo, nadpisanie pierwszego elementu
    
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
    int* tmp = new int[newCapacity];    //nowa tablica o podwojonej pojemnosci
    for(int i = 0; i < size; i++)
        tmp[i] = tab[i];                //przepisanie elementow
    
    delete[] tab;                       //usuniecie starej tablicy
    tab = tmp;                          //przypisanie nowej tablicy do tab
    capacity = newCapacity;             //zmiana pojemnosci
}
#pragma endregion

#pragma region lista jednokierunkowa
linkedList::linkedList(){  //wartosci poczatkowe
    head = nullptr;
    tail = nullptr;
    size = 0;
}

linkedList::~linkedList(){
    while(head != nullptr){ //czyszczenie pamieci
        node* tmp = head;  //przypisanie wskaznika do head
        head = head->link; //przypisanie head do nastepnego wezla
        delete tmp;        //usuniecie starego/poprzediego wezla
    }
}

void linkedList::addHead(int war){
    node* newNode = new node; //utworzenie nowego wezla
    newNode->data = war;      //przypisanie wartosci
    newNode->link = head;     //przypisanie wskaznika do nastepnego wezla
    head = newNode;           //przypisanie nowego wezla jako head

    if(tail == nullptr)       //jesli lista byla pusta
        tail = newNode;       //przypisanie nowego wezla jako tail
    size++;                   //zwiekszenie rozmiaru
}

void linkedList::addTail(int war){
    node* newNode = new node; //utworzenie nowego wezla
    newNode->data = war;      //przypisanie wartosci
    newNode->link = nullptr;  //ustawienie ostatniego wskaznika na nullptr
    
    if(tail != nullptr)       //jesli lista nie jest pusta
        tail->link = newNode; //przypisanie nowego wezla jako nastepnego
    
    tail = newNode;           //przypisanie nowego wezla jako tail
    if(head == nullptr)       //jesli lista byla pusta
        head = newNode;       //przypisanie nowego wezla jako head
    
    size++;                   //zwiekszenie rozmiaru
}

void linkedList::removeHead(){
    if(head == nullptr)      //jesli lista pusta nie robimy nic
        return;
    
    node* tmp = head;        //przypisanie wskaznika do head
    head = head->link;       //przypisanie head do nastepnego wezla
    delete tmp;              //usuniecie wezla
    size--;                  //zmniejszenie rozmiaru

    if(head == nullptr)      //jesli po usunieciu lista jest pusta
        tail = nullptr;      //ustawienie tail na nullptr
}

void linkedList::removeTail(){
    if(tail == nullptr)     //jesli lista pusta nie robimy nic
        return;
    
    if(head == tail){       //jesli lista ma tylko jeden element
        delete head;        //usuniecie wezla
        head = nullptr;     //ustawienie head na nullptr
        tail = nullptr;     //ustawienie tail na nullptr
        size--;             //zmniejszenie rozmiaru
        return;
    }
    
    node* tmp = head;        //przypisanie wskaznika do head
    while(tmp->link != tail) //przeszukiwanie listy do ostatniego wezla
        tmp = tmp->link;
    
    delete tail;           //usuniecie wezla
    tail = tmp;            //przypisanie tail do przedostatniego wezla
    tail->link = nullptr;  //ustawienie ostatniego wskaznika na nullptr
    size--;                //zmniejszenie rozmiaru
}

void linkedList::addAtIndex(int index, int war){
    if(index < 0 || index > size) //jesli index poza zakresem nie robimy nic
        return;
    
    if(index == 0){               //jesli dodajemy na poczatek
        addHead(war);
        return;
    }
    
    if(index == size){            //jesli dodajemy na koniec
        addTail(war);
        return;
    }
    
    node* newNode = new node;     //utworzenie nowego wezla
    newNode->data = war;          //przypisanie wartosci
    newNode->link = nullptr;      //ustawienie ostatniego wskaznika na nullptr
    
    node* tmp = head;             //przypisanie wskaznika do head
    for(int i = 0; i < index-1; i++)
        tmp = tmp->link;          //przeszukiwanie listy do wezla przed dodawanym
    
    newNode->link = tmp->link;   //przypisanie wskaznika do nastepnego wezla
    tmp->link = newNode;         //przypisanie nowego wezla jako nastepnego
    size++;                      //zwiekszenie rozmiaru
}

void linkedList::removeAtIndex(int index){
    if(index < 0 || index >= size) //jesli index poza zakresem nie robimy nic
        return;
    
    if(index == 0){               //jesli usuwamy z przodu
        removeHead();
        return;
    }
    
    if(index == size-1){          //jesli usuwamy z konca
        removeTail();
        return;
    }
    
    node* tmp = head;             //przypisanie wskaznika do head
    for(int i = 0; i < index-1; i++)
        tmp = tmp->link;          //przeszukiwanie listy do wezla przed usuwanym
    
    node* oldNode = tmp->link;   //przypisanie wskaznika do wezla do usuniecia
    tmp->link = oldNode->link;   //przypisanie nastepnego wezla do wezla przed usuwanym
    delete oldNode;              //usuniecie wezla
    size--;                       //zmniejszenie rozmiaru
}

bool linkedList::findN(int war){
    node* tmp = head;             //przypisanie wskaznika do head
    while(tmp != nullptr){        //szukamy do konca listy
        if(tmp->data == war)      //jesli znaleziono element
            return true;          //zwracamy true i konczymy szukanie
        tmp = tmp->link;          //w innym przypadku przechodzimy do nastepnego wezla
    }
    return false;                //jesli nie znaleziono zwracamy false
}
#pragma endregion
