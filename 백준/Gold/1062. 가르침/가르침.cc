#include <bits/stdc++.h>

using namespace std;
int words[51];
int learned;
int n,k,ans;

void dfs(int idx, int remain){
    if(remain == 0){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if((words[i]&learned)==words[i]){
                
                cnt++;
            }
        }
        ans = max(ans,cnt);
        return;
    }
    for(int i=idx;i<26;i++){
        
        if((learned&(1<<i)) == 0){
            learned |= 1<<i;
            dfs(i+1, remain-1);
            learned &= ~(1<<i);
        }
    }
    
}
int main(){
    cin >> n >> k;
    if(k<5){cout<<0;return 0;}
    string s;
    for(int i=0;i<n;i++){
        int num = 0;
        cin >> s;
        for(int j=0;j<s.length();j++){
            num |= 1<<(s[j]-'a');
        }
        words[i] = num;
    }
    learned |= 1<<('a'-'a');
    learned |= 1<<('n'-'a');
    learned |= 1<<('t'-'a');
    learned |= 1<<('i'-'a');
    learned |= 1<<('c'-'a');
    dfs(0,k-5);
    cout<<ans<<'\n';
    return 0;
}