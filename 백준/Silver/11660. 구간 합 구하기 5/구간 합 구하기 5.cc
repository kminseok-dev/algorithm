#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)
using namespace std;

int arr[1025][1025];
int d[1025][1025];
vector<vector<int> >spot;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,x1,y1,x2,y2;
    cin >> n >> m;
    
    
    
    FOR(i,n){
        FOR(j,n)
            cin >> arr[i][j];  
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++)
            arr[i+1][j] += arr[i][j];
    }
    while(m>0){
        m--;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=y1;i<=y2;i++){
            if(x1!=0){
                d[x2][i] = arr[x2][i]-arr[x1-1][i];
            }    
            else{
                d[x2][i] = arr[x2][i];
            }   
        }
        for(int i=y1;i<y2;i++){
            d[x2][i+1] += d[x2][i];
        }
        cout<<d[x2][y2]<<'\n';
    }
    
    
    
    return 0;
}