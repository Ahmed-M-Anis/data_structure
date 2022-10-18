#include <iostream>
#include <assert.h>

using namespace std;

class vector1 {

private:
    int *arr = nullptr;
    int size;
    //int capacety ;
public:
    vector1(int size) : size(size){
        //capacety = size+1;
        arr = new int [size] {};
    }

    void right_rotation (){//will make the last element in the array the frist one
        int x = arr[size-1];
        for(int i = size-1 ; i >= 0 ; --i){
            arr[i] = arr[i-1];
        }
        arr[0] = x;
    }

    void lift_rotation(){//will make the frist element in the array the last one
        int x = arr[0];
        for(int i = 0 ; i<size-1 ; ++i){
            arr[i] = arr[i+1];
        }
        arr[size-1]= x;
    }

    void right_rotation_n_time(int n){
        n%=size;

        while(n--)
            right_rotation ();

    }

void set1(int idx, int val){ // add by index
    arr[idx] = val ;
}

void print(){
    for(int i = 0 ; i<size ; ++i){
        cout<<arr[i]<<endl;
    }
}


void pop(int idx){// will remove element from the array

    for(int i = idx ; i<size ;++i){
        arr[i] = arr[i+1];
    }

    --size;
}




    ~vector1(){
        delete[] arr;
        arr = nullptr;
    }

};

int main()
{
    vector1 v(4);
    v.set1(0,1);
    v.set1(1,2);
    v.set1(2,3);
    v.set1(3,4);
    //v.right_rotation();
    //v.lift_rotation();
    //v.right_rotation_n_time(10);
    v.pop(2);

    v.print();

    return 0;
}
