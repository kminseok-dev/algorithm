#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long,vector<long long>,greater<long long>> q;
    for(int s:scoville){
        q.push(s);
    }
    int len = scoville.size();
    int cnt = 0;
    while(len-- > 1){
        long long first = q.top();q.pop();
        if(first>=K){return cnt;}
        long long second = q.top(); q.pop();
        q.push(first+(second*2));
        cnt++;


    }
    if(q.top()>=K) return cnt;
    return -1;
    
}