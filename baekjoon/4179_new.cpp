#include<iostream>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

int board[1001][1001];
int player[1001][1001];

//벽 : -3
//플레이어 -2
//지나갈 수 있는 공간 -1



queue<pair<int,int>> fireQueue;
queue<pair<int,int>> playerQueue;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int minimum = -1;

int main(){
    int r,c;
    cin>>r>>c;
    for(int i=0;i<1001;i++){
        fill(board[i],board[i]+1001,-1);
        fill(player[i],player[i]+1001,-1);
    }

    for(int i=0;i<r;i++){
        string str;
        cin>>str;
        for(int j=0;j<c;j++){
            if(str[j]=='#'){
                board[i][j]=-3;
                player[i][j]=-3;
            }
            else if(str[j]=='J'){
                board[i][j]=0;
                player[i][j]=0;
                playerQueue.push(make_pair(i,j));
            }
            else if(str[j]=='F'){
                board[i][j]=0;
                 player[i][j]=0;
                fireQueue.push(make_pair(i,j));

            }

        }
    }
//cout<<"now fire's turn\n";

    while(!fireQueue.empty()){
        pair<int,int>cur = fireQueue.front();fireQueue.pop();
      //  cout<<"seeking from "<<cur.second<<", "<<cur.first<<"\n";

        for(int i=0;i<4;i++){
            int nx = cur.second+dx[i];
            int ny = cur.first+dy[i];
            if(nx<0 || nx>=c||ny<0 || ny>=r) continue;
            if(board[ny][nx]!=-1)continue;
            board[ny][nx] = board[cur.first][cur.second]+1;
            fireQueue.push(make_pair(ny,nx));
         //   cout<<"visiting ( "<<nx<<" , "<<ny<<") time "<<board[ny][nx]<<"\n";
        }
    }
//cout<<"now player's turn\n";
    while(!playerQueue.empty() ){
         pair<int,int>cur = playerQueue.front();playerQueue.pop();
            if(cur.second==0 || cur.first==0 || cur.second==c-1||cur.first==r-1){
                minimum = player[cur.first][cur.second];
                cout<<minimum+1;
                return 0;
            }
       // cout<<"seeking from "<<cur.second<<", "<<cur.first<<"\n";

        for(int i=0;i<4;i++){
            int nx = cur.second+dx[i];
            int ny = cur.first+dy[i];
            if(nx<0 || nx>=c||ny<0 || ny>=r) continue;
            if(player[ny][nx]!=-1)continue;
            //cout<<"player time "<<player[cur.first][cur.second]+1<<" //fire time"<<board[ny][nx]<<"\n";
            if(player[cur.first][cur.second]+1 >=board[ny][nx] && board[ny][nx]!=-1)continue;
            player[ny][nx] = player[cur.first][cur.second]+1;
            playerQueue.push(make_pair(ny,nx));
           // cout<<"visiting ( "<<nx<<" , "<<ny<<")\n player time "<<player[ny][nx]<<" fire time"<<board[ny][nx]<<"\n";
            
            
        }
    }
    
    if(minimum==-1){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<minimum+1;
    }
    
}