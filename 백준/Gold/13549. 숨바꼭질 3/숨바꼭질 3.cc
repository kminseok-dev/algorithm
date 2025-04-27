#include <bits/stdc++.h>
#define FOR(i,j) for(int i=0;i<j;i++)

using namespace std;

int dir[3] = {1,-1,2}; 
queue<int> q;
int main(){
    vector<int> v(200005,-1);
    int n,k;
    cin>>n>>k;
    if(n==k){
        cout << 0;
        return 0;
    }
    v[n] = 0;
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        FOR(i,3){
            int next = cur + dir[i];
            if(dir[i]==2) next = 2 * cur;
            if(next<0||next>=200005) continue;
            if(v[next]==-1){
                if(dir[i]!=2)v[next] = v[cur] + 1;
                else v[next] = v[cur]; 
                q.push(next);
            }
            else{
                if((dir[i]!=2&&v[next]>v[cur]+1)||(dir[i]==2&&v[next]>v[cur])){
                    if(dir[i]==2) v[next] = v[cur];
                    else v[next] = v[cur] + 1; 
                    q.push(next); 
                } 
            }
        }
    }
    cout<<v[k];
    return 0;
}