#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int cnt = 1;
    int num = 0;
    int totalWeights = truck_weights[num];
    queue<int>q;
    q.push(num);
    while(!q.empty()){
        cnt++;
        if(cnt>bridge_length){
            if(q.front()!=-1) totalWeights-=truck_weights[q.front()];
            q.pop();
        }
        if(num<truck_weights.size()-1){
            if(totalWeights+truck_weights[num+1]<=weight){
                num++;
                q.push(num);
                totalWeights+=truck_weights[num];  
                cout << cnt << " " << num << " " << totalWeights << '\n';
                continue;
            }
            q.push(-1);
        }
        
        
    }
    return cnt;
}