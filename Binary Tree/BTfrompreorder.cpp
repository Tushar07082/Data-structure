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
int search(int arr[],int start,int end,int key){
        for(int i=start;i<=end;i++){
                if(arr[i]==key){
                        return i;
                }
        }
        return -1;
}
Node * constructBT(int preorder[],int inorder[],int start,int end){
        static int idx =0;
        if(start > end){
                return NULL;
        }
        int curr = preorder[idx];
        Node * a = new Node(preorder[idx]);
        idx++;
        int pos = search(inorder,start,end,curr);
        if(start == end){
                return a;
        }
        a->left = constructBT(preorder,inorder,start,pos-1);
        a->right = constructBT(preorder,inorder,pos+1,end);
        return a;
}
void printinorder(Node * root){
        if(root==NULL){
                return;
        }
        printinorder(root->left);
        cout<<root->data<<" ";
        printinorder(root->right);
}
int main(){
        /*
                    3
                  /   \
                 2     1
                      / \
                     4   5
        */
        int preorder[]={3,2,1,4,5};
        int inorder[]={2,3,4,1,5};
        Node * root = constructBT(preorder,inorder,0,4);
        printinorder(root);

}