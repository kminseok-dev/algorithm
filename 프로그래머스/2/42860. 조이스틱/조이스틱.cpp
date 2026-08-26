#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int len = name.length();
    int base = 'A';
    
    int move = len;
    for(int i=0;i<len;i++){
        answer += name[i]-base<=13? name[i]-base:26+base-name[i];
        int cursor = i+1;
        while(cursor<len&&name[cursor]=='A')cursor++;
        move = min(move, min(2*i+len-cursor, i+2*(len-cursor)));
    }

    return answer+move;
}