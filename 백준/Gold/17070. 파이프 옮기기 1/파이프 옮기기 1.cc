#include <bits/stdc++.h>

using namespace std;

int dx[3] = {0,1,1};
int dy[3] = {1,1,0};
int home[18][18];
int dp[18][18][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> home[i][j];
        }
    }
    dp[1][2][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=3;j<=n;j++){
            if(home[i][j])continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
            if(!(home[i-1][j]||home[i][j-1])){
                dp[i][j][2] = dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            }
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;

}