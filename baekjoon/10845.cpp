#include<cstdio>
#include<queue>
#include<cstring>


int main(){
    int n;
    std::queue<int> Q;    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char order[10];
        scanf("%s",order);
        if(strcmp(order,"push")==0){
            int number;
           scanf("%d",&number);
            Q.push(number);
        }
        else if(strcmp(order,"pop")==0){
            if(Q.empty()){
                puts("-1");
            }
            else{
                printf("%d\n",Q.front());
                Q.pop();
            }
        }
        else if(strcmp(order,"size")==0){
            printf("%d\n",Q.size());
        }
        else if(strcmp(order,"front")==0){
            if(Q.empty()){
                puts("-1");
            }
            else{
              printf("%d\n",Q.front());
            }
        }
         else if(strcmp(order,"back")==0){
            if(Q.empty()){
                puts("-1");
            }
            else{
              printf("%d\n",Q.back());
            }
        }
        else if(strcmp(order,"empty")==0){
            if(Q.empty())puts("1");
            else puts("0");
        }

    }

}