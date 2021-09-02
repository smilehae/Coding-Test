#include<iostream>
#include<queue>

using namespace std;

int board[502][502];
int vis[502][502];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

int n,m;
int maxSize=0;
int numCount=0;

void showArr(){
    
    for(int j=0;j<n;j++){
        for(int i=0; i<m;i++){
            cout<<board[j][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int bfs(pair<int,int> startPos){
    //cout<<"start at "<<startPos.first<<" , "<<startPos.second<<"\n";

    int count=1;
  vis[startPos.second][startPos.first] = 1;
    Q.push(startPos);
    while(!Q.empty()){
        pair<int,int> cur = Q.front();Q.pop();

        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>m || ny<0 || ny>n) continue;
            if(board[ny][nx]!=1 || vis[ny][nx]!=0) continue;
            vis[ny][nx]=1;
            Q.push(make_pair(nx,ny));
           // cout<<"visiting "<<nx<<" , "<<ny<<"\n";
            count++;
        }
    }
    return count;
}

int main(){
    cin>>n>>m;


    for(int j=0;j<n;j++){
        for(int i=0; i<m;i++){
            cin>>board[j][i];
        }
    }
    

    for(int j=0;j<n;j++){
        for(int i=0; i<m;i++){
            if(board[j][i]==1 && vis[j][i]==0){
                numCount++;
                int newSize=bfs(make_pair(i,j));
                if(newSize>maxSize) maxSize = newSize;
                //cout<<"size is "<<newSize<<"\n";
               // showArr();

            }
        }
    }

    cout<<numCount<<"\n"<<maxSize<<"\n";
  
    



}