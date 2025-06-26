#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> line(n);
    for(int i=0;i<n;i++){
        cin >> line[i];
    }
    sort(line.begin(),line.end());
   
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += line[i] * (n-i);
    }
    cout<<ans;
}