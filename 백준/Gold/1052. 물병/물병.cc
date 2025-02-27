#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,ans=0;
    cin>>n>>k;
    

    while(1){
        int temp = n, firstidx = -1, cnt = 0, idx = 0;
        while(temp){
            if(temp&1){
                if(firstidx == -1)
                    firstidx = idx;
                cnt++;
            }
            idx++;
            temp = temp >> 1;
        }
        if(cnt<=k)break;
        else{
            n += 1<<firstidx;
            ans += 1<<firstidx;
        }
    }
    
    cout<<ans;
    return 0;
}
