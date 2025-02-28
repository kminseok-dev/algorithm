#include <bits/stdc++.h>

using namespace std;
vector<string> str;
int max_read_words;
int n,k;
bool learned[26];
int Readable(){
    int cnt=0;
    for(string s : str){
        
        bool readable = true;
        for(char c : s){
            if(!learned[c-'a']){
                readable = false;
                break;
            }
        }
        if(readable){cnt++;}
    }
    return cnt;
}
void dfs(int idx, int remain){
    if(remain==k-5){
        max_read_words = max(max_read_words,Readable());
        return;
    }
    for(int i=idx;i<26;i++){
        if(!learned[i]){
            learned[i]=true;
            dfs(i+1, remain+1);
            learned[i]=false;
        }
    
    }
    
}
int main(){
    
    cin >> n >> k;
    
    if(k<5){cout<<0;return 0;}
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        s = s.substr(4,s.length()-8);
        set<char> unique_chars(s.begin(),s.end());
        str.push_back(string(unique_chars.begin(),unique_chars.end()));
    }
    
    learned['a'-'a'] = true;
    learned['n'-'a'] = true;
    learned['t'-'a'] = true;
    learned['i'-'a'] = true;
    learned['c'-'a'] = true;
    dfs(0, 0);
    
    cout<<max_read_words<<'\n';
    return 0;
    
}