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

    void collision(int ar[], int si){
        //the idea is the positive move to right
        //negative move to left and when have collision the smallest one disteroy
        stack stk(5);
        for(int i = 0 ; i< si ; ++i){
            if(ar[i] > 0 || stk.isempty())
                stk.push(ar[i]);
            else if(ar[i]< 0 && stk.peek() < 0){
                stk.push(ar[i]);
            }
            else if(ar[i] < 0 && (ar[i]*-1) < stk.peek()){
                continue;
            }
            else if(ar[i] < 0 && (ar[i]*-1) > stk.peek()){
                stk.pop();
                --i;
            }
            else
                stk.pop();
        }
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
    stack a(500) ;
    int b[4] = {1,2,-3,4};



    a.collision(b, 4);





}
