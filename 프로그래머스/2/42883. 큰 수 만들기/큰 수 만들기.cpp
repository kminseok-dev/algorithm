#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
//     int idx = -1;
//     string answer = "";
//     int originalLen = number.size() - k;
//     int copyLen = originalLen;
//     while(answer.size()<originalLen){
//         int num = 0;
//         for(int i=idx+1;i<number.size()-copyLen+1;i++){
//             if(num<number[i]-'0'){
//                 num = number[i]-'0';
//                 idx = i;
//             }
//         }
//         answer += to_string(num);
//         copyLen--;
//     }
    
    
    
//     return answer;
    string answer = "";
    int len = number.size() - k;
    stack<char> s;
    for(int i=0;i<number.size();i++){
        while(!s.empty()&&s.top()<number[i]&&k>0){
            s.pop();
            k--;
        }
        s.push(number[i]);
    }
    
    while(!s.empty()){
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(),answer.end());
    answer = answer.substr(0,len);
    return answer;
}