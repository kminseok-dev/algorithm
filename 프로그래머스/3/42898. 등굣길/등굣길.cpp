#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n+1,vector<int>(m+1,0));
    map[0][1] = 1;
    for(auto puddle:puddles){
        map[puddle[1]][puddle[0]] = -1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==-1){
                map[i][j] = 0;
                continue;
            }
            map[i][j] = (map[i-1][j] + map[i][j-1]) % 1000000007;
        }
    }
    
    return map[n][m] % 1000000007;
    
}
