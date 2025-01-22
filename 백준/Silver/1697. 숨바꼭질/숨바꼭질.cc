#include <bits/stdc++.h>
using namespace std;

int dir[3] = {-1,1,2};
int main(){
    queue<int> q;
    int n,k;
    cin >> n >> k;
    int max_size = max(n,k)*2+1;
    vector<int> arr(max_size,-1);
    arr[n] = 0;
    q.push(n);
    
 
    while(!q.empty()){
        int su = q.front();
        q.pop();
        
        if(su == k) break;
        for(int i=0; i<3; i++){
            int nv = su + dir[i];
            if(dir[i] == 2) nv = su*dir[i];
            if(nv < 0 || nv>=max_size||arr[nv]!= -1) continue;
            arr[nv] = arr[su] + 1;
            q.push(nv);
        }
    }
    cout << arr[k] << '\n';
    return 0;
       
}