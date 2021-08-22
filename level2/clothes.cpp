#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //옷을 입는 경우의 수 : 각 부위별 갯수+1 끼리 * -1(안입는거 제외)
    int answer = 1;
    unordered_map<string,int>mymap;

    for(int i=0;i<clothes.size();i++){
        mymap[clothes[i][1]]++;
    }

    for(unordered_map<string,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        answer *=(it->second+1);
    }
    
    return answer-1;
}

int main(){
    vector<vector<string>> mycloth={{"whitepants","pants"}};

    cout<<solution(mycloth);

}