#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int Graph[10003];

void PostOrder(int start, int end){
    if(start==end){return;}
    if(start==end-1){
       
        cout<<Graph[start]<<'\n';
        return;
    }
    int Index = start+1;
    while(Index<end){
        if(Graph[start]<Graph[Index]){
            break;
        }
        Index++;
    }
    PostOrder(start+1,Index);
    PostOrder(Index,end);

    cout<<Graph[start]<<'\n';
    
}
int main(){
    int node;
    int idx=1;
    while(cin>>node){
        Graph[idx++]=node;     
    }
    PostOrder(1, idx);
    
        
        
 
    return 0;
}