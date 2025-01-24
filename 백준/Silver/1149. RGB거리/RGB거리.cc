#include <bits/stdc++.h>
#define FOR(i,j) for(int i=2; i<=j; i++)
using namespace std;
int n;
int house[1001][4];
int d[1001][4];
int main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3; j++){
            cin >> house[i][j];
        }
    }
    d[1][1] = house[1][1];
    d[1][2] = house[1][2];
    d[1][3] = house[1][3];

    FOR(i, n){
        d[i][1] = min(d[i-1][2],d[i-1][3])+house[i][1];
        d[i][2] = min(d[i-1][1],d[i-1][3])+house[i][2];
        d[i][3] = min(d[i-1][1],d[i-1][2])+house[i][3];
    }
    cout<< min(min(d[n][1],d[n][2]),d[n][3]);
}