#ifndef tablica_dynamiczna
#define tablica_dynamiczna
#include<iostream>
template<typename T>
class tablicaDynamiczna{
    private:
    int size = 16;
    int fill = 0;
    T* arr = new T[size];
    void doubleSize() {
        size *= 2;
        T* temp = new T[size];
        for (int i = 0; i < fill; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;  // delete the old memory
        arr = temp;    // assign the new memory
    }
    public:
    T getFirst(){
        return arr[0];
    };
    T getLast(){
        return arr[fill-1];
    };
    T getSelect(int index){
        if(index < 0 || index > fill){
            std::cout<<"Index jest poza zakresem"<<std::endl;
            return T();
        }
        return arr[index];
    };
    void addFirst(T value){
        if(fill == size){
            doubleSize();
        }
        for(int i = fill; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        fill++;
    }
    void addLast(T value){
        if(fill == size){
            doubleSize();
        }
        arr[fill] = value;
        fill++;
    }
    void addSelect(T value, int index){
        if(index < 0 || index > fill){
            std::cout<<"Index jest poza zakresem"<<std::endl;
            return;
        }
        if(fill == size){
            doubleSize();
        }
        fill++;
        for(int i = index+1; i<=fill; i++){
            arr[i] = arr[i-1];
        }
        arr[index] = value;
    }
    void removeFirst(){
        if(fill == 0){
            std::cout<<"Tablica pusta"<<std::endl;
            return;
        }
        
        for(int i = 1; i<fill;i++){
            arr[i] = arr[i+1];
        }
        fill--;
    }
    void removeLast(){
        if(fill == 0){
            std::cout<<"Tablica jest pusta"<<std::endl;
            return;
        }
        fill--;
    }
    void removeSelect(int index){
        if(fill == 0){
            std::cout<<"Tablica jest usta"<<std::endl;
            return;
        }
        for(int i = index; i<fill; i++){
            arr[i] = arr[i+1];
        }
        fill--;
    }
    T findVal(T value){
        if(fill == 0){
            std::cout<<"Tablica jest usta"<<std::endl;
            return T();
        }
        int position = 0;
        for(int i = 0; i<=fill;i++){
            if(arr[i]==value){
                return position;
            }
        position++;
        }
        return T();
    }
};
#endif
