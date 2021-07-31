#include<cstdio>
#include<utility>
#include<queue>

using namespace std;

int board[1001][1001];
int dist[1001][1001];

queue<pair<int,int>> Q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int mx = 0;


int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            scanf("%d",&board[j][i]);
            if(board[j][i]==-1){
                dist[j][i]= -1;
            }
            //1로 표시된 것들은 큐에 넣어줌
            else if(board[j][i]==1){
                Q.push(make_pair(i,j));
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front();Q.pop();
     // printf("poped (%d,%d) distance %d\n",cur.first,cur.second,dist[cur.second][cur.first]);
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 ||nx>=m || ny<0 ||ny>=n) continue;
            if(dist[ny][nx] != 0 || board[ny][nx]==1) continue;
            dist[ny][nx] = dist[cur.second][cur.first]+1;
            if(dist[ny][nx] > mx) mx = dist[ny][nx];
          //printf("visiting (%d %d) distance %d\n",nx,ny,dist[ny][nx]);
            Q.push(make_pair(nx,ny));

        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
          if(board[j][i]!=1 && dist[j][i]==0 ){
              mx = -1;
          }
        }
    }
    

    printf("%d\n",mx);




   
}