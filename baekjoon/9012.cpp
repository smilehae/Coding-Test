/*
9012. 괄호 [스택]
입력으로 주어진 괄호 문자열이 쌍을 이루는지를 판단해서 결과를 YES나 NO로 나타내기
( 이거랑 ) 이게 주어짐
(()()) 이런 식

내 풀이
처음 들어오는것이 )면 NO  return
(가 들어오면 스택에 하나 넣고 )에 들어오면, 이때 
*/

#include<cstdio>
#include<stack>
#include<vector>
#include<string>

using namespace std;

char testset[50];
vector<int> ans;

int main(){
    int num;
    int count;
    scanf("%d",&num);
    // for(int i=0;i<num;i++){
    //     scanf("%s",testset);
    //     count = 0;
    //     while(1){
    //         if(testset[count]=='('){
    //             st.push('(');
    //             printf("pushed (\n");
    //         }
    //         else if(testset[count]==')'){
    //             if(st.empty()==true || st.top()!='('){
    //                 printf("wrong!\n");
    //                 ans.push_back(0);
    //                 break;
    //             }
    //             else{
    //                 st.pop();
    //                 printf("got it!\n");
    //             }
            
    //         }
    //         count++;
    //         if(testset[count]==0){
    //             ans.push_back(1);
    //             break;
    //         }
    //     }
    // }


    for(int i=0;i<num;i++){
        stack<char> st;
        scanf("%s",testset);
        count = 0;
        while(1){
            if(testset[count]==0) {
                //다 끝났는데 스택이 안비어있으면 false
                if(st.empty()==false){
                    ans.push_back(0);//NO
                    //puts("there's more (");
                }
                //다 끝났을떄 스택이 비면 true
                else{
                    ans.push_back(1);//YES
                }
                break;
            }
            if(testset[count]=='('){
                st.push('(');
                //puts("pushed ( ");
            }
            else if(testset[count] ==')'){
                //뺄것이 없음 짝 안맞음
                if(st.empty()==true){
                    ans.push_back(0); //NO
                   // puts("there's more )");
                    break;
                }
                // 가장 겉에 것이랑 짝 안맞음
                if(st.top()!='('){
                    ans.push_back(0);
                   // puts("not matching");
                    break;
                }
                //짝 맞음 : 하나 빼고 다시 확인
                else{
                    st.pop();
                   // puts("poped (");
                }
                
            }

            count++;
        }   
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]==1) puts("YES");
        else puts("NO");
    }
}