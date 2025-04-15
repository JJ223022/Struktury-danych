#include<iostream>
#include <chrono>
#include "lista_wiazana.h"
#include "tablica_dynamiczna.h"
using namespace std;
using namespace std::chrono;
int main(){
   int rozmiar = 1000000;
   long long time = 0;
   int il_pomiarow = 50;
   auto start = high_resolution_clock::now();
   auto stop = high_resolution_clock::now();
   listaDwukierunkowa<int> lista;
   tablicaDynamiczna<int> tablica;
   listaDwukierunkowa<int> lista_temp;
   tablicaDynamiczna<int> tablica_temp;
   for(int i = 0; i < rozmiar; i++){
    lista.addToEnd(i);
    tablica.addLast(i);
   }
   cout<<"----------------pomiary Listy--------------"<<endl;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    lista.addToStart(2137);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.removeStart();
   }
   cout <<"addToStart: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    lista.addToEnd(2137);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.removeEnd();
   }
   cout <<"addToEnd: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    lista.addToSelect(175923,index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.removeSelect(index);
   }
   cout <<"addToSelect: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    lista.removeStart();
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.addToStart(9999);
   }
   cout <<"removeStart: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    lista.removeEnd();
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.addToStart(0);
   }
   cout <<"removeEnd: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    lista.removeSelect(index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    lista.addToSelect(index,index);
   }
   cout <<"removeSelect: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    lista.findVal(index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
   }
   cout <<"findVal: " << time/il_pomiarow<<endl;
   cout <<"-------------------------pomiary tablicy-----------------" <<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    tablica.addFirst(123456);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.removeFirst();
   }
   cout <<"addFirst: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    tablica.addLast(123456);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.removeLast();
   }
   cout <<"addLast: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    tablica.addSelect(123456, index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.removeSelect(index);
   }
   cout <<"addSelect: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    tablica.removeFirst();
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.addFirst(9999);
   }
   cout <<"removeFirst: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    start = high_resolution_clock::now();
    tablica.removeLast();
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.addLast(0);
   }
   cout <<"removeLast: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    tablica.removeSelect(index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
    tablica.addSelect(index,index);
   }
   cout <<"removeSelect: " << time/il_pomiarow<<endl;
   time = 0;
   for(int i = 0;i < il_pomiarow; i++){
    int index = rozmiar/2;
    start = high_resolution_clock::now();
    tablica.findVal(index);
    stop = high_resolution_clock::now();
    time += duration_cast<nanoseconds>(stop-start).count();
   }
   cout <<"findVal: " << time/il_pomiarow<<endl;
}