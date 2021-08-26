#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //처음 생각한 풀이 : 막대기가 끝날때마다 미사일을 맞은 갯수를 세보았다. 이렇게 하면 복잡도가 O(N^2)이 나와서 시간 안에 불가. ( 데이터 10000개)
    /*
     string str;
    int total=0;
    cin>>str;
    stack<char> myStack;

    for(int i=0;i<str.size();i++){
        if(str[i]=='(' && str[i+1]==')'){
            str[i]='o';
            str[i+1]='x';
           // std::cout<<"found laser in "<<i<<"\n";
        }
    }
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            myStack.push('(');
           // std::cout<<"found ( in "<<i<<" pushed\n";
        }
        else if(str[i]=='o'){
            myStack.push('o');
           // std::cout<<"found o in "<<i<<" pushed\n";
        }
        else if(str[i]==')'){
            int count = 0;
           // std::cout<<"found ) in "<<i<<"\n";

            while(myStack.top()!='('){
                if(myStack.top()=='o'){
                    count++;
                   // std::cout<<"found o. count became "<<count<<"\n";
                }
                myStack.pop();
            }
            myStack.pop(); // ( 를 빼주기

            for(int j=0;j<count;j++){
                myStack.push('o');
                //std::cout<<"pushing o\n";
            }

            total += (count+1); //한번 자르면 2개로 분할
           // std::cout<<"adding "<<count+1<<"to total.\n";
            
        }
    }
        cout<<total;

      */
    
    //바킹독님 힌트 보고 생각한 풀이 : 미사일을 기준으로 생각. (을 스택에 넣고 ) 나오면 스택에서 꺼내고, 가지갯수 ++. 미사일이 발견되었을때, 그때 있는 스택의 사이즈 만큼 부서짐 수 +. 이 두개를 합치면 된다.
    stack<char> S;
    int stickCount = 0;
    int breakCount = 0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(' && str[i+1]==')'){
           // cout<<"found raser in "<<i<<" breaked "<<S.size()<<"\n";
            breakCount+=S.size();
        }
        else if(str[i]=='('){
          //  cout<<"pushed (\n";
            S.push('(');
        }
        else if(str[i]==')' && str[i-1]!='('){
           // cout<<"poped )\n";
            stickCount++;
            S.pop();
        }
    }
    cout<<stickCount+breakCount;

    
}