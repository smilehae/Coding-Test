#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int,int>> Q;

int board[1002][1002];
int fire[1002][1002];
int escape[1002][1002];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c;

    cin>>r>>c;

    for(int i=0;i<r;i++){
        fill(fire[i],fire[i]+r,-1);
        fill(escape[i],escape[i]+r,-1);
        
    }


    pair<int,int> firePos;
    pair<int,int> startPos;

    bool isEscaped= false;
    int minTime;

    for(int j=0;j<r;j++){
        for(int i=0;i<c;i++){
            char place;
            cin>>place;
            //#으로 처리된 벽을, board의 -1로 처리
            if(place=='#'){
                board[j][i]=-1;
            }
            else if(place=='J'){
                startPos.first=i;
                startPos.second=j;
                
            }
            else if(place=='F'){
                firePos.first=i;
                firePos.second=j;
            }
        }
    }

    // printf("jihoon is in (%d,%d)\n",startPos.first,startPos.second);
    // printf("fire is in (%d,%d)\n",firePos.first,firePos.second);

    //fire bfs돌리기
    fire[firePos.second][firePos.first]=0;
    Q.push(firePos);
    while(!Q.empty()){
        pair<int,int>cur=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx<0||nx>=c||ny<0||ny>=r) continue;
            if(board[ny][nx]==-1||fire[ny][nx]!=-1 ) continue;
            fire[ny][nx] = fire[cur.second][cur.first]+1;
          //  printf("visiting (%d,%d), pos %d\n",nx,ny,fire[ny][nx]);
            Q.push(make_pair(nx,ny));
        }

    }
puts("");
    //지훈 bfs 돌리기
    escape[startPos.second][startPos.first]=0;
    if(startPos.first==c-1 || startPos.second==r-1 || startPos.first==0 || startPos.second==0) {
        isEscaped=true;
        minTime = escape[startPos.first][startPos.second];
        cout<<minTime+1;
        return 0;
        }
    Q.push(startPos);
    while(!Q.empty()){
        pair<int,int>cur=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            //범위 벗어나면 스캅
            if(nx<0||nx>=c||ny<0||ny>=r) continue;
            //벽이거나, 이미 가본 곳이면 스킵
            if(board[ny][nx]==-1||escape[ny][nx]!=-1 ) continue;
            //만약 불이 올 수 있는 곳이면, 불이 오는 타이밍이 탈출시점보다 빠르면 스킵
            if(fire[ny][nx]!=-1){
                if(fire[ny][nx]<=escape[cur.second][cur.first]+1) continue;
            }
            escape[ny][nx]=escape[cur.second][cur.first]+1;
            printf("visiting (%d,%d), pos %d fire %d\n",nx,ny,escape[ny][nx],fire[ny][nx]);
            if(nx==c-1 || ny==r-1 || nx==0 || ny==0) {
                isEscaped=true;
               minTime = escape[ny][nx];
               cout<<minTime+1;
               return 0;
            }
            Q.push(make_pair(nx,ny));
        }
    }

    if(isEscaped){
        cout<<minTime+1;
    }
    else{
        cout<<"IMPOSSIBLE";
    }

    
}