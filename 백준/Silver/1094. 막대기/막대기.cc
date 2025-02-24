#include<iostream>
#include<bitset>
using namespace std;
int main() {
    int X;
    int cnt = 0;
    cin >> X;
    bitset<8> bit = X;
    
    for(int i = 0; i<8; i++){
        if(bit[i] == 1)
            cnt++;
    }
    cout << cnt << endl;
    return 0;



}
