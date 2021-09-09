#include <string>
#include <vector>
#include <iostream>

using namespace std;


int board[502][502];

void turnRight(pair<int,int>& dir){
    if(dir.first==0){
        dir.second*=-1;
    }
    int temp = dir.first;
    dir.first = dir.second;
    dir.second = temp;
    return;
}

void turnLeft(pair<int,int>& dir){
    if(dir.first!=0){
        dir.first*=-1;
    }
    int temp = dir.first;
    dir.first = dir.second;
    dir.second = temp;
    return;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int rowMax = grid.size();
    int colMax = grid[0].size();
   
    //입력 넣기
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='S'){
                board[i][j]=1;
            }
            else if(grid[i][j]=='L'){
                board[i][j]=2;
            }
            else if(grid[i][j]=='R'){
                board[i][j]=3;
            }
        }
    }

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[4]; //방문해본 방향 저장.

pair<int,int> firstPos={0,0};
pair<int,int> pos={0,0};

for(int i=0;i<4;i++){
    //이미 출발해본 곳이면 패스.
    if(vis[i]==1)continue;
    cout<<"starting from "<<dx[i]<<","<<dy[i]<<"\n";

    pair<int,int> firstDir={dx[i],dy[i]};
    pair<int,int> dir=firstDir;
    vis[i]=1;

    int count=0;
    while(count<20){
        pos.first += dir.first;
        pos.second += dir.second;
        if(pos.first== colMax ) pos.first = 0;
        if(pos.first<0) pos.first = colMax-1;
        if(pos.second==rowMax) pos.second = 0;
        if(pos.second<0) pos.second= rowMax-1;
       cout<<"cur position is ("<<pos.first<<" , "<<pos.second<<") in turn"<<count+1<<"\n";
        if(board[pos.second][pos.first]==1){
          //  cout<<"meeting S. go straight";
        }
        if(board[pos.second][pos.first]==2) {
           // cout<<"meeting L. turnLeft";
            turnLeft(dir);
            }
        else if(board[pos.second][pos.first]==3) {
           // cout<<"meeting R. turnRight";
            turnRight(dir);
            }
        //위치가 0,0이고 발사한 방향은 더 가지 않도록 저장.
        if(pos.first==0 && pos.second==0){
            if(dir.first==0 && dir.second==1)vis[0]=1;
            else if(dir.first==1 && dir.second==0) vis[1]=1;
            else if(dir.first==0 && dir.second==-1) vis[2]=1;
            else vis[3]=1;
            cout<<"this pos is 0,0. making direction visited\n";
        }

        count++;
        //cout<<" dir : "<<dir.first<<","<<dir.second<<"\n";
        if(firstPos==pos && firstDir==dir){
            //cout<<"finished loop\n";
            answer.push_back(count);
            break;
        }
    }
   
}

    return answer;
}

int main(){
    vector<string> myGrid={"SL","LR"};
    vector<int>answer = solution(myGrid);
    for(int elem: answer){
        cout<<elem<<" ";
    }
}