#include<iostream>
#include<vector>

using namespace std;

struct Edge{
    int u,v,w;
    
};
vector<Edge>map;

int dist[502];
int TC,N,M,W;
int S,E,T,start,dst;

void input(){

    cin >> N >> M >> W;
    
    map.clear();
    
    for(int j=1;j<=M;j++){
        cin >> S >> E >> T;
        map.push_back({S,E,T});
        map.push_back({E,S,T});
    }
    for(int j=1;j<=W;j++){
        cin >> start >> dst >> T;
        map.push_back({start,dst,-T});
        
        
    }
    

}
bool bellmanFord(){

    bool ans = false;

    for(int i=0;i<=N;i++){
        dist[i] = 0;
    }

    for(int i=1;i<=N;i++){
        for(auto edge : map){
            if(dist[edge.u]+edge.w < dist[edge.v]){
                dist[edge.v] = dist[edge.u] + edge.w;
                if(i==N){
                    ans = true;
                    return ans;
                }
            }

        }
    }
    return ans;
    

}

int main(){
    
    cin >> TC;

    while(TC-->0){
        input();
        if(bellmanFord()){
            cout << "YES"<<'\n';
        }
        else{
            cout << "NO" << '\n';
        }

    }
    return  0;

}



