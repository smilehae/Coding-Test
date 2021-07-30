#include<cstdio>
#include<queue>

///bfs - 이웃한 값 queue에 넣기

int board[500][500];


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&board[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",board[j][i]);
        }
    }
}