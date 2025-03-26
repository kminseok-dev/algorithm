#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)
using namespace std;

int rgbValue[1001][4];
int RGB[1001][4];
int n,result=0xf777777;
void dp(int idx){
    FOR(i,n)FOR(j,4)RGB[i][j] = 0xf777777;
    RGB[1][idx] = rgbValue[1][idx];
    for(int i=2;i<=n;i++){
        RGB[i][1] = min(RGB[i-1][2],RGB[i-1][3]) + rgbValue[i][1];
        RGB[i][2] = min(RGB[i-1][1],RGB[i-1][3]) + rgbValue[i][2];
        RGB[i][3] = min(RGB[i-1][1],RGB[i-1][2]) + rgbValue[i][3];
    }
    RGB[n][idx] = 0xf777777;
    result = min(result,min(min(RGB[n][1],RGB[n][2]),RGB[n][3]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    FOR(i,n)
        FOR(j,3){
            cin>>rgbValue[i][j];
        }
    FOR(i,3)dp(i);
    
    cout<< result;
    
    return 0;
}