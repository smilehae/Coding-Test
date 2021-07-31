#include<cstdio>
#include<utility>
#include<queue>

int board[100][100];
int visit[100][100];
int dist[100][100];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char oneLine[100];
        scanf("%s",oneLine);
        printf("this line input: %s\n",oneLine);
        int cnt=0;
        while(oneLine[cnt]!=0){
            if(oneLine[cnt]=='1'){
                board[i][cnt]=1;
                printf("putting 1 to board[%d][%d]\n",i,cnt);
            }
            else if(oneLine[cnt]=='0'){
                board[i][cnt]=0;
                printf("putting 0 to board[%d][%d]\n",i,cnt);

            }
            else{
                puts("error\n");
            }
            cnt++;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",board[i][j]);
        }
        puts("");
    }
}