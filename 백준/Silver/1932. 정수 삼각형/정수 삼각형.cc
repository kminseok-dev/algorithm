#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> triangle;
int dp[502][502];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,num;
    
    cin >> n;

    for(int i=0;i<n;i++){
        vector<int> line;
        for(int j=0;j<=i;j++){
            cin >> num;
            line.push_back(num);
        }
        triangle.push_back(line);

    }
    dp[0][0] = triangle[0][0];

    for(int i=1;i<n;i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                dp[i][j] = dp[i-1][0] + triangle[i][j];
            }
            else if(j==triangle[i].size()-1){
                dp[i][j] = dp[i-1][triangle[j-1].size()-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
        
        
    }
    int result = 0;
    for(int i=0;i<triangle[n-1].size();i++){
        result = max(result,dp[n-1][i]);
    }
    cout << result;

}