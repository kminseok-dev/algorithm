#include<iostream>
#include<vector>

using namespace std;



int dp[5][4]; 

int board[100003][5];
int n;

void downning(){
    
    for(int i=2;i<=n;i++){
        //최소 
        dp[2][1] = min(dp[1][1],dp[1][2]) + board[i][1];
        dp[2][2] = min(min(dp[1][1],dp[1][2]),dp[1][3]) + board[i][2];
        dp[2][3] = min(dp[1][2],dp[1][3]) + board[i][3];

        //최대
        dp[4][1] = max(dp[3][1],dp[3][2]) + board[i][1];
        dp[4][2] = max(max(dp[3][1],dp[3][2]),dp[3][3]) + board[i][2];
        dp[4][3] = max(dp[3][2],dp[3][3]) + board[i][3];
        
        dp[1][1] = dp[2][1]; dp[1][2] = dp[2][2]; dp[1][3] = dp[2][3];
        dp[3][1] = dp[4][1]; dp[3][2] = dp[4][2]; dp[3][3] = dp[4][3];

        
        
    }
    
    cout << max(max(dp[4][1],dp[4][2]),dp[4][3]) << " " << min(min(dp[2][1],dp[2][2]),dp[2][3]);
    return;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin >> board[i][j];
        }
    }
    
    if(n==1){
        cout << max(max(board[1][1],board[1][2]),board[1][3]) << ' ' << min(min(board[1][1],board[1][2]),board[1][3]);
        return 0;
    }
    dp[1][1] = board[1][1]; dp[3][1] = board[1][1];
    dp[1][2] = board[1][2]; dp[3][2] = board[1][2];
    dp[1][3] = board[1][3]; dp[3][3] = board[1][3];

    downning();
    return 0;
    
    
    
    
}