#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    vector<string>::iterator it;
    it = find(seoul.begin(),seoul.end(),"Kim");
    cout<<*it;
    string answer = "김서방은 "+*it+"에 있다";
    return answer;
}

int main(){
    vector<string>myString = {"hihi","Kim"};
    cout<<solution(myString);
}