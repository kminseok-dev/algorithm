#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
vector<pair<int,int> > chicken;
vector<pair<int,int> > house;
vector<pair<int,int> >ChooChi;
int n,m,result=2e9;
int arr[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int Calculator(){
    int ans = 0;
    for(int i=0;i<house.size();i++){
        int dist = 2e9;
        int x = house[i].X;
        int y = house[i].Y;
        //cout<< x<<y<<'\n';
        for(int j=0;j<ChooChi.size();j++){
            int chicken_x = ChooChi[j].X;
            int chicken_y = ChooChi[j].Y;
            dist = min(dist,abs(x-chicken_x)+abs(y-chicken_y));
            
        }
    ans+=dist;    
    
    //cout<<ans<<'\n';
    }
    return ans;
}
void BT(int idx,int k){

    if(k==m){
        //for(int i=0;i<m;i++)cout<<ChooChi[i].X<<" "<<ChooChi[i].Y<<'\n';
        result = min(result,Calculator());
        return;
    }
    for(int i=idx;i<chicken.size();i++){
        ChooChi.push_back(chicken[i]);
        BT(i+1,k+1);
        ChooChi.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                chicken.push_back({i,j});
            }
            else if(arr[i][j]==1){
                house.push_back({i,j});
            }
        }
    }
    BT(0,0);
    cout<<result;
   
}