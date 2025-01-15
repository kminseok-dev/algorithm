#include <bits/stdc++.h>

using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int n,cnt=0;
void Queen(int y){
    if(y==n){cnt++;return;}
    for(int i=0;i<n;i++){
        if(isused1[i]||isused2[i+y]||isused3[y-i+n-1])continue;
        isused1[i] = 1;
        isused2[i+y] = 1;
        isused3[y-i+n-1] = 1;
        Queen(y+1);
        isused1[i] = 0;
        isused2[i+y] = 0;
        isused3[y-i+n-1] = 0;
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    Queen(0);
    cout<< cnt;
    return 0;
}