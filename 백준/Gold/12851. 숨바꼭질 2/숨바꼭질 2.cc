#include <bits/stdc++.h>

using namespace std;
queue<int> q;
int direc[3] = {1,-1,2};

int main(){
    vector<int> arr(200005,-1);
    int N,K,cnt=0;
    cin >> N >> K;
    if(N==K){
        cout<<0<<'\n'<<1;
        return 0;
    }
    q.push(N);
    arr[N] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int next = cur + direc[i];;
            if(direc[i]==2)next = cur * 2;
            if(next<0||next>200005)continue;
            if(arr[next]!=-1&&(arr[next]<arr[cur]+1))continue;
            arr[next] = arr[cur] + 1;
            if(next==K){
                if(arr[cur]+1==arr[K]){
                    cnt++;
                }
            }
            q.push(next);
        }
    }
    cout<<arr[K]<<'\n'<<cnt;
    return 0;
}