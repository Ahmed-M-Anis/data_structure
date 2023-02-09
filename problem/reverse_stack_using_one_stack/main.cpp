#include <iostream>
#include <cassert>

#include<string>
using namespace std;


class stack{
private:
   int size {};
   int top {};
   int *array {};
public:
    stack(int size) :
        size(size) , top(-1){
        array = new int[size];
        }

	int isfull() {
		return top == size-1;
	}

	int isempty() {
		return top == -1;
	}

    void push(int data){
        assert(!isfull());
        array[++top] = data;
    }

    int pop(){
        assert(!isempty());
        array[top--];
        return top;
    }

    int peek(){
        assert(!isempty());
        return array[top];

    }

    void display(){
        for (int i = top ; i >= 0 ; --i)
            cout<<array[i];

    }


    void add_to_end_of_stack(int n){
        array[top+1] = array[top];
        for(int i = top ; i>0 ; --i){
            array[i] = array[i-1];
        }
        array[0] = n;
        ++top;
    }

    void reverse_stack(){
        int s = top;
        for(int i = 0 ; i<=top-1 ; ++i){
            add_to_end_of_stack(array[++i]);

        }
        top = s;
    }











};

int main()
{
    stack a(500) ;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    //a.add_to_end_of_stack(0);
    //a.add_to_end_of_stack(-1);
    //a.display();
    a.reverse_stack();
    a.display();







}
