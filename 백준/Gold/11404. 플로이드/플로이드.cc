#include <bits/stdc++.h>
#define X first
#define Y second
#define Z third
using namespace std;

vector<vector<long long int>> v(105,vector<long long int>(105,0X7ffffff));
void CToC(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(v[i][j]>v[i][k]+v[k][j]){
                    v[i][j] = v[i][k]+v[k][j];
                }
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int a,b,c;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;
        if(v[a][b]>c)v[a][b] = c;
        
    }
    for(int i=1;i<=n;i++)
        v[i][i] = 0;
    
    CToC(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==0X7ffffff){
                cout<<0<<' ';
            }
            else cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    } 
    return 0;
}