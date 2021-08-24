#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    map<int,int> originMap;
    for(int i=0;i<numbers.size();i++){
        //char은 바로 int에 할당하면 바뀌어진다.
        //단, 이때의 값은 char의 아스키 값이므로, 정홗한 int 값을 원한다면 -48 또는 -'0' 를 해주어야 한다.
        int elem = numbers[i]-'0';
        originMap[elem]++;
    }

    // for(map<int,int>::iterator it=originMap.begin();it!=originMap.end();it++){
    //     cout<<it->first<<" "<<it->second<<"\n";
    // }

    for(int i=0;i<10000000;i++){
        cout<<i<<" ";
    }

    return answer;
}

int main(){
    cout<<solution("176663");
}