#include<bits/stdc++.h>

using namespace std;

void star(vector<vector<bool>>& board,int n, int x,int y){
    if(n==3){
        board[x][y] = true;
        board[x+1][y-1] = true;
        board[x+1][y+1] = true;
        board[x+2][y-2] = true;
        board[x+2][y-1] = true;
        board[x+2][y] = true;
        board[x+2][y+1] = true;
        board[x+2][y+2] = true;
        return;
    }

    star(board,n/2,x,y);
    star(board,n/2,x+n/2,y-n/2);
    star(board,n/2,x+n/2,y+n/2);
   
}


int main(){
    int n;
    cin >> n;

    vector<vector<bool>> board(n+2,vector<bool>(2*(n+2),false));
    star(board,n,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n;j++){
            if(board[i][j]){
                cout << '*'; 
            }
            else{
                cout << ' ';
            }

        }
        cout << '\n';
    }

    




    
}