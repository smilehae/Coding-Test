#include<iostream>
#include<utility>
#include<queue>

using namespace std;

//바킹독님 강의의 네모판 : 0,0 위치와 이어진 모든 값 검출!
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

 bool vis[502][502]; //방문 여부 : 처음 0
 int n=7, m=10;
 int dx[4]={1,0,-1,0}; // dx dy의 0 1 2 3이 차례대로 오른쪽 위쪽 왼쪽 아래쪽
 int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>>Q;
    //0,0을 넣음
    vis[0][0]=1;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        pair<int,int>cur = Q.front(); Q.pop();
        cout<<"("<<cur.first<<" , "<<cur.second<<") ->";
        //상하좌우의 값을 봐서, 범위 안에 있고, 아직 방문하지 않은 0이 있으면 방문하고 큐에 추가
        for(int dir=0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if(nx<0 || nx >= n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny]!=1) continue;
            vis[nx][ny] = 1;
            Q.push(make_pair(nx,ny));
        }
    }
}