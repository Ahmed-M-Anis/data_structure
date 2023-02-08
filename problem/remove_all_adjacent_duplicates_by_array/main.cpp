#include <iostream>
#include <cassert>

#include<string>
using namespace std;


class stack{
private:
   int size {};
   int top {};
   char *array {};
public:
    stack(int size) :
        size(size) , top(-1){
        array = new char[size];
        }

	int isfull() {
		return top == size-1;
	}

	int isempty() {
		return top == -1;
	}

    void push(char data){
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


    void remove_all_adjacent(string x){
        stack stk(500);
        for(int i =0 ; i<x.size() ; ++i){
            char cur = x[i]; //we check if this char is the top of stack remove it and continue
            if(stk.isempty() || stk.peek() != cur){
               stk.push(cur);
            }
             else if(stk.peek() == cur){
                stk.pop();
            }
        }
        //for reverse the string to his normal
    stack stk2(500);
    while(!stk.isempty()){
        stk2.push(stk.peek());
        stk.pop();
    }

    stk2.display();

    }





};

int main()
{
    stack a(500);
    string b = "abbaca";
    a.remove_all_adjacent(b);


}
