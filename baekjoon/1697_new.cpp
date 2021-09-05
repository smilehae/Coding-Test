#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[100002];
queue<int> Q;

int main(){
    int n,k;
    cin>>n>>k;
    fill(board,board+100002,-1);


    board[n]=0;
    Q.push(n);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        //cout<<"start from "<<cur<<"\n";
        int next = cur+1;
        if(cur==k){
           // cout<<"founded in "<< board[cur];
           cout<<board[cur];
            break;
        }
        if(next<100002 &&next>=0&& board[next]==-1 ){
            board[next] = board[cur]+1;
            Q.push(next);
          //  cout<<"visiting "<<next<<" count"<< board[next]<<"\n";
        }
        next = cur-1;
        if(next<100002 &&next>=0&& board[next]==-1 ){
            board[next] = board[cur]+1;
            Q.push(next);
          //  cout<<"visiting "<<next<<" count"<<  board[next]<<"\n";
        }
        next = cur*2;
        if(next<100002 &&next>=0&& board[next]==-1 ){
            board[next] = board[cur]+1;
            Q.push(next);
          //  cout<<"visiting "<<next<<" count"<<  board[next]<<"\n";
        }
    }

}