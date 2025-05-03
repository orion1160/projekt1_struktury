#include <iostream>
#include "testowanie.h"
#include <string>

using namespace std;

int main(){
    string warunek;
    int rozmiar[] = {0,5000, 8000, 10000, 16000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    testowanie t;
    int i,j,k;

    do{
        do{
            cout<<"Wybierz strukture: "<<endl;
            cout<<"[1]  kolejka priorytetowa na tablicy dynamicznej"<<endl;
            cout<<"[2]  kolejka priorytetowa na kopcu"<<endl;
            cin>>i;
        }
        while(i<1 || i>2);
    
        do{
            cout<<"Wybierz operacje do zbadania: "<<endl;
            cout<<"[1]  insert(e,p)"<<endl;
            cout<<"[2]  extract-max()"<<endl;
            cout<<"[3]  find-max()"<<endl;
            cout<<"[4]  modify-key()"<<endl;
            cout<<"[5]  return-size()"<<endl;
            cin>>j;
    
        }while(j<1 || j>5);
    
        do
        {
            cout<<"Wybierz rozmiar tablicy: "<<endl;
            cout<<"[1]  5000"<<endl;
            cout<<"[2]  8000"<<endl;
            cout<<"[3]  10000"<<endl;
            cout<<"[4]  16000"<<endl;
            cout<<"[5]  20000"<<endl;
            cout<<"[6]  30000"<<endl;
            cout<<"[7]  40000"<<endl;
            cout<<"[8]  50000"<<endl;
            cout<<"[9]  60000"<<endl;
            cout<<"[10] 70000"<<endl;
            cout<<"[11] 80000"<<endl;
            cout<<"[12] 90000"<<endl;
            cout<<"[13] 100000"<<endl;
            cin>>k;
        }while(k<1 || k>13);
        cout<<"wyniki pomiaru dla: ";
        if(i==1)
            cout<<"Kolejki priorytetowej (tablica dynamiczna), ";
        else
            cout<<"Kolejki priorytetowej (kopiec), ";
        cout<<"operacji: ";
        switch(j){
            case 1: 
                cout<<"insert, ";
                break;
            case 2: 
                cout<<"extract-max, ";
                break;
            case 3: 
                cout<<"find-max, ";
                break;
            case 4: 
                cout<<"modify-key, ";
                break;
            case 5: 
                cout<<"return-size, ";
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