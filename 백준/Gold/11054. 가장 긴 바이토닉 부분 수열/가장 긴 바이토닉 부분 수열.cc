#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int sequence[1005][4];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >>  sequence[i][1];
        sequence[i][2] = 1;
        sequence[i][3] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(sequence[j][1]<sequence[i][1]){
                if(sequence[j][2]>=sequence[i][2]){
                    sequence[i][2] = sequence[j][2] + 1;
                }

            }
        }
        
    }
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>i;j--){
            if(sequence[j][1]<sequence[i][1]){
                if(sequence[j][3]>=sequence[i][3]){
                    sequence[i][3] = sequence[j][3] + 1;
                }
            }
        }
    }
    int maxLength = 0;

    for(int i=1;i<=n;i++){
        maxLength = max(maxLength,sequence[i][2]+sequence[i][3]);
    }
    cout << maxLength -1 ;
    return 0;




}