#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    string item;
    vector<string>::iterator it1 = participant.begin();
   vector<string>::iterator it2 = completion.begin();
    
    //정렬을 시킨 다음에, it하나씩 이동하면서 체크
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    //eden kiki leo hihi / eden kiki hihi
    for(it2 = completion.begin();it2!=completion.end();it2++){
        vector<string>::iterator it3;

        if(*it1 != *it2){
            answer = *it1;
            return answer;
        }
        
        it1++;
    }
    answer = *(it1);
    
    return answer;
}