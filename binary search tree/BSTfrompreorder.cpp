#include <iostream>
#include <limits.h>
using namespace std;
struct Node{
        int data;
        Node * left,*right;
        Node(int val){
                data = val;
                left = NULL;
                right = NULL;
        }
};
Node * BSTfrompreorder(int preorder[],int * preorderIDX,int key,int min,int max,int n){
        if(*preorderIDX >= n){
                return NULL;
        }
        Node * root = NULL;
        if(key>min && key<max){
                root = new Node(key);
                *preorderIDX = *preorderIDX + 1;
                if(*preorderIDX < n){
                        root->left = BSTfrompreorder(preorder,preorderIDX,preorder[*preorderIDX],min,key,n);
                }
                if(*preorderIDX < n){
                        root->right = BSTfrompreorder(preorder,preorderIDX,preorder[*preorderIDX],key,max,n);
                }
        }
        return root;
}
void printpreorder(Node * root){
        if(root!=NULL){
                cout<<root->data<<" ";
                printpreorder(root->left);
                printpreorder(root->right);
        }
}
int main(){
        int preorder[]= {10,2,1,13,11};
        int preorderIDX = 0;
        int n = 5;
        Node * root = BSTfrompreorder(preorder,&preorderIDX,10,INT_MIN,INT_MAX,n);
        printpreorder(root);

}