#include <string>
#include <vector>
#include <cmath>

/*
    프로그래머스 월간 코드 챌린지 시즌 1. 3진법 뒤집기.
    몫을 3으로 나누고 나머지를 string에 집어넣고, string의 요소 하나씩을 int로 만들어서
    string을 int로 하려면 stoi(string). int를 string으로 하려면 to_string(int);
    char을 int로 만드려면 char-'0'
*/
using namespace std;

int solution(int n) {
    int answer = 0;
    //3진법 변경
    string third="";
    int quotient = n;
    int remainder = 0;
    while(quotient>=3){
        remainder = quotient % 3;
        quotient /= 3;
        third += to_string(remainder);
    }
    third += to_string(quotient);
    //10진법 변환
    double count = 0;
    for(int i=third.size()-1;i>=0;i--){
        int num = third[i]-'0';
        answer += num*pow(3,count);
        count++;
    }
    
    return answer;
}