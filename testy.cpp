 #include "testy.h"
 #include <iostream>
 #include "struktury.h"
 #include <cstdlib>
 #include <chrono>

 using namespace std;
 using namespace chrono;

 void testowanie::test(int struktura, int operacja, int rozmiar){
    if(struktura == 1){   //dynamiczna tablica
       
        //czasy
        double pomiarDodawaniePrzod  = 0;
        double pomiarUsuwaniePrzod   = 0;
        double pomiarUsuwanieKoniec  = 0;
        double pomiarDodawanieKoniec = 0;
        double pomiarDodawanieRand   = 0;
        double pomiarUsuwanieRand    = 0;
        double pomiarZnalezienie     = 0;

      
        for (int testIndex = 0; testIndex < 100; testIndex++){
            dynamicArray tab; //utworzenie

            srand(testIndex+200); //losowanie wartosci ze stalym ziarnem

            for(int i = 0; i < rozmiar;i++ )
                tab.addBack(rand()); //dodanie losowych wartosci do tablicy
    
            switch(operacja){
                case 1: //dodanie na poczatek
                {
                    auto start = high_resolution_clock::now();
                    tab.addFront(rand());
                    auto end = high_resolution_clock::now();
                    pomiarDodawaniePrzod += duration<double,nano>(end - start).count(); 
                }
                    break;
                case 2: //dodanie na koniec
                {
                    auto start = high_resolution_clock::now();
                    tab.addBack(rand());
                    auto end = high_resolution_clock::now();
                    pomiarDodawanieKoniec += duration<double,nano>(end - start).count();
                }
                    break;
                case 3: //dodanie w losowym miejscu
                {
                    auto start = high_resolution_clock::now();
                    tab.addAt(rand()%rozmiar, rand());
                    auto end = high_resolution_clock::now();
                    pomiarDodawanieRand += duration<double,nano>(end - start).count();
                }
                    break;
                case 4: //usuniecie z przodu
                {
                    auto start = high_resolution_clock::now();
                    tab.removeFront();
                    auto end = high_resolution_clock::now();
                    pomiarUsuwaniePrzod += duration<double,nano>(end - start).count();
                }
                    break;
                case 5: //usuniecie z tylu
                {
                    auto start = high_resolution_clock::now();
                    tab.removeBack();
                    auto end = high_resolution_clock::now();
                    pomiarUsuwanieKoniec += duration<double,nano>(end - start).count();
                }
                    break;
                case 6: //usuniecie z losowego indeksiu
                {
                    auto start = high_resolution_clock::now();
                    tab.removeAt(rand()%rozmiar);
                    auto end = high_resolution_clock::now();
                    pomiarUsuwanieRand += duration<double,nano>(end - start).count();
                }
                    break;
                case 7: //szukanie elementu
                {
                    auto start = high_resolution_clock::now();
                    tab.find(rand());
                    auto end = high_resolution_clock::now();
                    pomiarZnalezienie += duration<double,nano>(end - start).count();
                }
                    break;
                default:
                    cout<<"Nieznana operacja"<<endl;
                    break;
            }
    }  
    switch(operacja){
        case 1: 
            cout<<"Dodawanie na poczatek: "<<pomiarDodawaniePrzod/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 2: 
            cout<<"Dodawanie na koniec: "<<pomiarDodawanieKoniec/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 3: 
            cout<<"Dodawanie w losowym miejscu: "<<pomiarDodawanieRand/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 4: 
            cout<<"Usuwanie z przodu: "<<pomiarUsuwaniePrzod/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 5: 
            cout<<"Usuwanie z tylu: "<<pomiarUsuwanieKoniec/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 6: 
            cout<<"Usuwanie z losowego indeksu: "<<pomiarUsuwanieRand/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 7: 
            cout<<"Znalezienie elementu: "<<pomiarZnalezienie/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
    }
  
    }
    else if(struktura == 2){//lista jednokierunkowa

        //czasy
        double pomiarDodawaniePrzod  = 0;
        double pomiarUsuwaniePrzod   = 0;
        double pomiarUsuwanieKoniec  = 0;
        double pomiarDodawanieKoniec = 0;
        double pomiarDodawanieRand   = 0;
        double pomiarUsuwanieRand    = 0;
        double pomiarZnalezienie     = 0;

        for (int testIndex = 0; testIndex < 100; testIndex++){
            linkedList lista; //utworzenie

            srand(testIndex+200); //losowanie wartosci ze stalym ziarnem

            for(int i = 0; i < rozmiar;i++ )
                lista.addTail(rand()); //dodanie losowych wartosci do tablicy
    

        switch(operacja){
            case 1: //dodanie na poczatek
            {
                auto start = high_resolution_clock::now();
                lista.addHead(rand());
                auto end = high_resolution_clock::now();
                pomiarDodawaniePrzod += duration<double,nano>(end - start).count(); 
            }
                break;
            case 2: //dodanie na koniec
            {
                auto start = high_resolution_clock::now();
                lista.addTail(rand());
                auto end = high_resolution_clock::now();
                pomiarDodawanieKoniec += duration<double,nano>(end - start).count();
            }
                break;
            case 3: //dodanie wlosowym miejscu
            {
                auto start = high_resolution_clock::now();
                lista.addAtIndex(rand()%rozmiar, rand());
                auto end = high_resolution_clock::now();
                pomiarDodawanieRand += duration<double,nano>(end - start).count();
            }
                break;
            case 4: //usuniecie z przodu
            {
                auto start = high_resolution_clock::now();
                lista.removeHead();
                auto end = high_resolution_clock::now();
                pomiarUsuwaniePrzod += duration<double,nano>(end - start).count();
            }
                break;
            case 5: //usuniecie z tylu
            {
                auto start = high_resolution_clock::now();
                lista.removeTail();
                auto end = high_resolution_clock::now();
                pomiarUsuwanieKoniec += duration<double,nano>(end - start).count();
            }
                break;
            case 6: //usuniecie z lsowego indeksu
            {
                auto start = high_resolution_clock::now();
                lista.removeAtIndex(rand()%rozmiar);
                auto end = high_resolution_clock::now();
                pomiarUsuwanieRand += duration<double,nano>(end - start).count();
            }
                break;
            case 7: //znalezienie elementu
            {
                auto start = high_resolution_clock::now();
                lista.findN(rand());
                auto end = high_resolution_clock::now();
                pomiarZnalezienie += duration<double,nano>(end - start).count();
            }
                break;
        }
    }
    switch(operacja){
        case 1: 
            cout<<"Dodawanie na poczatek: "<<pomiarDodawaniePrzod/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 2: 
            cout<<"Dodawanie na koniec: "<<pomiarDodawanieKoniec/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 3: 
            cout<<"Dodawanie w losowym miejscu: "<<pomiarDodawanieRand/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 4: 
            cout<<"Usuwanie z przodu: "<<pomiarUsuwaniePrzod/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 5: 
            cout<<"Usuwanie z tylu: "<<pomiarUsuwanieKoniec/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 6: 
            cout<<"Usuwanie z losowego indeksu: "<<pomiarUsuwanieRand/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
        case 7: 
            cout<<"Znalezienie elementu: "<<pomiarZnalezienie/100/1000<<" us ["<<rozmiar<<"]"<<endl;
            break;
    }
    } 
}
 
