#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(int n,vector<int>& times, long long mid){
    long long total = 0;
    for(auto time : times){
        total += mid / time;
        if(total >= n)return true;
    }
    return total >= n;
}
long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    
    long long h = (long long)(times.back()) * n;
    long long l = (long long)(times.front());
    
    while(l<h){
        long long mid = l + (h-l)/2;
        if(judge(n,times,mid)) h = mid;
        else l = mid+1;
    }
    
    return l;
}