    #include <bits/stdc++.h>
    typedef long long ll;
    using namespace std;
    vector<ll> v;

    void func(ll k,int cnt){
        if(cnt>10)return;
        v.push_back(k);
        for(int i=0;i<=9;i++){
            if(k%10>i){
                func(k*10+i,cnt+1);
            }
        }
        return;
        
        
        
    }
    int main(){
        int n;
        cin>>n;
        int cnt = 1;
        
        for(int i=0;i<=9;i++){
            func(i,1);
        }
        sort(v.begin(),v.end());
        if(n>=v.size()){
            cout<<-1;
            return 0;
        }
        
        cout<<v[n];
        return 0;
        
    }