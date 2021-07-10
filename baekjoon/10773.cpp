#include<cstdio>
#include<stack>

/*
백준 10773 - 제로 [스택]
잘못된 수를 부를때마다 0을 외쳐서 최근에 쓴 수를 지ㅏ운다.
수를 받아 적은 후 합 구하기

*/
using namespace std;

int main(){
    int num;
    int sNum;
    
    unsigned long long ans = 0;

    stack<int> st;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&sNum);
        if(sNum!=0){
            st.push(sNum);
        }
        else{
            st.pop();
        }
    }

    while(st.size()!=0){
        ans += (unsigned long long)st.top();
       // printf("added %d\n",st.top());
        st.pop();
    }

    printf("%llu",ans);
}