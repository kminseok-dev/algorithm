#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end(),compare);
    int cnt = 0;
    int idx = 0;
    
    while(idx<routes.size()){
        int base = routes[idx][1];
        cnt++;
        int next = routes.size();
        for(int i=idx+1;i<routes.size();i++){
            if(base < routes[i][0]){
                next = i;
                break;
            }
        }
        idx = next;
        
    }
    return cnt;
    
}