#include <iostream>
#include <vector>

using namespace std;

int dp[1001][1001];
vector<char> trace;
int main(){
    string X ,Y;

    cin >> X >> Y;

    for(int i=1;i<=X.length();i++){
        for(int j=1;j<=Y.length();j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int x = X.length();
    int y = Y.length();
    
    while(x>0&&y>0){
        if(dp[x][y] == dp[x-1][y]) x--;
        else if(dp[x][y] == dp[x][y-1]) y--;
        else{
            trace.push_back(X[x-1]);
            x--;
            y--;
        }
    }
    
    cout << dp[X.length()][Y.length()] << '\n';
    for(int i=trace.size()-1;i>=0;i--){
        cout<<trace[i];
    }
   
}