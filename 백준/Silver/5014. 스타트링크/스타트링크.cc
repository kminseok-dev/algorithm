#include <bits/stdc++.h>

using namespace std;

int main(){
    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;
    queue<int> q;
    int arr[1000001];
    for(int i=0;i<1000001;i++){
        arr[i]=-1;
    }
    if(U==0&&D==0||G<S&&D==0||G>S&&U==0){cout<<"use the stairs";return 0;}
    
    int button[2] = {U,-D};
    q.push(S);
    arr[S] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur==G)break;
        for(int i=0;i<2;i++){
            int nextfloor = cur+button[i];
            if(nextfloor>F||nextfloor<1)continue;
            if(arr[nextfloor]==-1){
                arr[nextfloor] = arr[cur]+1;
                q.push(nextfloor);
            }
                       
        }
    }
    if(arr[G]==-1)cout<<"use the stairs";
    else cout<<arr[G];
    return 0;
}
