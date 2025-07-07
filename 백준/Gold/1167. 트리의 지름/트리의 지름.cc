#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int>> tree[100001];
int mxdist,longNode;

void dfs(int node,int parent,int dist){

    for(auto child:tree[node]){
        if(child.first == parent)continue;

        if(mxdist<dist+child.second){
            mxdist = dist+child.second;
            longNode = child.first;
        }
        dfs(child.first,node,dist+child.second);




    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,u,v,w;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin >> u;
        while(1){
            cin >> v;
            
            if(v==-1)break;
            cin>>w;
            
            tree[u].push_back({v,w});
            

        }
    }
    dfs(1,0,0);
    mxdist = 0;
    dfs(longNode,0,0);
    cout<<mxdist;

    

    
}