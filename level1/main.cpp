/*
프로그래머스 위클리 챌린지 4주차 : 직업군 추천하기

table 길이 5 : [직업군 5점 언어 4점 3점 2점 1점] 이런 배열 있음
languages 선호 언어
preference : 선호 언어의 선호도
언어 선호도 * 직업군 언어 점수 총합 높은 거 리턴
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    int score;
    string answer = "";
    return answer;
}

int main(){
    vector<string> myTable={"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};

    vector<string> myLanguage = {"PYTHON","C++","SQL"};
    vector<int> myPreference = {7,5,5};

    cout<<solution(myTable,myLanguage,myPreference);
}