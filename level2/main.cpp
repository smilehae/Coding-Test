#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int divider = 2;
    //내부가 N이 5000이 되므로 o(n^2)가능.
    while(divider <= s.size()/2){
        cout<<"when divider is "<<divider<<"size is "<<s.size()<<"there is"<<s.size()/divider<<"\n";
        for(int i=0;i<s.size();i+=divider){
            cout<<"i is "<<i<<"\n";
        }
        divider++;
    }
    return answer;
}

int main(){
    string myString = "aabbaccc";
    cout<<solution(myString);
}