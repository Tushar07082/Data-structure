#include <iostream>
using namespace std;
int parent[1000000];
int ranki[1000000];
void makeset(int n){
        for(int i=0;i<n;i++){
                parent[i] = i;
                ranki[i]=0;
        }
}
int findpar(int i){
        if(parent[i]==i){
                return i;
        }
        parent[i] = findpar(parent[i]);
        return parent[i];
}
void unioni(int u, int v){
        u = findpar(u);
        v = findpar( v);
        if(ranki[u] < ranki[v]){
                parent[u] = v;
        }
        else if (ranki[v]>ranki[u]){
                parent[v] = u;
        }else{
                parent[u] = v;
                ranki[v] ++;
        }
}
int main(){

}