#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b){
    return a > b;

}
int main(){
    int n,ans=0;
    cin >> n;
    int A[n+1];
    int B[n+1];
    int temp[n+1];
    map <int,pair<int,int> >m;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        cin >> B[i];
        temp[i] = B[i];
    }
    sort(temp+1, temp+n+1);
    sort(A+1, A+n+1,cmp);

    for(int i=1;i<=n;i++){
       ans += temp[i]*A[i];
    }
    cout << ans;
}
