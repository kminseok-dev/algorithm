#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt=0;

void dfs( vector<int> v, int index, int result,int target){
    if(index == v.size()){
        if(result == target){
            cnt++;
             
        }
        return;
    }
    int pos = v[index];
    int neg = -1*v[index];
    dfs(v,index+1,result+pos,target);
    dfs(v,index+1,result+neg,target);
    
          
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers,0,0,target);
    answer = cnt;
    return answer;
}