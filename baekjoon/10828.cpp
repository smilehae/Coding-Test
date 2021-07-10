#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
//스택 문제
/*
10828번
2021.07.10
정수를 저장하는 스택을 구현하여 입력으로 주어지는 명령 처리
push pop size empty top

정답 추출할때
1. 배열 이용->좀 공간낭비 +  count등 쓸모없는 변수
2. 벡터 사용
*/

using namespace std;


int main(){
    int num;
    int tempNum;
    char order[10];
    stack<int> stack;
    vector<int> ans;

    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",order);
       if(strcmp(order,"push")==0){
           scanf("%d",&tempNum);
           stack.push(tempNum);
            
       }
       else if(strcmp(order,"top")==0){
           if(stack.size()!=0){
               ans.push_back(stack.top());
           }
           else{
               ans.push_back(-1);
           }
       }
       else if(strcmp(order,"size")==0){
          ans.push_back(stack.size());
       }
       else if(strcmp(order,"empty")==0){
          if(stack.size()==0) ans.push_back(1);
          else ans.push_back(0);
       }
       else if(strcmp(order,"pop")==0){
            if(stack.size()==0)ans.push_back(-1);
            else{
                ans.push_back(stack.top());
                stack.pop();
            }
       }
    }
    
    vector<int>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        printf("%d\n",*it);
    }
}