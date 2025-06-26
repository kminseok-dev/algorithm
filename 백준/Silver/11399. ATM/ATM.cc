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
   
    int ans = line[0];
    for(int i=1;i<n;i++){
        int result = 0;

        for(int j=0;j<=i;j++){
            result += line[j];
        }
        ans += result;
       
    }
    cout<<ans;
}