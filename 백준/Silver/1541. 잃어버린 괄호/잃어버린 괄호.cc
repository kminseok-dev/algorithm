#include <bits/stdc++.h>

using namespace std;


int calculate(string expr){
    string num = "";
    int sum = 0;
    for(char c:expr){
        if(c=='+'){
            sum += stoi(num);
            num = "";
        }
        else{
            num+=c;
        }
    }
    sum+=stoi(num);
    
    return sum;
}
int main(){
    string input;
    string temp;
    getline(cin,input);
    
    vector<string> a;
    
    int idx = 0;
    for(char c:input){
        if(c=='-'){
            
            a.push_back(temp);
            // op.push_back(c);
            temp = "";
        }
        
        else{
            temp += c;
        }
    }
    a.push_back(temp);
    // for(auto s:a){
    //     cout<<s<<'\n';
    // }
    // cout<<'\n';
    vector<int> result;
    for(auto s:a){
        result.push_back(calculate(s));
    }
    // for(int i=0;i<result.size();i++){
    //     cout << result[i]<<'\n';
    // }
    int ans = result[0];
    
    for(int i=1;i<result.size();i++){
        ans -= result[i];
    }    
    cout << ans;
}