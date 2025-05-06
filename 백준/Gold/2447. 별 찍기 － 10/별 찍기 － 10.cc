#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> dotBoard;
void star(vector<vector<bool>>&dotBoard,int n,int x,int y){
    if(n==1){
        
        dotBoard[x][y] = true; 
        
        return;
    }
    
    star(dotBoard,n/3,x,y);
    star(dotBoard,n/3,x,y+n/3);
    star(dotBoard,n/3,x,y+2*n/3);
    star(dotBoard,n/3,x+n/3,y);
    star(dotBoard,n/3,x+n/3,y+2*n/3);
    star(dotBoard,n/3,x+2*n/3,y);
    star(dotBoard,n/3,x+2*n/3,y+n/3);
    star(dotBoard,n/3,x+2*n/3,y+2*n/3);
    
    return;
    
}
int main(){
    int n;
    cin >> n;
    dotBoard = vector<vector<bool>>(n+1,vector<bool>(n+1,false));
    star(dotBoard,n,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dotBoard[i][j]==false){
                cout<<' ';
                continue;
            }
            else
            cout<<"*";
        }
        cout<<'\n';
    }
    return 0;

}