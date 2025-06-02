#include "testy.h"
#include "open_hash.h"
#include "chain_hash.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void testy::test(int struktura, int operacja, int rozmiar, float wypelnienie){

    mt19937 gen_k; //generator k
    mt19937 gen_v; //generator v
    uniform_int_distribution<int> k(0, INT_MAX);  //klucz   
    uniform_int_distribution<int> v(0, INT_MAX);  //wartosc     
    double pomiar_insert = 0;
    double pomiar_remove = 0;

    if(struktura == 1){
        for(int i = 0; i < 100; i++){
            gen_k.seed(i);                        //ziarno klucza
            gen_v.seed(i+200);                    //ziarno wartosci
            int elementy = rozmiar * wypelnienie; //liczba elementow do wstawienia
            OpenHash hash(rozmiar);               //tworzymy tablice

            for(int j = 0; j < elementy; j++){    //wstepne wypelnienie tablicy
                int key = k(gen_k);
                int value = v(gen_v);
                hash.insert(key, value);         
            }

            if(operacja == 1){         //insert
                int key = k(gen_k);
                int value = v(gen_v);
                auto start = high_resolution_clock::now();
                hash.insert(key, value); 
                auto end = high_resolution_clock::now();
                pomiar_insert += duration_cast<nanoseconds>(end - start).count(); 
            } else if(operacja == 2){  //remove
                int key = k(gen_k);
                auto start = high_resolution_clock::now();
                hash.remove(key);  
                auto end = high_resolution_clock::now();
                pomiar_remove += duration_cast<nanoseconds>(end - start).count(); 
            }
        }//koniec petli

        switch(operacja){
            case 1:
                cout <<"insert: " << pomiar_insert / 100 << " ns [" <<rozmiar<<"] ["<<wypelnienie*100<<"%]"<< endl;
                break;
            case 2:
                cout <<"remove: " << pomiar_remove / 100 << " ns [" <<rozmiar<<"] ["<<wypelnienie*100<<"%]"<< endl;
                break;
            default:
                cout << "Nieznana operacja" << endl;
        }
    } else if(struktura == 2){
        for(int i = 0; i < 100; i++){
            gen_k.seed(i);
            gen_v.seed(i+200);
            int elementy = rozmiar * wypelnienie; //liczba elementow do wstawienia
            ChainHash hash(rozmiar);              //tworzymy tablice

            for(int j = 0; j < elementy; j++){    //wstepne wypelnienie tablicy
                int key = k(gen_k);
                int value = v(gen_v);
                hash.insert(key, value);          
            }

            if(operacja == 1){ 
                int key = k(gen_k);
                int value = v(gen_v);
                auto start = high_resolution_clock::now();
                hash.insert(key, value); 
                auto end = high_resolution_clock::now();
                pomiar_insert += duration_cast<nanoseconds>(end - start).count(); 
            } else if(operacja == 2){ 
                int key = k(gen_k);
                auto start = high_resolution_clock::now();
                hash.remove(key);  
                auto end = high_resolution_clock::now();
                pomiar_remove += duration_cast<nanoseconds>(end - start).count(); 
            }
        }//koniec petli

        switch(operacja){
            case 1:
                cout <<"insert: " << pomiar_insert / 100 << " ns [" <<rozmiar<<"] ["<<wypelnienie*100<<"%]"<< endl;
                break;
            case 2:
                cout <<"remove: " << pomiar_remove / 100 << " ns [" <<rozmiar<<"] ["<<wypelnienie*100<<"%]"<< endl;
                break;
            default:
                cout << "Nieznana operacja" << endl;
        }
    }
}
