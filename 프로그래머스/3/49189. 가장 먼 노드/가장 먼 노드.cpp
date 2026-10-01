#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1,-1);
    
    for(const auto& node : edge){
        adj[node[0]].push_back(node[1]);
        adj[node[1]].push_back(node[0]);
    }
    
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        auto node = q.front(); q.pop();
        for(int i=0;i<adj[node].size();i++){
            if(dist[adj[node][i]]==-1){
                dist[adj[node][i]] = dist[node] + 1;
                q.push(adj[node][i]);
            }
        }
    }
    
    sort(dist.begin()+1,dist.begin()+n+1);
    int maxdist = dist[n];
    answer++;
    for(int i=n-1;i>1;i--){
        if(maxdist>dist[i])return answer;
        answer++;
    }
    
    return answer;
}