#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int > map(m*n,2e9);
    
    
    

    for(int i=0;i<drops.size();i++){
        map[n*drops[i][0]+drops[i][1]] = i+1;
    }
    int slideN = n-w+1;
    vector<vector<int>> cMin(m,vector<int>(slideN));
    
    for(int i=0;i<m;i++){
        deque<int> dq;
        for(int j=0;j<n;j++){
            while(!dq.empty()&&map[i*n+j]<=map[i*n+dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            
            if(dq.front()<j-w+1){
                dq.pop_front();
            }
            if(j>=w-1){
            
                cMin[i][j-w+1] = map[i*n+dq.front()];
            }
        }
    }

    int slideM = m-h+1;
    
    vector<vector<int>> rMin(slideM,vector<int>(slideN));

    for(int i=0;i<slideN;i++){
        deque<int>dq;
        for(int j=0;j<m;j++){
            while(!dq.empty()&&cMin[j][i]<=cMin[dq.back()][i]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(dq.front()<j-h+1){
                dq.pop_front();
            }
            if(j>=h-1){
                rMin[j-h+1][i] = cMin[dq.front()][i];
            }
        }
    }
    
    int r = 0,c = 0,rain = 0;
    for(int i=0;i<slideM;i++){
        for(int j=0;j<slideN;j++){
            if(rMin[i][j] > rain ||(rMin[i][j] == rain && (i < r || (i == r && j < c)))){
                r=i; c=j; rain=rMin[i][j];
            }
        }
       
    }
    vector<int> answer;
    answer.push_back(r);
    answer.push_back(c);
    return answer;
}