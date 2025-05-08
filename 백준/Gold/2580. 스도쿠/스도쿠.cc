#include<bits/stdc++.h>

using namespace std;
int arr[10][10];
int board[10][10];
vector<int> digit;
vector<pair<int,int>> point;
bool flag;
bool check(int x,int y,int d){
    
    for(int i=0;i<9;i++){
        if(arr[x][i] == d||arr[i][y] == d){
           return false;
        }
    }
    int section_x = x/3;
    int section_y = y/3;

    for(int i=3*section_x;i<3*section_x+3;i++){
        for(int j=3*section_y;j<3*section_y+3;j++){
            if(arr[i][j]==d){
                return false;
            }
        }
    }
    return true;
    

}
void sudoku(int cur){
    if(flag == true ){return;}
    if(cur == point.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<arr[i][j]<<' ';
            }
            cout<<'\n'; 
        }
        flag = true;
    }

    else{
        
        int nx = point[cur].first;
        int ny = point[cur].second;
        for(int i=1;i<=9;i++){
            if(check(nx,ny,i)){
                arr[nx][ny] = i;
                sudoku(cur+1);
                arr[nx][ny] = 0;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> a;
            if(a==0){
                point.push_back({i,j});
            }
            arr[i][j] = a;
        }
    }
    
    sudoku(0);
    return 0;
}