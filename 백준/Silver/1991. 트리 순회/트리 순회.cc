#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

map<char ,pair<char,char> >m;
char node;
void preO(char node){
    if(node == '.') return;
    cout<<node;
    preO(m[node].X);
    preO(m[node].Y);
}
void inO(char node){
    if(node == '.') return;
    inO(m[node].X);
    cout<<node;
    inO(m[node].Y);
}

void postO(char node){
    if(node == '.') return;
    postO(m[node].X);
    postO(m[node].Y);
    cout<<node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)cin>>node>>m[node].X>>m[node].Y;
    preO('A');
    cout<<'\n';
    inO('A');
    cout<<'\n';
    postO('A');
    cout<<'\n';
    
    return 0;
}