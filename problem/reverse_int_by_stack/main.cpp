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



    void reverse_int(int a){
        int z;

        while (a != 0){
            push(int(a%10));
            a = a/10;
        }
        int result;
        int power = 1;
        while(!isempty()){
            result += peek() * power;
            power *= 10;
            pop();
        }
        cout<<result;
    }



};

int main()
{
    stack a(50000);
    //a.push('a');
    //a.push('b');
    //a.push('c');
    //cout<<a.peek();
    //a.display();
    a.reverse_int(1234);
    //a.push(4);
    //a.push(5);
    //a.push(6);
    //a.push(7);
    //a.display();

}
