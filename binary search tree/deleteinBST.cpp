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
Node * insertBST(Node * root,int val){
        if(root == NULL){
                return new Node(val);
        }
        if(val< root->data){
                root->left = insertBST(root->left,val);
        }else {
                root->right = insertBST(root->right,val);
        }
        return root;
}
Node * inordersucc(Node * root){
        Node * curr = root;
        while(curr && curr->left != NULL){
                curr = curr->left;
        }
        return curr;
}
Node * deleteinBST(Node * root,int val){
        
        if(root->data < val){
                root->right= deleteinBST(root->right,val);
        }else if(root->data > val){
                root->left =  deleteinBST(root->left,val);
        }else{
                if(root->left == NULL){
                        Node * temp = root->right;
                        free(root);
                        return temp;
                }
                else if(root->right == NULL){
                        Node * temp = root->left;
                        free(root);
                        return temp;
                }else {
                        Node * temp = inordersucc(root->right);
                        root->data = temp->data;
                        root->right = deleteinBST(root->right,temp->data);
                }
        }
        return root;
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
        Node * root = NULL;
        root = insertBST(root,5);
        root = insertBST(root,1);
        root = insertBST(root,3);
        root = insertBST(root,4);
        root = insertBST(root,2);
        root = insertBST(root,7);
        inorder(root);
        cout<<"\n";
        root = deleteinBST(root,5);
        inorder(root);
        cout<<"\n";
        

}