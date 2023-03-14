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

    bool SEARCH(int target) {	// search for value by recurtion
		if (target == data)
			return true;

		if (target < data)
			return left && left->SEARCH(target);

		return right && right->SEARCH(target);
	}



	bool Search(int vall){ //search for value by iterative way
	    tree* cur =this;
	    while(cur){
            if(cur->data == vall)
               return 1;
	        if(vall < data){
                if(!left)
                    return 0;
                else
                    cur =cur->left;
	        }
	        else if(vall > data){
                if(!right)
                    return 0;
                else
                    cur = cur->right ;
	        }
	    }
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

    //a.print_inorder();
    //the output will be sorted
    cout<<a.Search(20);

    return 0;
}
