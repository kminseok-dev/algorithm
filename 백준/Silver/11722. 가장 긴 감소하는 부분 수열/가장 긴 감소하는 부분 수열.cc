#include <bits/stdc++.h>

using namespace std;

int arr_len[1001];
int num_arr[1001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num_arr[i];
    }

    for(int i=1;i<=n;i++){
        arr_len[i] = 1;
    }
    int ele;
    for(int i=2;i<=n;i++){
        ele = num_arr[i]; //기준
        for(int j=1;j<i;j++){
            if(ele<num_arr[j]){
                if(arr_len[j]>=arr_len[i]){
                    arr_len[i] = arr_len[j]+1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(arr_len[i]>ans)ans = arr_len[i];
    }
    cout<<ans<<'\n';    
        
}