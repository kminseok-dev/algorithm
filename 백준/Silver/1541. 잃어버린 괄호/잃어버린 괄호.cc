#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string input;
    cin >> input;
 
    int result = 0;
    string num;
    bool minus = false;
 
    for (int i = 0; i <= input.size(); i++) {
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (minus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
            if (input[i] == '-') {
                minus = true;
            }    
        }
        else {
            num += input[i];
        }
    }
    cout << result;
}