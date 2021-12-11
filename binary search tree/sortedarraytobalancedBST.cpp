#include <iostream>
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
Node * makebalancedBST(int arr[],int l,int r){
        if(l>r){
                return NULL;
        }
        int mid = (l+r)/2;
        Node * root = new Node(arr[mid]);
        root->left = makebalancedBST(arr,l,mid-1);
        root->right = makebalancedBST(arr,mid+1,r);
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
        int a[]={10,20,30,40,50};
        Node * root = makebalancedBST(a,0,4);
        printpreorder(root);

}