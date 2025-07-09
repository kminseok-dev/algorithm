#include <iostream>
#include <vector>


using namespace std;

vector<int> tree[50002];
int ancestor[50002][21];
int depth[50002];
void dfs(int node,int parent){
    
    ancestor[node][0] = parent;
    for(int i=1;i<21;i++){
        ancestor[node][i] = ancestor[ancestor[node][i-1]][i-1];
    }
    for(int child : tree[node]){
        if(child == parent)continue;
        depth[child] = depth[node] + 1;
        dfs(child,node);
    }

}
int find_LCA(int u,int v){

    if(depth[u]<depth[v]) swap(u,v);

    for(int i=20;i>=0;i--){
        if(depth[u]-(1<<i) >= depth[v])
            u = ancestor[u][i];
    }
    if(u==v) return u;

    for(int i=20;i>=0;i--){
        if(ancestor[u][i]!=ancestor[v][i]){
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    return ancestor[u][0];



}
int main(){

    int n,m,u,v;
    cin>>n;

    for(int i=1;i<n;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        cout<<find_LCA(u,v)<<'\n';

    }
}