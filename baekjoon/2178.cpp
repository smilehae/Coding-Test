#include<cstdio>
#include<utility>
#include<queue>

using namespace std;

int board[100][100];
int visit[100][100];
int dist[100][100];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;


queue<pair<int,int>> Q;


void bfs(pair<int,int> pos){
    visit[pos.second][pos.first]=1;
    dist[pos.second][pos.first]= 1;
   // printf("starting bfs. visiting (%d,%d) distance %d\n",pos.first,pos.second,dist[pos.second][pos.first]);
    
    Q.push(pos);
    while(!Q.empty()){
        pair<int,int>cur=Q.front();Q.pop();
        int preDist = dist[cur.second][cur.first];
       // printf("poped element (%d,%d) distance %d\n",cur.first,cur.second,preDist);
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(board[ny][nx]==0 || visit[ny][nx]) continue;
            visit[ny][nx]=1;
            dist[ny][nx]=preDist+1;
            Q.push(make_pair(nx,ny));
           // printf("visiting (%d,%d) distance is %d\n",nx,ny,preDist+1);

        }
    }
    printf("%d\n",dist[n-1][m-1]);
}

int main(){
    scanf("%d %d",&n,&m);

    //입력 처리해서 board에 저장
    for(int i=0;i<n;i++){
        char oneLine[100];
        scanf("%s",oneLine);
       // printf("this line input: %s\n",oneLine);
        int cnt=0;
        while(oneLine[cnt]!=0){
            if(oneLine[cnt]=='1'){
                board[i][cnt]=1;
              //  printf("putting 1 to board[%d][%d]\n",i,cnt);
            }
            else if(oneLine[cnt]=='0'){
                board[i][cnt]=0;
              //  printf("putting 0 to board[%d][%d]\n",i,cnt);

            }
            else{
                puts("error\n");
            }
            cnt++;
        }
    }

    bfs(make_pair(0,0));



    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         printf("%d ",board[i][j]);
    //     }
    //     puts("");
    // }
}