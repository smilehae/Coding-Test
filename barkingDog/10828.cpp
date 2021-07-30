#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

int main(){
    int n;
    char order[10]={};
    stack<int> S;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",order);
        if(strcmp(order,"push")==0){
            int num;
            scanf("%d",&num);
            S.push(num);
        }
        else if(strcmp(order,"pop")==0){
            if(S.empty()==true)puts("-1");
            else{
                int top = S.top();
                S.pop();
                printf("%d\n",top);
            }
        }
        else if(strcmp(order,"size")==0){
            printf("%d\n",S.size());
        }
        else if(strcmp(order,"empty")==0){
            if(S.empty()==true)puts("1");
            else puts("0");
        }
        else if(strcmp(order,"top")==0){
            if(S.empty()==true)puts("-1");
            else{
                printf("%d\n",S.top());
            }
        }
    }   
}