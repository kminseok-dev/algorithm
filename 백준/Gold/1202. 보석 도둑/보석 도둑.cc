#include <bits/stdc++.h>
#define X first
#define Y second
typedef long long ll;
using namespace std;
vector<int> bag;
priority_queue<int,vector<int>,less<int> > value;
pair<int,int> jew[300001];
int main(){
    int n, k;
    cin>>n>>k;
    int m,v;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>jew[i].X>>jew[i].Y;
    }
    int c;
    for(int i=0;i<k;i++){
        cin >> c;
        bag.push_back(c);
        
    }
    sort(jew+1,jew+n+1);
    sort(bag.begin(), bag.begin()+k);
    int idx = 1;
    for(int i=0;i<k;i++){
        for(int j=idx;j<=n;j++){
            if(jew[j].X<=bag[i]){
                value.push(jew[j].Y);
                //cout<<jew[j].X<<' ';
                idx++;
            }
            else break;
        }
        if(!value.empty()){
            sum+=value.top();
            value.pop();
        }
    }
    
    
    
    cout<< sum;
}