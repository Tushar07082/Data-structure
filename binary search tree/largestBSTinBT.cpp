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
struct info{
        int min;
        int max;
        int size;
        int ans;
        bool isBST;
};
info largestBST(Node * root){
        if(root==NULL){
                return{INT_MAX,INT_MIN,0,0,true};
        }
        if(root->left == NULL && root->right == NULL){
                return{root->data,root->data,1,1,true};
        }
        info leftinfo = largestBST(root->left);
        info rightinfo = largestBST(root->right);
        info curr ;
        curr.size = 1+ leftinfo.size + rightinfo.size;
        curr.max = max(root->data,max(leftinfo.max,rightinfo.max));
        curr.min = min(root->data,min(leftinfo.min,rightinfo.min));

        if(leftinfo.isBST && rightinfo.isBST && root->data > leftinfo.max && root->data < rightinfo.min){
                curr.isBST = true;
                curr.ans = curr.size;
                return curr;
        }
        curr.ans = max(rightinfo.ans,leftinfo.ans);
        curr.isBST= false;
        return curr;
       

}
int main(){
        /*
                    1
                  /   \
                 2     3
                / \   / \
               1   5 2   7
        */
        Node * a = new Node(1);
       a->left = new Node(2);
       a->right = new Node(3);
       a->left->left= new Node(1);
       a->left->right = new Node(5);
       a->right->left = new Node(2);
       a->right->right = new Node(7);
        cout<<largestBST(a).ans;

}