#include <bits/stdc++.h>
using namespace std;

int num[1025];
vector<vector<int> >depthlevel;



void depth(int idx, int parentidx, int size, int level){
    if(level>=depthlevel.size())depthlevel.resize(level+2);
    if(parentidx==idx+1||size==parentidx+1){
        depthlevel[level].push_back(num[parentidx-1]);
        depthlevel[level].push_back(num[parentidx+1]);
        return;
    }
    
    int nodeidx1 = (idx+parentidx-1)/2;
    int nodeidx2 = (parentidx+size+1)/2;
    depthlevel[level].push_back(num[nodeidx1]);
    depthlevel[level].push_back(num[nodeidx2]);
    depth(idx,nodeidx1,parentidx-1,level+1);
    depth(parentidx+1,nodeidx2,size,level+1);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int k;
    cin >> k;
    int nodeNum = pow(2,k)-1; 
    
    depthlevel.resize(k+1);
    for(int i=0;i<nodeNum;i++)cin>>num[i];
    depthlevel[0].push_back(num[nodeNum/2]);
    depth(0,nodeNum/2,nodeNum,1);
    cout<<depthlevel[0][0]<<'\n';
    for(int i=1;i<depthlevel.size();i++){
        for(int node:depthlevel[i])cout<<node<<' ';
        cout<<'\n';
    }
    return 0;
}