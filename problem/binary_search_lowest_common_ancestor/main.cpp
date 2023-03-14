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


	int lowest_commen_ancestor(int x,int y){
	    tree* cur_x = this;
	    tree* cur_y = this;
	    int lowest_ancestor = data;

	    while (x != cur_x->data || y != cur_y->data ){
            if(x > cur_x->data)
                cur_x = cur_x->right;
            else if (x < cur_x->data)
                cur_x = cur_x->left;

            if(y > cur_y->data)
                cur_y = cur_y->right;
            else if (y < cur_y->data)
                cur_y = cur_y->left;

            if(cur_x->data == cur_y->data && lowest_ancestor > cur_y->data)
                lowest_ancestor = cur_y->data;
	    }
	    return lowest_ancestor;
	}

};



int main()
{
    tree a(50);
    a.Insert(20);
    a.Insert(60);
    a.Insert(15);
    a.Insert(45);
    a.Insert(58);
    a.Insert(70);
    a.Insert(16);
    a.Insert(35);
    a.Insert(73);
    a.Insert(36);
    a.Insert(75);

    //a.print_inorder();
    //the output will be sorted

    cout<<a.lowest_commen_ancestor(58 ,70);

    return 0;
}
