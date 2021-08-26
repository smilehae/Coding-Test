#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDone;



int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    stack<char> S;
    string str;
    //string 헤더의 getline. cin을 output으로 받고 
    while(str!="."){
        isDone = false;
        getline(cin,str);
        if(str==".")break;
        for(char elem : str){
            if(elem=='(' || elem=='['){
                S.push(elem);
            //    cout<<"pushed "<<elem<<"\n";
            }
            else if(elem==')'){
                if(S.empty()) {
                    isDone=true;
                  //  cout<<"empty.not match()\n";
                    }
                else if(S.top()!='('){
                     isDone=true;
                   //  cout<<"not match.()\n";
                     }
                else {
                 //   cout<<"found ). pop\n";
                    S.pop();
                }
            }
            else if(elem==']'){
                if(S.empty()) {
                    isDone=true;
                 //   cout<<"empty.not match[]\n";
                    }
                else if(S.top()!='[') {
                    isDone=true;
                 //   cout<<"not match [].\n";
                    }
                else {
                 //   cout<<"found ]. pop\n";
                    S.pop();
                }
            }
        }
        if(!S.empty()){
            isDone = true;
            while(!S.empty()){
                S.pop();
            }
        }
        if(isDone) cout<<"no\n";
        else cout<<"yes\n";
    }
    

    // while(str!="."){
    // }
}