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
Node * constructBT(int postorder[],int inorder[],int start,int end){
        static int idx = 4;
        if(start > end){
                return NULL;
        }
        int curr = postorder[idx];
        Node * a = new Node(postorder[idx]);
        idx--;
        int pos = search(inorder,start,end,curr);
        if(start == end){
                return a;
        }
        a->right = constructBT(postorder,inorder,pos+1,end);
        a->left = constructBT(postorder,inorder,start,pos-1);
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
                    5
                  /  
                 4    
                /  \  
               2    1 
                \
                 3
        */
       /*
                    3
                  /   \
                 2     1
                      / \
                     4   5
        */
        int postorder[]={3,2,1,4,5};
        int postorder2[]={2,4,5,1,3};
        int inorder[]={2,3,4,1,5};
        Node * root = constructBT(postorder2,inorder,0,4);
        printinorder(root);

}