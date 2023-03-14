#include <iostream>

using namespace std;

class tree{//binary search tree
private:
    int data { } ;
    tree* left { };
    tree* right { };
public:
    tree(int data):
        data(data){}

    void Insert(int vall){
        if(vall < data){
            if(left)
                left->Insert(vall);
            else
                left = new tree(vall);
        }
        else if(vall >data){
            if(right)
                right->Insert(vall);
            else
                right =new tree(vall);
        }

    }

    void print_inorder() {
		if(left)
			left->print_inorder();
		cout << data << " ";
		if(right)
			right->print_inorder();
	}

};



int main()
{
    tree a(5);
    a.Insert(7);
    a.Insert(9);
    a.Insert(3);
    a.Insert(1);
    a.Insert(2);

    a.print_inorder();
    //the output will be sorted

    return 0;
}
