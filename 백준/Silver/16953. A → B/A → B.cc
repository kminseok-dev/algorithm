#include <iostream>
#include <queue>

using namespace std;

queue<pair<long,long>> q;
long op[2] = {1,2};

int main(){
    long start, target, result = 2e9;

    cin >> start >> target;

    q.push({start,0});

    while(!q.empty()){
        long cur = q.front().first;
        long cnt = q.front().second;
        
        
        q.pop();
        long newCur;

        for(long i=0;i<2;i++){
            long newCnt = cnt;
            
            
            if(op[i]==2){
                
                newCur = cur * 2;
                
            }
            else{
                
                newCur = cur * 10 + 1;
                
            }

            if(newCur > target){
                continue;
            } 
            newCnt++;
            
            if(newCur == target && newCnt < result) {
                result = newCnt;
                continue;
            }
          
            q.push({newCur,newCnt});
        }
    }
    if(result == 2e9){
        cout<< -1;
        return 0;
    }
    
    cout << result + 1;
    return 0;

}



