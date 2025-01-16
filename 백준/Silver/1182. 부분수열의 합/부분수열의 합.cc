#include <bits/stdc++.h>

using namespace std;

int arr[30];

int n,s,cnt;

void func(int k,int total){
    if(k==n){
        if(total==s)
            cnt++;
        return;
    }
    func(k+1,total);
    func(k+1,total+arr[k]);
   
    
}
int main(){
    cin>> n>> s;
    for(int i=0;i<n;i++)cin>> arr[i];
    
    func(0,0);
    if(s==0)cnt--;
    cout<<cnt;
    return 0;

}