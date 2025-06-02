#include <iostream>
#include "testy.h"

using namespace std;

int main(){

    float zapelnienie[] = {0.3,0.5,0.7};
    int rozmiar[] = {
        6151,      12289,     24593,
        49157,     98317,     196613,    393241,    786433,
        1572869,   3145739,   6291469,   12582917,  25165843,
        50331653,  100663319, 201326611, 402653189, 805306457, 
        1610612741
    };
    int i,j,k,l,w;
    testy t;

    do{
        do{
            cout<<"Wybierz implementacje tablicy mieszajacej: "<<endl;
            cout<<"[1] adresowanie otwarte"<<endl;
            cout<<"[2] lancuchowanie"<<endl;
            cin>>i;
        }while(i < 1 || i > 2);

        do{
            cout<<"Wybierz operacje: "<<endl;
            cout<<"[1] insert"<<endl;
            cout<<"[2] remove"<<endl;
            cin>>j;
        }while(j < 1 || j > 2);

        do{
            cout<<"Wybierz rozmiar tablicy: "<<endl;
            cout<<"[1] 6151"<<endl;
            cout<<"[2] 12289"<<endl;
            cout<<"[3] 24593"<<endl;
            cout<<"[4] 49157"<<endl;
            cout<<"[5] 98317"<<endl;
            cout<<"[6] 196613"<<endl;
            cout<<"[7] 393241"<<endl;
            cout<<"[8] 786433"<<endl;
            cout<<"[9] 1572869"<<endl;
            cout<<"[10] 3145739"<<endl;
            cout<<"[11] 6291469"<<endl;
            cout<<"[12] 12582917"<<endl;
            cout<<"[13] 25165843"<<endl;
            cout<<"[14] 50331653"<<endl;
            cout<<"[15] 100663319"<<endl;
            cout<<"[16] 201326611"<<endl;
            cout<<"[17] 402653189"<<endl;
            cout<<"[18] 805306457"<<endl;
            cout<<"[19] 1610612741"<<endl;
            cin>>k;
        }while(k < 1 || k > 19);

        do{
            cout<<"Wybierz wypelnienie tablicy: "<<endl;
            cout<<"[1] 30%"<<endl;
            cout<<"[2] 50%"<<endl;
            cout<<"[3] 70%"<<endl;
            cin>>l;
        }while(l < 1 || l > 3);

        switch(i){
            case 1:
                cout<<"adresowanie otwarte"<<endl;
                break;
            case 2:
                cout<<"lancuchowanie"<<endl;
                break;
        }

        t.test(i, j, rozmiar[k-1], zapelnienie[l-1]); 
        cout<<endl;
        cout<<"Czy chcesz kontynuowac? "<<endl;
        cout<<"[1] tak"<<endl;
        cout<<"[ ] nie"<<endl;
        cin>>w;

    }while(w == 1);


    return 0;
}