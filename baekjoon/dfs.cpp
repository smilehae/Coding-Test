#include<iostream>
#include<utility>
#include<stack>

using namespace std;

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
 
bool vis[502][502];
int n=7,m=10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<int,int>> S;
    vis[0][0]=1;
    S.push(make_pair(0,0));
    while(!S.empty()){
        pair<int,int> cur = S.top(); S.pop();
        cout<<"("<<cur.first<<","<<cur.second<<")->";
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 || nx>=n ||ny<0 ||ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny]!=1) continue;
            vis[nx][ny]=1;
            S.push(make_pair(nx,ny));
        }
    }

}