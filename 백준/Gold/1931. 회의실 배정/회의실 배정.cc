#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >meeting(100001, vector<int>(3));

int main(){
    int n,ans=1;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin >> meeting[i][2]>>meeting[i][1];
    }
    sort(meeting.begin(),meeting.begin()+n+1);
    int e = 2;
    int ele = meeting[1][1];
    for(int i=e;i<=n;i++){
        
        if(ele<=meeting[i][2]){
            ans++;
            ele = meeting[i][1];
            e = i;
            
        }
    }
    cout<< ans ;
}