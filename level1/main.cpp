#include<iostream>
#include<queue>

using namespace std;

int m,n;

int board[1001][1001];
int time[1001][1001];

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


int main(){
    cin>>m>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    



}