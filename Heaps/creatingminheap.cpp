#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
void swap(int &a,int &b){
        int temp = a;
        a= b;
        b = temp;
}
class minheap{
        public:
        int *harr;
        int capacity;
        int size;
        minheap(int cap){
                harr = new int[cap];
                size = 0;
                capacity = cap;
        }
        int parent(int i){
                return (i-1)/2;
        }
        int left(int i){
                return 2*i + 1;
        }
        int right(int i){
                return 2*i + 2;
        }
        int getmin(){
                return harr[0];
        }
        void insertkey(int k){
                if(capacity == size){
                        cout<<"Heap Overflow!";
                        return;
                }
                size++;
                int i = size - 1;
                harr[i] = k;
                while(i!=0 && harr[parent(i)]>harr[i]){
                        swap(harr[i],harr[parent(i)]);
                        i = parent(i);
                }
        }
        int height(){
                return ceil(log2(size+1) - 1);
        }
        int search(int k){
                for(int i=0;i<size;i++){
                        if(harr[i]==k){
                                return i;
                        }
                }
                return -1;
        }
        void print(){
                for(int i=0;i<size;i++){
                        cout<<harr[i]<<" ";
                }
                cout<<endl;
        }
        void minheapify(int i){
                int l = left(i);
                int r = right(i);
                int smallest = i;
                if(l < size && harr[l]<harr[i]){
                        // cout<<"changing to left"<<endl;
                        smallest = l;
                }
                if(r < size && harr[r]<harr[smallest]){
                        // cout<<"changing to right"<<endl;
                        smallest = r;
                }
                if(smallest != i){
                        // cout<<harr[smallest]<<endl;
                        swap(harr[smallest],harr[i]);
                        minheapify(smallest);
                }
                
        }
        int extractmin(){
                if(size<=0)return INT_MAX;
                if(size == 1){
                        size --;
                        return harr[0];
                }
                int root = harr[0];
                int i = harr[size -1];
                harr[0] = i;
                size--;
                minheapify(0);
                return root;

        }
        void decreasekey(int i , int new_val){
                harr[i] = new_val;
                while(i!=0 && harr[parent(i)]> harr[i]){
                        swap(harr[i],harr[parent(i)]);
                        i = parent(i);
                }
        }
        void deletekey(int i){
                decreasekey(i,INT_MIN);
                extractmin();
        }
        void heapsort(){
                int temp[capacity];
                for(int i=0;i<capacity;i++){
                        temp[i] = extractmin();
                        cout<<temp[i]<<" ";
                }
        }
};
int main(){
        minheap a(12);
        // cout<<a.size<<endl;
        a.insertkey(5);
        cout<<a.size<<endl;
        a.insertkey(6);
        cout<<a.size<<endl;
        a.insertkey(4);
        cout<<a.size<<endl;
        a.insertkey(3);
        cout<<a.size<<endl;
        a.insertkey(2);
        cout<<a.size<<endl;
        a.insertkey(1);
        a.insertkey(8);
        a.insertkey(9);
        a.insertkey(7);
        a.insertkey(11);
        cout<<a.size<<endl;
        cout<<a.height()<<endl;
}