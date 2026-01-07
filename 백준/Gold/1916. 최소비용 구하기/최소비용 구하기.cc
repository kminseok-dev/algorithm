#include<iostream>
#include<queue>
#include<functional>

#define X first
#define Y second

using namespace std;

int d[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<vector<pair<int,int>>> busInfo(100002);

int main(){
    int n,m;
    int u,v,pay;
    int startC,endC;

    fill(d,d+1001,2e9);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> u >> v >> pay;
        busInfo[u].push_back({pay,v});
    }

    cin >> startC >> endC;

    d[startC] = 0;

    pq.push({d[startC],startC});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X){
            continue;
        }

        for(auto nxt : busInfo[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X)continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y}); 
        }
    }

    cout << d[endC];
}