#include<cstdio>
#include<queue>
#include<utility>

///bfs - 이웃한 값 queue에 넣기
using namespace std;

int board[500][500];
int visit[500][500];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;

int cnt=0;
int mx=0; //area 크기 최대
int siz=0; //각각 내부 area 크기 재는 용

queue<pair<int,int>> Q;

void bfs(pair<int,int> mypair){
    //처음 위치 방문했다고 표시하고 큐에 넣기
    visit[mypair.first][mypair.second]=1;
    Q.push(mypair);
    siz=1;
    printf("starting new bfs starting at (%d %d)\n",mypair.first,mypair.second);
    while(!Q.empty()){
        //큐에 있는거 하나 꺼내서, 상하좌우 확인 후 넣기
        pair<int,int>cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first+dx[dir];
            int ny= cur.second+dy[dir];
            if(nx<0||nx>=m || ny<0 ||ny>=n)continue;
            if(visit[nx][ny] || board[nx][ny]==0) continue;
            visit[nx][ny]=1;
            Q.push(make_pair(nx,ny));
            siz++;
            printf("pushing (%d %d) to queue.\n",nx,ny);
            
        }
    }
    cnt++;
    if(mx < siz){
        printf("changing max from %d to %d\n",mx,siz);
        mx = siz;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&board[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[j][i]==1 && visit[j][i]==0){
                bfs(make_pair(j,i));
            }
        }
    }

    printf("%d\n",cnt);
    printf("%d\n",mx);


    

}