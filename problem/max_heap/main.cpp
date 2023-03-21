#include <iostream>

using namespace std;


class max_heap{
private:
    int *array{ } ;
    int size { };

    int left_chiled(int pos){
        int chiled = (pos*2)+1;
        if(chiled > size)
            return -1;
        return chiled ;
    }

    int right_chiled(int pos){
        int chiled = (pos*2)+2;
        if(chiled > size)
            return -1;
        return chiled ;
    }

    int parent(int pos){
        int p = (pos-1)/2;
        if(p < 0)
            return -1;
        return p;
    }

    void heapify_up(int pos){
        int p = parent(pos);
        if(array[pos] <= array[p] || pos == 0)
            return ;

        swap(array[p] ,array[pos]);
        heapify_up(p);
    }

    void heapify_down(int pos){
        int l_chiled = left_chiled(pos);
        int r_chiled = right_chiled(pos);

		if (l_chiled == -1)
			return;

        if(array[pos] >= array[l_chiled] && array[pos] >= array[r_chiled])
            return;
        if(array[l_chiled] < array[r_chiled])
            l_chiled = r_chiled;
        swap(array[l_chiled] ,array[pos]);
        heapify_down(l_chiled);
    }

public:

    max_heap(){
        array = new int [10000] { };
        size = 0;
    }

    void push(int value){
        array[size++] = value;
        heapify_up(size-1);
    }

    int top(){
        return array[0];
    }

    int pop(){
        array[0] = array[--size];
        heapify_down(0);
    }

    void cheak(){
        for(int i = size-1 ; i >= 0 ; --i){
            cout<<array[i]<<' ';
        }
    }

};

int main()
{
    max_heap a;
    a.push(50);
    a.push(40);
    a.push(35);
    a.push(60);
    a.push(12);
    a.push(30);
    a.push(20);
    a.push(70);
    a.push(11);
    a.push(9);

    cout<<a.top()<<endl;

    a.pop();
    a.pop();
    a.pop();
    a.pop();

    cout<<a.top();

    return 0;
}
