#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int,int> result = {0,0};
vector<int> remain;

void deploy(int idx,int maxLength){
    queue<int> q;
    int base = remain[idx];
    q.push(base);
    for(int i=idx+1;i<maxLength;i++){
        if(base>=remain[i]){
            q.push(remain[i]);
        }
        else{
            result.first = q.size();
            result.second = i;
            return;
        }
    }
    result.first = q.size();
    result.second = maxLength;
    return;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int maxLen = progresses.size();
    for(int i=0;i<maxLen;i++){
        int amount = 100 - progresses[i];
        if(amount%speeds[i]!=0){
            remain.push_back(amount / speeds[i] + 1);
        }
        else
            remain.push_back(amount / speeds[i]);
    }
    
    int idx = 0;
    int maxLength = progresses.size();
    while(1){
        if(idx==maxLen){
            break;
        }
            deploy(idx,maxLength);
            answer.push_back(result.first);
            idx = result.second;
        
    }
    
    
    
    return answer;
}