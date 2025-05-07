#include <bits/stdc++.h>

using namespace std;
int city[52][52];
vector<pair<int,int>>chiLo;
vector<pair<int,int>>chooCkiLo;
vector<pair<int,int>>houseLo;
int n,m;
int result = 2e9;
int calculator(){
    int ans = 0;
    for(int i=0;i<houseLo.size();i++){
        int h_c_dist = 2e9;
        int h_x = houseLo[i].first;
        int h_y = houseLo[i].second;
        for(int j=0;j<chooCkiLo.size();j++){
            int c_x = chooCkiLo[j].first;
            int c_y = chooCkiLo[j].second;
            h_c_dist = min(h_c_dist,abs(c_x-h_x)+abs(c_y-h_y));
            
        }
        ans += h_c_dist;
    }
    return ans;
}
void backTrac(int idx,int cnt){
    if(cnt==m){
        result = min(result,calculator());
        return;
    }
    for(int i=idx;i<chiLo.size();i++){
        chooCkiLo.push_back(chiLo[i]);
        backTrac(i+1,cnt+1);
        chooCkiLo.pop_back();
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
            cin >>city[i][j];
            if(city[i][j]==2){
                chiLo.push_back({i,j});
            }
            else if(city[i][j]==1){
                houseLo.push_back({i,j});
            }
        }
    }
    backTrac(0,0);
    cout<<result;
    return 0;

}