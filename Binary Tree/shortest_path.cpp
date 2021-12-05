#include <bits/stdc++.h>
using namespace std;
class Node {
        public:
        int data;
        Node * left;
        Node * right;
        Node(int x){
                data=x;
                left=NULL;
                right=NULL;
        }
};
bool getpath(Node * root, int key,vector <int> &path){
        if (root == NULL){
                return false;
        }

        path.push_back(root->data);
        if(root->data == key){
                return true;
        }else {
                if(getpath(root->left,key,path) || getpath(root->right,key,path)){
                        return true;
                }
        }
        path.pop_back();
        return false;
}
int lca(Node * root,int n1,int n2){
        vector <int> path1,path2;
        if(!getpath(root,n1,path1)||!getpath(root,n2,path2)){
                return -1;
        }
        int k = path1.size()>path2.size()?path2.size():path1.size();
        int i;
        for(i=0;i<k;i++){
                if(path1[i]!=path2[i]){
                        break;
                }
        }
        return path1[i-1];
}
Node * LCA2(Node * root,int n1,int n2){
        if(root==NULL){
                return NULL;

        }
        if(root->data == n1 || root->data == n2){
                return root;
        }
        Node * leftLCA = LCA2(root->left,n1,n2);
        Node * rightLCA = LCA2(root->right,n1,n2);
        if(leftLCA && rightLCA){
                return root;
        }
        if(leftLCA==NULL){
                return rightLCA;
        }
        return leftLCA;
}
int finddist(Node * root,int n,int dist){
        if(root==NULL){
                return -1;
        }
        if(root->data == n){
                return dist;
        }
        int left = finddist(root->left,n,dist+1);
        if(left != -1){
                return left;
        }
        return finddist(root->right,n,dist+1);
}
int distbwnode(Node * root,int n1,int n2){
        Node * r = LCA2(root,n1,n2);
        int d1 = finddist(r,n1,0);
        int d2 = finddist(r,n2,0);
        return d1+d2;
}
int main(){
       Node * a = new Node(1);
       a->left = new Node(2);
       a->right = new Node(3);
       a->left->left= new Node(4);
       a->left->right = new Node(5);
       a->right->left = new Node(6);
       a->right->right = new Node(7);
       Node * b = new Node(1);
       b->left = new Node(2); 
       b->left->left = new Node(3);
       cout<<distbwnode(a,6,4);

}