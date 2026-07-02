#include <string>
#include <vector>

using namespace std;
vector<bool> checked(205);
int cnt;
void dfs(int start,vector<vector<int>> computers){
    checked[start] = true;
    for(int i=0;i<computers.size();i++){
        if(computers[start][i]==1&&!checked[i]){
            dfs(i,computers);
        }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++){
        computers[i][i] = -1;
    }
    for(int i=0;i<n;i++){
        if(!checked[i]){
            dfs(i,computers);
            answer++;
        }
    }
    
    
    return answer;
}