#include <iostream>

using namespace std;
int v[21][21];
bool isused[10];
int n,gap=10000000;

void devide(int sp,int cur){
    if(sp==n/2){
        int teamLvalue = 0;
        int teamSvalue = 0;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isused[i]&&isused[j]){
                teamSvalue += v[i][j];
            }
            else if(!isused[i]&&!isused[j]){
                teamLvalue += v[i][j];
            }
        }
    }
    gap = min(gap,abs(teamSvalue-teamLvalue)); 
    return ;
    }
    for(int i=cur;i<n;i++){
        isused[i] = true;
        devide(sp+1,i+1);
        isused[i] = false;
    
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }

    }
    devide(0,0);
    cout<<gap;
}