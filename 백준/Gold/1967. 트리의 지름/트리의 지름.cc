#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>>tree[10001];

vector<pair<int,int>> dp(10001);
int mxdist;
int longNod;
void dfs(int node,int parent,int dis){
    
    for(auto child:tree[node]){
        if(child.first == parent) continue;
        
        if(mxdist<dis+child.second){
            mxdist = dis+child.second;
            longNod = child.first;
        }
        dfs(child.first,node,dis+child.second);
        
    }
 
    


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,parent,child,w;
    cin>>n;

    for(int i=1;i<n;i++){
        cin >> parent >> child >> w;
        tree[parent].push_back({child,w});
        tree[child].push_back({parent,w});
       
    }
    dfs(1,0,0);
    mxdist = 0;
    dfs(longNod,0,0);

    cout<<mxdist;
    
}