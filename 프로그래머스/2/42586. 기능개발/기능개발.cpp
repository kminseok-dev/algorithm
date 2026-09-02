#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain(progresses.size());
    for(int i=0;i<remain.size();i++){
        int day = (100-progresses[i]) % speeds[i] == 0 ? 0 : 1 ;
        remain[i] = (100-progresses[i])/speeds[i] + day;
        
    }
    int base = remain.front();
    int cnt = 1;
    for(int i=1;i<remain.size();i++){
        if(base>=remain[i])cnt++;
        else {
            answer.push_back(cnt);
            base = remain[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}