#include <iostream>
#include <vector>
#include <utility>

#define FOR(i,j) for(int i=0;i<j;i++)

using namespace std;

int board[10][10];
vector<pair<int,int>> point;
int p_size;
bool flag;

bool validator(int x, int y, int digit){

    FOR(i,9){
        if(board[x][i]==digit||board[i][y]==digit){
            return false;
        }
    }

    int sectorX = 3*(x/3);
    int sectorY = 3*(y/3);

    for(int i=sectorX;i<sectorX+3;i++){
        for(int j=sectorY;j<sectorY+3;j++){
            if(board[i][j]==digit){
                return false;
            }
        }
    }
    return true;
}

void sudoku(int n){
    if(flag){
        return;
    }

    if(n == p_size){
        FOR(i,9){
            FOR(j,9){
                cout<<board[i][j];
            }
            cout<< '\n';
        }
        flag = true;
    }
    
    int x = point[n].first;
    int y = point[n].second;
    
    for(int i=1;i<=9;i++){
        if(validator(x,y,i)){
            board[x][y] = i;
            sudoku(n+1);
            board[x][y] = 0;
        }
    }
}

void input(){
    string num;
    FOR(i,9){
        cin >> num;
        cin.ignore();
        FOR(j,9){
            board[i][j] = num[j]-'0';
            if(board[i][j]==0){
                point.push_back({i,j});
            }
        }
        
    }
    p_size = point.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    
    sudoku(0);
    return 0;
}