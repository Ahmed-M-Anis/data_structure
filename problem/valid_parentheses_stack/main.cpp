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

    char peek(){
        assert(!isempty());
        return array[top];

    }

    void display(){
        for (int i = top ; i >= 0 ; --i)
            cout<<array[i];

    }


    int chack_parentheses(string parenthes){
        stack stk(500) ;
        int i = 0 ;
        for(int i = 0 ; i< (parenthes.size()) ; ++i){
            char cur = parenthes[i];
            if (cur == '[' || cur == '{' || cur =='(')
                stk.push(cur);
            else if(cur == ']' && stk.peek() == '[')
                stk.pop();
            else if(cur == '}' && stk.peek() == '{')
                stk.pop();
            else if(cur == ')' && stk.peek() == '(')
                stk.pop();
            else
                return 0 ;
        }
        if (!stk.isempty()){
            return 0;
        }
        return 1;

    }


};

int main()
{
    stack a(500) ;
    string b = "(][)";



   cout<<a.chack_parentheses(b);





}
