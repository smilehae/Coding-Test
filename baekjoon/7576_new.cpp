#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int m,n;

int board[1001][1001];
int time[1001][1001];

int dx[4]={1,0,-1,0};
int dy[4]= {0,1,0,-1};
int maxTime = 0;

queue<pair<int,int>> Q;

void showBoard(){
     cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void showTime(){
     cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<time[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


int main(){
    cin>>m>>n;

    for(int i=0;i<1001;i++){
        fill(time[i],time[i]+1001,-1);
    }

//board에 값 다 입력하고, time세팅 & Queue에 값 넣기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==-1){
                time[i][j]=-2; //빈공간 있을 시 -2 표시.
            }
            else if(board[i][j]==1){
                Q.push(make_pair(i,j));
                time[i][j]=0; //바로 완료된거니까 0초
               // cout<<"pushed "<<i<<" , "<<j<<"\n";
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front();Q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.second+dx[i];
            int ny = cur.first+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(board[ny][nx] !=0 || time[ny][nx]!=-1)continue;
            time[ny][nx] = time[cur.first][cur.second]+1;
            //cout<<"visited "<<ny<<" , "<<nx<<"\n";
            Q.push(make_pair(ny,nx));
           // cout<<"time in "<<ny<<" , "<<nx<<"is "<<time[ny][nx]<<"\n";
            if(time[ny][nx]>maxTime){ 
                maxTime = time[ny][nx];
               // cout<<"changing max time to "<<maxTime<<"\n";
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(time[i][j]==-1){
                maxTime=-1;
            }
        }
    }


    cout<< maxTime;


}