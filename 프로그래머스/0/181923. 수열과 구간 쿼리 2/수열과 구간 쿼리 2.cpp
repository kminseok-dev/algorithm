#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i=0;i<queries.size();i++){
        int found = -1;
        for(int j=queries[i][0];j<=queries[i][1];j++){
            if(arr[j] > queries[i][2]){
                if(found==-1 || arr[j]<found)
                    found = arr[j];
            }
        }
        answer.push_back(found);
    }

    
    return answer;
}