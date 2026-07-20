#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    stack<int> st;
    sort(citations.begin(),citations.end());
    int last = citations.back();

    for(int i=1;i<=last;i++){
        int num = 0;
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=i){
                num++;    
            }
        }
        if(i<=num){
            st.push(i);
        }   
    }
    if(!st.empty()){
        return st.top();
    }
    return answer;
}