/*
4949. 균형잡힌 세상 [스택]
9012번의 확장판
입력으로 주어진 괄호 문자열이 쌍을 이루는지를 판단해서 결과를 YES나 NO로 나타내기
( 이거랑 ) 이게 주어짐
(()()) 이런 식

와 생각보다 오래 걸렸다. 8번 제출을 통해 맞았다.
이유는.... 지문에서 총 길이가 100이라고 했는데, 100 + null문자  + . 해서 102로 fgets를 받아야 했다.
. 가 100개에 포함되지 않는 것인가 보다..!


*/

#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

char testset[102];
vector<int> ans;

int main(){
    int num;
    int count;
    

    while(1){
        stack<char> st;
        //scanf("%s",testset);
        fgets(testset,102,stdin);
        //fgets를 쓰면, 끝의 개행까지 포함해서 저장. 그래서 없애버림.
        testset[strlen(testset)-1] = 0;
        //printf("%d\n",strlen(testset));
        count = 0;
        //printf("%s\n",testset);
        if(strcmp(testset,".")==0)break;
        //printf("%d %d\n",testset[0],testset[1]);
        
        while(1){
            if(testset[count]==0 ) {
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
            else if(testset[count]=='['){
                st.push('[');
                //puts("pushed ( ");
            }
            else if(testset[count] ==']'){
                //뺄것이 없음 짝 안맞음
                if(st.empty()==true){
                    ans.push_back(0); //NO
                   // puts("there's more )");
                    break;
                }
                // 가장 겉에 것이랑 짝 안맞음
                if(st.top()!='['){
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
        if(ans[i]==1) puts("yes");
        else puts("no");
    }
}