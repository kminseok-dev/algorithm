#include <bits/stdc++.h>

using namespace std;

vector<char>arr;
vector<int>temp;
vector<char>op;
bool isused[23];
int num[15];
int n,p,m,mp,d,c,ansmin,ansmax;
void func(int k){
    if(k==n-1){
        temp[c] = num[0];        
        for(int i=0;i<n-1;i++){
            if(arr[i]=='+')temp[c]+=num[i+1];
            else if(arr[i]=='-')temp[c]-=num[i+1];
            else if(arr[i]=='*')temp[c]*=num[i+1];
            else if(arr[i]=='/'){
                if(temp[c]>=0)temp[c]/=num[i+1];
                else temp[c]=-(-temp[c]/num[i+1]);
            }
        }
        if(c==0){ansmin=temp[0];ansmax=temp[0];}
        ansmax=max(temp[c],ansmax);
        ansmin = min(ansmin,temp[c]);
        c++;
        
        return ;
    }
    for(int i=0;i<op.size();i++){
        if(!isused[i]){
            arr[k] = op[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}
int main(){
    cin >> n;
    arr.resize(n-1);
    int size=1;
    for(int i=2;i<=n-1;i++) size*=i;
    temp.resize(size+1);
    for(int i=0;i<n;i++)cin >> num[i];
    cin >> p >> m >> mp >> d;
    
    if(p>0)for(int i=0;i<p;i++)op.push_back('+');
    if(m>0)for(int i=0;i<m;i++)op.push_back('-');
    if(mp>0)for(int i=0;i<mp;i++)op.push_back('*');
    if(d>0)for(int i=0;i<d;i++)op.push_back('/');
    
    func(0);
    cout<< ansmax<<'\n'<<ansmin;
    return 0;
    
}