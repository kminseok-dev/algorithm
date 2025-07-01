#include <bits/stdc++.h>

using namespace std;


map<int,pair<int,int>> graph;
bool visited[50];
void deleteNode(int node){

   if(graph[node].first==-2||graph[node].second==-2){
        visited[node] = true;
        return;
   }
    visited[node] = true;
   
    deleteNode(graph[node].first);
    graph[node].first = -2;
    deleteNode(graph[node].second);
    graph[node].second = -2;
}
int main(){
    int n, root,parent;
    
    cin >> n;
    for(int i=0;i<n;i++){
        graph[i].first = -2;
        graph[i].second = -2;
    }

    for(int i=0;i<n;i++){
        cin >> parent;
        if(parent != -1){
            if(graph[parent].first==-2)
                graph[parent].first = i;
            else
                graph[parent].second = i;
            
        }
        else
            root = i;
    }
    int node;
    cin >> node;
    if(root == node){
        cout << 0;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        if(graph[i].second==node){
         
            graph[i].second = -2;
        }
        else if(graph[i].first==node){
      
            graph[i].first = -2;
         
        }
        if(graph[i].first==-2&&graph[i].second==-2){

        }
        
    }
    // for(int i=0;i<n;i++){
    //     if(graph[i].first==-2&&graph[i].second==-2){
    //         cout<<i<<'\n';
    //     }
    // }
    deleteNode(node);
    
    
    int cnt = 0;
   
    for(int i=0;i<n;i++){
        // if(i==3)cout<<"??"<<'\n';
        if((graph[i].first==-2&&graph[i].second==-2)&&!visited[i]){
            // cout<<i<<'\n';
            cnt ++;
        }
    }
    cout << cnt;

}