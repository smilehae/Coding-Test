#include <string>
#include <vector>
#include <iostream>

using namespace std;

string miniString="";


string transNumber(string s){
    if(s=="zero"){
        return "0";
    }
    else if(s=="one"){
        return "1";
    }
    else if(s=="two"){
        return "2";
    }
    else if(s=="three"){
        return "3";
    }
    else if(s=="four"){
        return "4";
    }
    else if(s=="five"){
        return "5";
    }
    else if(s=="six"){
        return "6";
    }
    else if(s=="seven"){
        return "7";
    }
    else if(s=="eight"){
        return "8";
    }
    else if(s=="nine"){
        return "9";
    }
    else{
        return "-1";
    }
}

int solution(string s) {
    int answer = 0;
    string ansString="";
    for(string::iterator it=s.begin();it!=s.end();it++){
        if(*it<'0' || *it>'9'){
           
            miniString+=*it;
            if(transNumber(miniString)!="-1"){
               // cout<<"found number "<<transNumber(miniString)<<"\n";
                ansString+=transNumber(miniString);
                miniString="";
            }
        }
        else{
            ansString+=*it;
        }
    }
   // cout<<ansString<<"\n";
    answer = stoi(ansString);
    return answer;
}

int main(){
    string mystr = "2three45sixseven";
    cout<<solution(mystr);
}

/*

    루프 돌면서, 0~9가 아니면 검출 시작(bool)하고 위치 저장.
    검출 ) string 하나 만들어서 ++시키고, 만약 값이 0~9의 문자표기와 같으면 라턴 & 갯수 지워주기, result에 넣기
*/