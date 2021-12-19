#include <iostream>
#include <limits.h>
using namespace std;
struct Node{
        int data;
        Node * left, * right;
        Node(int val){
                data = val;
                left = NULL;
                right = NULL;
        }
};
void calcpointers(Node * root,Node **first,Node **mid,Node **last,Node **prev){
        if(root == NULL){
                return;
        }
        calcpointers(root->left,first, mid, last, prev); 
        if( (*prev) && (*prev)->data > root->data){
                if(!  (*first)){
                        *first = *prev;
                        *mid = root;
                }
                else{
                        *last = root;
                }
        }
        *prev = root;
        calcpointers(root->right,first, mid, last, prev); 


}
void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
}
void recover(Node * root){
        Node * first,*mid,*last,*prev;
        first = mid = last = prev=  NULL;
        calcpointers(root, &first, &mid, &last, &prev);
        if(first && last){
                swap((first->data),(last->data));
        }
        else if(first && mid){
                 swap((first->data),(mid->data));
        }
}
void inorder(Node * root){
        if(root==NULL){
                return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}
int main(){
     /*
                  3
                 / \
                1   7
                 \
                  5
                 /  \
               2      4
                
        */ 
       Node * root = new Node(1);
       root->left = new Node(3);
       root->left->right = new Node(2);
       root->right = new Node(3);
       root->left->right = new Node(5);
       root->left->right->left = new Node(2);
       root->left->right->right = new Node(4);
       inorder(root);
       cout<<endl;
       recover(root);
       inorder(root);
        
}