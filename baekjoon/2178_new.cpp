#include<iostream>
#include<queue>
#include<string>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[101][101];
int dist[101][101];

queue<pair<int,int>> Q;

int main(){
    int n,m;
    string s;
    cin>>n>>m;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        for(int j=0;j<m;j++){
            if(s[j]=='1') board[i][j]=1;
            else board[i][j]=0;
        }
    }

    dist[0][0]=1;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        pair<int,int>cur = Q.front();Q.pop();
        for(int i=0;i<4;i++){
           int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 || nx > m | ny<0 || ny > n)continue;
            if(board[ny][nx]!=1 || dist[ny][nx]!=0)continue;
            dist[ny][nx] = dist[cur.second][cur.first]+1;
            Q.push(make_pair(nx,ny));
    
         }
    }
    cout<<dist[n-1][m-1];


}