#include <bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
#define X first
#define Y second


using namespace std;
bool N_vis[101][101];
bool P_vis[101][101];
char Ncolor[101][101];
char Pcolor[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,Psec_num=0,Nsec_num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>Ncolor[i][j];
            Pcolor[i][j]=Ncolor[i][j];
            if(Pcolor[i][j]!='B')Pcolor[i][j]='R';
           // cout<<Pcolor[i][j]<<' ';
        }
        //cout<<'\n';
    }
    queue<pair<int,int> > N_sector;
    queue<pair<int,int> > P_sector;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!N_vis[i][j]){
                N_sector.push(mk(i,j));
                N_vis[i][j] = true;
                Nsec_num++;
                        //cout<<i<<' '<<j<<'\n';
            }
            if(!P_vis[i][j]){
                P_sector.push(mk(i,j));
                P_vis[i][j] = true;
                //cout<<i<<' '<<j<<'\n';
                Psec_num++;
            }
            while(!N_sector.empty()){
                pair<int,int> Ncur = N_sector.front();
                N_sector.pop();
                for(int i=0;i<4;i++){
                    //cout<< cur.X<<' '<<cur.Y<<'\n';
                    int Nnx = Ncur.X + dx[i];
                    int Nny = Ncur.Y + dy[i];
                    if(Nnx<1 || Nny<1 || Nnx>n || Nny>n) continue;
                    if(N_vis[Nnx][Nny]) continue;
                    if(Ncolor[Ncur.X][Ncur.Y]==Ncolor[Nnx][Nny]){
                        N_vis[Nnx][Nny]=true;
                        //cout<<'-'<<nx<<' '<<ny<<'\n';  
                        N_sector.push(mk(Nnx,Nny));
                    }
                   
                }
            }
            while(!P_sector.empty()){
                pair<int ,int> Pcur = P_sector.front();
                P_sector.pop();
                for(int i=0;i<4;i++){
                    int Pnx = Pcur.X + dx[i];
                    int Pny = Pcur.Y + dy[i];
                    if(Pnx<1 || Pny<1 || Pnx>n || Pny>n) continue;
                    if(P_vis[Pnx][Pny]) continue;
                    if(Pcolor[Pcur.X][Pcur.Y]==Pcolor[Pnx][Pny]){
                        P_vis[Pnx][Pny]=true;
                        //cout<<'-'<<Pnx<<' '<<Pny<<'\n';  
                        P_sector.push(mk(Pnx,Pny));
                    }
                }
            }
        }
    }
    cout<<Nsec_num <<'\n';
    cout<<Psec_num;
    return 0;
}