#include <iostream>
#include <assert.h>

using namespace std;

class Vector {
private:
   int *arr = nullptr;
   int size = 0;
   int capacety ;
public:
   Vector(int size) : size(size){ // for make the frist size = the input
   if (size < 0)
       size = 1;
    capacety = size + 100;
   arr = new int[capacety] { };
}

void get(int idx){ //print element by index
    assert(idx >=0 && idx < size);
    cout<<arr[idx];
}

void set1(int idx, int val){ // add by index
    assert(idx >=0 && idx < size);
    arr[idx] = val ;
}

void print(){ //print all
    for (int i = 0 ; i<size ; ++i){
        cout<<arr[i]<<"  ";
    }
}

void capacety_extention(){ // capacety trick
    capacety = capacety * 2;
    int *arr2 = new int[capacety] ;
    for(int i = 0 ; i < size ; ++i){
        arr2[i] = arr[i] ;
    }

    swap(arr2 ,arr);
    delete[] arr2;

}

void push_back1(int val){
    if (capacety == size)
        capacety_extention();
    arr[size] = val;
    ++size;
}

~Vector() {
   delete[] arr;
   arr = nullptr;
}
};
int main()
{
    Vector v(3);
    v.set1(0,10);
    v.set1(1,8);
    v.set1(2,6);
    v.push_back1(15);
    v.push_back1(20);
    v.print();
    v.get(2);
    return 0;
}
