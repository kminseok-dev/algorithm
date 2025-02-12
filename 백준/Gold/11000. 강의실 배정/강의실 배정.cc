#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> >Class;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int S,T, n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin >> S >> T;
        Class.push_back(make_pair(S,T));
    }

    sort(Class.begin(),Class.end());
   
    for(int i=0;i<Class.size();i++){
            pq.push(Class[i].Y);
            if(pq.top()<=Class[i].X){
                pq.pop();
            }
    }
                
            
        
    
    cout<<pq.size();
     return 0;
}

