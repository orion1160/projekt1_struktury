#include <iostream>
#include "testy.h"
#include <iostream>

using namespace std;

int main(){
    testowanie t;
   
    int i,j,k;
    string warunek;
    int rozmiar[] = {0,5000, 8000, 10000, 16000, 20000, 40000, 60000, 80000, 100000, 200000, 400000, 600000, 800000, 1000000};
    
do{
    do{
        cout<<"Wybierz strukture: "<<endl;
        cout<<"[1]  tablica dynamiczna"<<endl;
        cout<<"[2]  lista wiazana jednokierunkowa"<<endl;
        cin>>i;
    }
    while(i<1 || i>2);

    do{
        cout<<"Wybierz operacje do zbadania: "<<endl;
        cout<<"[1]  dodanie na poczatek"<<endl;
        cout<<"[2]  dodanie na koniec"<<endl;
        cout<<"[3]  dodanie w losowym miejscu"<<endl;
        cout<<"[4]  usuniecie z przodu"<<endl;
        cout<<"[5]  usuniecie z tylu"<<endl;
        cout<<"[6]  usuniecie z losowego indeksu"<<endl;
        cout<<"[7]  znalezienie elementu"<<endl;
        cin>>j;

    }while(j<1 || j>7);

    do
    {
        cout<<"Wybierz rozmiar tablicy: "<<endl;
        cout<<"[1]  5000"<<endl;
        cout<<"[2]  8000"<<endl;
        cout<<"[3]  10000"<<endl;
        cout<<"[4]  16000"<<endl;
        cout<<"[5]  20000"<<endl;
        cout<<"[6]  40000"<<endl;
        cout<<"[7]  60000"<<endl;
        cout<<"[8]  80000"<<endl;
        cout<<"[9]  100000"<<endl;
        cout<<"[10] 200000"<<endl;
        cout<<"[11] 400000"<<endl;
        cout<<"[12] 600000"<<endl;
        cout<<"[13] 800000"<<endl;
        cout<<"[14] 1000000"<<endl;
        cin>>k;
    }while(k<1 || k>14);
    cout<<"wyniki pomiaru dla: ";
    if(i==1)
        cout<<"tablicy dynamicznej, ";
    else
        cout<<"listy jednokierunkowej, ";
    cout<<"operacji: ";
    switch(j){
        case 1: 
            cout<<"dodaj na poczatek, ";
            break;
        case 2: 
            cout<<"dodaj na koniec, ";
            break;
        case 3: 
            cout<<"dodaj w losowym miejscu, ";
            break;
        case 4: 
            cout<<"usun z przodu, ";
            break;
        case 5: 
            cout<<"usun z tylu, ";
            break;
        case 6: 
            cout<<"usuniecie z losowego indeksu, ";
            break;
        case 7: 
            cout<<"znalezienie elementu, ";
            break;
    }
    cout<<" oraz rozmiaru: ";
    cout<<rozmiar[k]<<endl;

    t.test(i, j, rozmiar[k]);
    cout<<endl;
    cout<<"Czy chcesz kontynuowac? "<<endl;
    cout<<"[Y] tak"<<endl;
    cout<<"[N] nie"<<endl;
    cin>>warunek;

}while(warunek != "N" && warunek != "n");

    return 0;
}