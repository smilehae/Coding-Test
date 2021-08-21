#include <string>
#include <vector>
// #include<algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

//sort를 사용한 버전 ) 복잡도 _ O(nlogn)
// string solution(vector<string> participant, vector<string> completion) {
//     string answer="";

//     sort(participant.begin(),participant.end());
//     sort(completion.begin(),completion.end());

//     for(int i=0;i<completion.size();i++){
//         if(participant[i]!= completion[i]){
//             answer = participant[i];
//             return answer;
//         }
//     }
//     answer = participant[participant.size()-1];
//     return answer;
// }

//이 문제 의도 : hash 이용 0 map

string solution(vector<string> participant,vector<string> completion){
    string answer="";
    unordered_map<string,int> mymap;
    
    vector<string>::iterator it;
    for(it=completion.begin();it!=completion.end();it++){
        mymap[*it]++;
    }

    for(string elem:participant){
        if(mymap.find(elem)!=mymap.end()){
            mymap[elem]--;
            if(mymap[elem]<0){
                answer = elem;
                return answer;
            }
        }
        else{
            return elem;
        }
    }
}


int main(){
    vector<string> part={"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> comple = {"josipa", "filipa", "marina", "nikola"};

    cout<<solution(part,comple);

}