/*
1874 스택 수열 [스택]
스택에 push 하는 순서는 오름차순을 지킨다. 
주어진 수열을 스택을 이용할 수 있는지, 있다면 어떤 순서로 push pop?

1 2 3 4 5 6 7 8

4 3 6 8 7 5 2 1



1 2 3 4 5
3 5 4 2 1

push pop 값을 저장하는 배열 생성.
1부터 스택에 push.
값 입력받기
해당 값과 같은 값이 나오면 pop

스택에 1 push

[반복]
값 입력받기
top을 봤을때 값이 같으면 pop
값 > top이면 push count
아니면 NO

*/
#include<cstdio>
#include<stack>

using namespace std;

char ans[200001];

int main(){
    int count=0;
    int num;
    int value;
    int mainNum = 1;
    bool fail = false;
    //stack 만들어서 1 미리 넣어놓음
    stack<int> st;
    st.push(1);
     ans[count++] = '+';

    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&value);
    
        while(1){
            if(st.empty()==true){
                 st.push(++mainNum);
                 ans[count++] = '+';
              //  printf("pushed %d\n",mainNum);
            }
            if(st.top()==value){
              // printf("poped %d\n",st.top());
               ans[count++] = '-';
                st.pop();
                break;
            }
            else if(value > st.top()){
                st.push(++mainNum);
                ans[count++] = '+';
               // printf("pushed %d\n",mainNum);
            }
            else {
                fail = true;
                //printf("top is bigger than value. NO\n");
                break;
            }
            
        }
       
    }
    //puts("fin!");

    if(!fail){
        for(int i=0;i<count;i++){
        printf("%c\n",ans[i]);
        }
    }
    else{
        printf("NO");
    }
    
}