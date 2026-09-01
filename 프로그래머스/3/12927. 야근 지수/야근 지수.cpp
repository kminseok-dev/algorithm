#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool isFeasible(vector<int>& works, int n, int mid){
    long long total = 0;
    for(int work : works){
        total += max(work - mid,0);
        if(total>n)return false;
    }
    return true;
}
long long solution(int n, vector<int> works) {
    long long totalWork = 0;
    for (int w : works) totalWork += w;
    if (totalWork <= n) return 0;
    long long answer = 0;
    sort(works.begin(),works.end());
    
    int st = 0;
    int en = works.back();
    
    while(st<en){
        int mid = (st+en)/2;
        if(isFeasible(works,n,mid)){
            en = mid;
        }
        else{
            st = mid + 1;
        }
    }
    auto it = upper_bound(works.begin(),works.end(),st);
    int cnt = works.end() - it;
    long long total = 0;
    for(auto iter=it;iter!=works.end();iter++){
        total += (*iter) - st;
    }
    long long remain = n - total;
    
    for(auto iter=works.begin();iter!=it;iter++){
        answer += (long long) (*iter) * (*iter);
    }
    answer += remain * (long long)(st-1)*(st-1);
    answer += (cnt-remain)*(long long)st*st;
    
    return answer;
}