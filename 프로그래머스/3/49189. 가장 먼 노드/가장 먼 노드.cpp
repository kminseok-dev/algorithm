#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+4);
    vector<bool> visited(n+4);
    vector<int> dist(n+2);
    
        for(auto node : edge){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
    
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        auto node = q.front(); q.pop();
        visited[node] = true;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dist[adj[node][i]] = dist[node] + 1;
                visited[adj[node][i]] = true;
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