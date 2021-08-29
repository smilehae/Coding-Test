/*2021 8월
프로그래머스 위클리 챌린지 4주차 : 직업군 추천하기

table 길이 5 : [직업군 5점 언어 4점 3점 2점 1점] 이런 배열 있음
languages 선호 언어
preference : 선호 언어의 선호도
언어 선호도 * 직업군 언어 점수 총합 높은 거 리턴
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string delimiter=" ";
   int score[5];
    fill(score,score+5,0);
    
    map<string,int> myMap[5];
    vector<string> names;
   
    for(int i=0;i<table.size();i++){
        int pref=6;
        while(1){
            int pos = table[i].find(delimiter);
            string word = table[i].substr(0,pos);
            if(names.size()==i){
                names.push_back(word);
             //   cout<<"putting "<<word<<"\n";
            }
            else{
                myMap[i].insert(make_pair(word,pref));
           //     cout<<"inserting "<<word<<"  "<<pref<<" to map "<<i<<"\n";
            }
            table[i].erase(0,pos+delimiter.length());
            //cout<<word<<" ";
            if(pos==string::npos){
            //    cout<<"fin. break\n";
                break;
            }
         pref--;
        }
       
        //cout<<"\n";
    }

// //내용 확인 용
//     for(int i=0;i<table.size();i++){
//         cout<<names[i]<<"\n";
//         for(map<string,int>::iterator it=myMap[i].begin();it!=myMap[i].end();it++){
//             cout<<it->first<<" "<<it->second<<"\n";
//         }
//     }

    for(int i=0;i<table.size();i++){
       // cout<<"starting "<<i<<"\n";
        for(int j=0;j<languages.size();j++){
            score[i] += (myMap[i][languages[j]]*preference[j]);
           // cout<<"adding score "<<score[i]<<" from "<<languages[j]<<" in "<<names[i]<<"  "<<myMap[i][languages[j]]<<"*"<<preference[j]<<"\n";
        }
    }

    int maxIndex = 0;
    int max = 0;
    for(int i=0;i<table.size();i++){
        if(score[i]>max){
            max = score[i];
            maxIndex = i;
        }
        else if(score[i]==max){
            if(names[i]<=names[maxIndex]){
                maxIndex = i;
            }
        }
    }
    //cout<<"max num : "<<max<<"recommand "<<names[maxIndex]<<"\n";

   

    string answer = "";
    answer = names[maxIndex];
    return answer;
}

int main(){
    vector<string> myTable={"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};

    vector<string> myLanguage = {"PYTHON", "C++", "SQL"};
    vector<int> myPreference = {7,5,5};

    cout<<solution(myTable,myLanguage,myPreference);
}