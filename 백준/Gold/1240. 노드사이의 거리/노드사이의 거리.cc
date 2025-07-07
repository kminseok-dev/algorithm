#include <iostream>
#include <vector>


using namespace std;

vector<pair<int,int>>tree[1001];
int result;

bool dfs(int node,int end, int parent,int dist){
    if(node == end){
        result = dist;
        return true;
    }
    for(auto child:tree[node]){
        if(child.first == parent)continue;
        if(dfs(child.first,end,node,dist+child.second)) return true;
    }
    return false;

}

int main(){
    int n,m,u,v,w;
    cin >> n >> m;
    for(int i=1;i<n;i++){
        cin >> u >> v >> w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    int a,b;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        dfs(a,b,0,0);
        cout<<result<<'\n';
    }
}