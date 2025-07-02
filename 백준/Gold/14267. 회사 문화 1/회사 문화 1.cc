#include <bits/stdc++.h>

using namespace std;

vector<int> cmp[100001];
vector<int> result(100001);
void dfs(int member){

   
    for(int i:cmp[member]){
        result[i] += result[member];
        dfs(i);
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,boss,supervisor;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> supervisor;
        if(supervisor == -1){
            boss = i;
        }
        else
            cmp[supervisor].push_back(i);
    }
    int compliment,member;

    for(int i=1;i<=m;i++){
        cin >> member >> compliment;
        result[member] += compliment;
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<< result[i]<<' ';
    }
}