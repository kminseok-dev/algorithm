// #include <bits/stdc++.h>

// using namespace std;
// int dp[1001][1001];
// int main(){
//     int ans=0;
//     string s1,s2;
//     cin>>s1>>s2;
    
//     for(int i=1;i<=s1.size();i++){
//         for(int j=1;j<=s2.size();j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j] = dp[i-1][j-1]+1;
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }
//             ans = max(ans,dp[i][j]);
//         }
//     }
//     cout<<ans;
// }
#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans=0; 
    string s1,s2,result;
    cin>>s1>>s2;
    
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    int dx=s1.size(),dy=s2.size();
    while(dx!=0&&dy!=0){
        if(dp[dx][dy]==dp[dx-1][dy]){
            
            dx--;
            
        }
        else if(dp[dx][dy]==dp[dx][dy-1]){
            dy--;
            
        }
        else{
            result+=s1[dx-1];
            dx--;dy--;
        }
        
    }
    // for(int i=1;i<=s1.size();i++){
    //     for(int j=1;j<=s2.size();j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
            
    
    cout<<ans<<'\n';
    if(ans!=0){
        for(int i=result.size()-1;i>=0;i--){
            cout<<result[i];
        }
    }
    return 0;
}
// 8 8
// 7 7
// 6 6
// 5 6
// 4 5
// 3 4
// 2 3
// 2 2
// 1 1
// 0 0