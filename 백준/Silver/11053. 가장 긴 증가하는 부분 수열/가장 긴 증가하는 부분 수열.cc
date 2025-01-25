#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)

using namespace std;
int a[1005]; // 수열을 넣을 배열
int b[1005]; // 현재 인덱스 원소가 포함 됐울 때 길이를 체크해줄 배열
bool visited[1005];
int n,ans,ele;//수열의 길이, 출력할 값, 기준이 될 원소

int main(){
    
    cin>>n;
    if(n==1){cout<<1;return 0;}
    FOR(i,n)cin>>a[i];
   // subq(1);
    FOR(i,n)b[i] = 1;
    
    for(int i=2;i<=n;i++){
        ele = a[i]; // 기준이 될 원소를 2번부터 잡고 시작 
        for(int j=1;j<i;j++){ // ele의 바로 앞까지 작은 수들을 비교해서 
            if(ele>a[j]){ 
                if(b[j]>=b[i])b[i] = b[j]+1; //앞선 길이를 체크해서 자신보다 짧은 길이를 가지고 있으면 길이에 더하지 않아서 
                                             //21 20 30 과 같은 문제에서 21:1 20:1 30:2로 문제 없이 길이를 체크한다 
            }
        } 
    }
    FOR(i,n){
        if(ans<b[i])ans = b[i];
    }
    cout<<ans<<endl;
}
