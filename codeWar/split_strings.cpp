#include<iostream>
#include<string>
#include <vector>
//codewar. 2021.07.23
/*
  split strings
  string을 2개씩 나누어준다. 홀수개인 경우, 마지막을 _로 대체한다.
*/

using namespace std;

std::vector<std::string> solution(const std::string &s)
{
  vector<string> answer = {};
  string mystring = s;
  string::iterator it = mystring.begin();
  string substring="";
  
  //만약 string이 홀수면 마지막에 -를 넣어야 한다고 표시
  if(mystring.size()%2==1){
    mystring.append("-");
  }

  for(it=mystring.begin();it!=mystring.end();it+=2){
     
      cout<<*it<<endl;
  }

  answer.push_back(mystring);
  answer.push_back("hoho");

    return answer; // Your code here
}

int main(){
  vector<string> myanswer = solution("abc");
  for(int i=0;i<myanswer.size();i++){
    cout<<myanswer[i]<<endl;
  }
}