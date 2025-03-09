#include <bits/stdc++.h>

using namespace std;
queue<int>q;
int R,C,T,ans;
int arr[51][51];
int temp[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void down_move(){
    int idx = q.back();
    for(int i=3;i<=C;i++){
        temp[idx][i] = arr[idx][i-1];
        arr[idx][i-1] = 0;
    }
    for(int i=idx+1;i<=R;i++){
        temp[i][C] = arr[i-1][C];
        arr[i-1][C] = 0;
    }
    for(int i=C-1;i>0;i--){
        temp[R][i] = arr[R][i+1];
        arr[R][i+1] = 0;
    }
    for(int i=R-1;i>=idx;i--){
        if(arr[i][1]==-1){
            temp[i][1]=-1;
            arr[i+1][1] = 0;
            continue;
        }
        temp[i][1] = arr[i+1][1];
        arr[i+1][1] = 0;
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(temp[i][j]!=0){
                arr[i][j] = temp[i][j];
            }
        }
    }
    memset(temp,0,sizeof(temp));
    
    return;
    
}
void up_move(){
    int idx = q.front();
    for(int i=3;i<=C;i++){
        temp[idx][i] = arr[idx][i-1];
        arr[idx][i-1] = 0;

    } 
    for(int i=idx-1;i>0;i--){
        temp[i][C] = arr[i+1][C];
        arr[i+1][C] = 0;

    }
    for(int i=C-1;i>0;i--){
        temp[1][i] = arr[1][i+1];
        arr[1][i+1] = 0;

    }
    for(int i=2;i<=idx;i++){
        if(arr[i][1]==-1){
            temp[i][1]=-1;
            arr[i-1][1] = 0;
            continue;
        }
        temp[i][1] = arr[i-1][1];
        arr[i-1][1] = 0;

    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(temp[i][j]!=0){
                arr[i][j] = temp[i][j];
            }
        }
    }
        
    memset(temp,0,sizeof(temp));
    return;
}
void spread(){
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(arr[i][j]!=0||arr[i][j]!=-1){
                int sp = arr[i][j]/5;
                for(int k=0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx<1 || nx>R | ny<1 || ny>C || arr[nx][ny]==-1)continue;
                    temp[nx][ny] += sp;
                    arr[i][j] -= sp;
                    
                }
                temp[i][j] += arr[i][j];
            }
        }
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            arr[i][j] = temp[i][j];
        }
    }
    memset(temp,0,sizeof(temp));
    return;
}
void solution(int cnt){
    if(cnt == T){
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(arr[i][j]!=-1)ans += arr[i][j];
            }
        }
        return;
    }
    spread();
    up_move();
    down_move();
    solution(cnt+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >> T;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> arr[i][j];
            if(arr[i][j]==-1)q.push(i);
        }
    }
    solution(0);
    cout<<ans;
}   