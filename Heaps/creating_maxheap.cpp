#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
void swap(int &a,int &b){
        int temp = a;
        a= b;
        b = temp;
}
class maxheap{
        public:
        int * harr;
        int capacity;
        int size;
        maxheap(int cap){
                harr = new int[cap];
                capacity = cap;
                size = 0;
        }
        int parent(int i){
                return (i-1)/2;
        }
        int left(int i){
                return (2*i + 1);
        }
        int right(int i){
                return (2*i + 2);
        }
        int getmax(){
                return harr[0];
        }
        void insertkey(int val){
                if(size == capacity){
                        cout<<"Overflow!\n";
                        return;
                }
                size ++;
                int i = size -1;
                harr[i] = val;
                while(i!=0 && harr[parent(i)]<harr[i]){
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
        void maxheapify(int i){
                int l = left(i);
                int r = right(i);
                int largest = i;
                if(l < size && harr[l]>harr[i]){
                        largest = l;
                }
                if(r < size && harr[r]> harr[largest]){
                        largest = r;
                }
                if(largest != i){
                        swap(harr[largest],harr[i]);
                        maxheapify(largest);
                }
        }
        int extractmax(){
                if(size <= 0)return INT_MIN;
                if(size == 1){
                        size --;
                        return harr[0];
                }
                int root = harr[0];
                harr[0] = harr[size - 1];
                size --;
                maxheapify(0);
                return root;
        }
        void decreasekey(int i,int new_val){
                harr[i] = new_val;
                while(i!=0 && harr[parent(i)]< harr[i]){
                        swap(harr[i],harr[parent(i)]);
                        i = parent(i);
                }
        }
        void deletekey(int i){
                decreasekey(i,INT_MAX);
                extractmax();
        }
        void heapsort(){
                int temp[capacity];
                for(int i=0;i<capacity;i++){
                        temp[i] = extractmax();
                        cout<<temp[i]<<" ";
                }
        }
};
int main(){
        maxheap a(12);
        a.insertkey(5);
         
        a.insertkey(6);
         
        a.insertkey(4);
         
        a.insertkey(3);
         
        a.insertkey(2);
         
        a.insertkey(1);
        a.insertkey(8);
        a.insertkey(9);
        a.insertkey(7);
        a.insertkey(11);
        a.insertkey(12);
        a.insertkey(13);
        a.print();

        a.heapsort();
}