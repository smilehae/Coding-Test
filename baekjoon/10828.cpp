#include<iostream>
#include<cstring>
#include<stack>
//스택 문제
/*
10828번
정수를 저장하는 스택을 구현하여 입력으로 주어지는 명령 처리
push pop size empty top
*/

using namespace std;


int main(){
    int num;
    int tempNum;
    char order[10];
    stack<int> stack;
    int count = 0;
    int ans[10000];

    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",order);
       if(strcmp(order,"push")==0){
           scanf("%d",&tempNum);
           stack.push(tempNum);
            
       }
       else if(strcmp(order,"top")==0){
           if(stack.size()!=0){
               ans[count]=stack.top();
           }
           else{
               ans[count]=-1;
           }
           count++;
       }
       else if(strcmp(order,"size")==0){
          ans[count]=stack.size();
          count++;
       }
       else if(strcmp(order,"empty")==0){
          if(stack.size()==0) ans[count]=1;
          else ans[count] = 0;
          count++;
       }
       else if(strcmp(order,"pop")==0){
            if(stack.size()==0)ans[count]=-1;
            else{
                ans[count]=stack.top();
                stack.pop();
            }
            count++;
       }
    }
    
    for(int i=0;i<count;i++){
        printf("%d\n",ans[i]);
    }
}