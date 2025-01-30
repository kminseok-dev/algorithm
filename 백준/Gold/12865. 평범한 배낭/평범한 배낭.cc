#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int d[101][100001];
map <int,pair<int,int> >bag;//X - 무게 , Y - 가치
int n,k,curweight,ans;
// void func(int c,int curweight, int value){
//     if(c == n+1){
//         if(curweight > k)return;
//         if(ans<value) ans = value;return;
//     }
//     func(c+1,curweight+bag[c].X,value+bag[c].Y);
//     func(c+1,curweight,value);
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> bag[i].X >> bag[i].Y;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>=bag[i].X){
                if(bag[i].Y+d[i-1][j-bag[i].X]>d[i-1][j])
                    d[i][j] = d[i-1][j-bag[i].X]+bag[i].Y;
                else    
                    d[i][j] = d[i-1][j];
            }
            else 
                d[i][j] = d[i-1][j];
        }
    }
    
    cout << d[n][k] << endl;
    return 0;
}