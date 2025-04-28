#include "testowanie.h"
#include "heap.h"
#include "array.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

void testowanie::test(int struktura, int operacja, int rozmiar){

    mt19937 gen; //generator
    uniform_int_distribution<int> distElement(0, INT_MAX);      //zakres losowania liczb
    uniform_int_distribution<long long> distPrio(0, 15LL*rozmiar); //zakres losowania dla priorytetu
    double pomiarInsert = 0;    
    double pomiarExtract = 0;
    double pomiarFind = 0;
    double pomiarModify = 0;
    double pomiarSize = 0;

    if(struktura == 1){
        for(int i = 0; i<100;i++){
            gen.seed(200+i); //ziarno generacji 
            arrayQueue* kolejka = new arrayQueue(rozmiar);

            for(int j = 0; j < rozmiar;j++)
                kolejka->insert(distElement(gen), distPrio(gen)); //dodawanie elementow do kolejki
                
            switch(operacja){
                case 1: //insert
                {
                    auto start = high_resolution_clock::now();
                    kolejka->insert(distElement(gen), distPrio(gen));
                    auto stop = high_resolution_clock::now();
                    pomiarInsert += duration<double, nano>(stop - start).count();
                }
                    break;
                case 2: //extract
                {
                    auto start = high_resolution_clock::now();
                    kolejka->extractMax();
                    auto stop = high_resolution_clock::now();
                    pomiarExtract += duration<double, nano>(stop - start).count();
                }
                    break;
                case 3: //find
                {
                    auto start = high_resolution_clock::now();
                    kolejka->findMax();
                    auto stop = high_resolution_clock::now();
                    pomiarFind += duration<double, nano>(stop - start).count();
                }
                    break;
                case 4: //modify
                {
                    auto start = high_resolution_clock::now();
                    kolejka->modify(distElement(gen), distPrio(gen));
                    auto stop = high_resolution_clock::now();
                    pomiarModify += duration<double,nano>(stop - start).count();
                }
                    break;
                case 5: //size
                {
                    auto start = high_resolution_clock::now();
                    kolejka->printSize();
                    auto stop = high_resolution_clock::now();
                    pomiarSize += duration<double, nano>(stop - start).count();
                }
                    break;
                default:
                    cout << "nieznana operacja"<<endl;
                    break;
            }//koniec switcha
        }//koniec petli for100
        switch(operacja){
            case 1:
                cout<<"insert: "<<(pomiarInsert/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 2:
                cout<<"extract: "<<(pomiarExtract/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 3:
                cout<<"find: "<<(pomiarFind/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 4:
                cout<<"modify: "<<(pomiarModify/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 5:
                cout<<"size: "<<(pomiarSize/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
        }
    }else if(struktura == 2){
        for(int i = 0; i<100;i++){
            gen.seed(200+i); //ziarno generacji 
            heapQueue* kolejka = new heapQueue(rozmiar);

            for(int j = 0; j < rozmiar;j++)
                kolejka->insert(distElement(gen), distPrio(gen)); //dodawanie elementow do kolejki
        
            switch(operacja){
                case 1: //insert
                {
                    auto start = high_resolution_clock::now();
                    kolejka->insert(distElement(gen), distPrio(gen));
                    auto stop = high_resolution_clock::now();
                    pomiarInsert += duration<double, nano>(stop - start).count();
                }
                    break;
                case 2: //extract
                {
                    auto start = high_resolution_clock::now();
                    kolejka->extractMax();
                    auto stop = high_resolution_clock::now();
                    pomiarExtract += duration<double, nano>(stop - start).count();
                }
                    break;
                case 3: //find
                {
                    auto start = high_resolution_clock::now();
                    kolejka->findMax();
                    auto stop = high_resolution_clock::now();
                    pomiarFind += duration<double, nano>(stop - start).count();
                }
                    break;
                case 4: //modify
                {
                    auto start = high_resolution_clock::now();
                    kolejka->modify(distElement(gen), distPrio(gen));
                    auto stop = high_resolution_clock::now();
                    pomiarModify += duration<double, nano>(stop - start).count();
                }
                    break;
                case 5: //size
                {
                    auto start = high_resolution_clock::now();
                    kolejka->printSize();
                    auto stop = high_resolution_clock::now();
                    pomiarSize += duration<double, nano>(stop - start).count();
                }
                    break;
                default:
                    cout << "nieznana operacja" << endl;
                    break;
            }//koniec switcha
        }//koniec petli for100
        switch(operacja){
            case 1:
                cout<<"insert: "<<(pomiarInsert/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 2:
                cout<<"extract: "<<(pomiarExtract/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 3:
                cout<<"find: "<<(pomiarFind/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 4:
                cout<<"modify: "<<(pomiarModify/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
            case 5:
                cout<<"size: "<<(pomiarSize/100)/1000<<"us ["<<rozmiar<<"]"<<endl;
                break;
        }
    }
};