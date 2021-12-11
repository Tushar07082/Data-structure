#include <iostream>
#include <vector>
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
vector <Node * > constructBST(int start,int end){
        vector <Node *> trees;
        if(start > end){
                trees.push_back(NULL);
                return trees;
        }
        for(int i=start;i<=end;i++){
                vector<Node*>leftsubtrees = constructBST(start,i-1);
                vector<Node*>rightsubtrees = constructBST(i+1,end);
                for(int j=0;j<leftsubtrees.size();j++){
                        Node * left = leftsubtrees[j];
                        for(int k=0;k<rightsubtrees.size();k++){
                                Node* right = rightsubtrees[k];
                                Node * a = new Node(i);
                                a->left = left;
                                a->right = right;
                                trees.push_back(a);
                        }
                }
        }
        return trees;
}
void printpreorder(Node * root){
        if(root!=NULL){
                cout<<root->data<<" ";
                printpreorder(root->left);
                printpreorder(root->right);
        }
}

int main(){
        vector <Node *> trees = constructBST(1,5);
        for(int i=0;i<trees.size();i++){
                cout<<i+1<<": ";
                printpreorder(trees[i]);
                cout<<endl;
        }

}