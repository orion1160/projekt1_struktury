#ifndef STRUKTURY_H
#define STRUKTURY_H

class dynamicArray{
    public:
        dynamicArray(int pojemnosc);
        ~dynamicArray();
            
        void addFront(int war);
        void addBack(int war);

        void removeFront();
        void removeBack();

        void addAt(int index, int war);
        void removeAt(int index);

        bool find(int war);
        int printRozmiar() const;
        int printPojemnosc() const;

    private:
        int* tab;     
        int size;     // obecny rozmiar [1,2,3,-,-] ->3
        int capacity; // calkowita pojemnosc [1,2,3,-,-] ->5
        void resize(int newCapacity); //zmiana pojemnosci tablicy
};

struct node{
    int data; //wartosc przechowywana
    node* link; //wskaznik do nastepnego wezla
};

class linkedList{
    public:
        linkedList();
        ~linkedList();
        
        void addHead(int war);
        void addTail(int war);

        void removeHead();
        void removeTail();

        void addAtIndex(int index, int war);
        void removeAtIndex(int index);

        bool findN(int war);

    private:
        node* head;
        node* tail;
        int size;

};

#endif