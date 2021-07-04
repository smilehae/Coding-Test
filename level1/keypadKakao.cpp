#include <string>
#include <vector>
#include<iostream>

using namespace std;

//여긴 내가 임의로 넣은 거
vector<int> number = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
string hands = "right";

//여기가 테스트
string solution(vector<int> numbers, string hand){
    vector<int>::iterator it;
    string answer="";
    int rightHand =  12; //* 의미
    int leftHand = 10; //# 의미
    int rightTemp;
    int leftTemp;
    int thisNum;
    int leftCount = 0;
    int rightCount = 0;
    for(it = numbers.begin();it!=numbers.end();it++){

        //1,4,7은 왼쪽
       if(*it == 1 || *it == 4 || *it == 7){
           leftHand = *it;
           answer +="L";
       }
       //3,6,9는 오른쪽
       else if(*it == 3 || *it == 6 || *it ==9){
           rightHand = *it;
           answer += "R";
       }
       //이부분을 짜야함. 더 가까운 쪽
       //양쪽 길이 비교해서 오른손잡이의 왼손이 더 가까우면 변경. vice versa.

       else{
        //cout<<"finding middle. left : "<<leftHand<<" right : "<<rightHand<<endl;
        thisNum = *it;
        leftCount = 0;
        rightCount = 0;
        leftTemp = leftHand;
        rightTemp = rightHand;
        if(thisNum == 0) thisNum= 11; //로직 적용 위해 0을 11로 변경 (핸드폰 상 위치)
        //왼쪽 손
        while(1){
            //cout<<"left hand : "<<leftTemp<<endl;
            if( leftTemp - thisNum == -1 ){
                leftCount++;
                break;
            }
            if(leftTemp - thisNum == 0){
                break;
            }
            if(leftTemp > thisNum) leftTemp = leftTemp-3;
            else if(leftTemp < thisNum) leftTemp = leftTemp + 3;

            leftCount++;
        }
        //cout<<"touching "<<thisNum<<" left Count : "<<leftCount<<endl;


        //오른쪽 손
        while(1){
            //cout<<"right hand : "<<rightTemp<<endl;
            if( rightTemp - thisNum ==1 ){
                rightCount++;
                break;
            }
            if(rightTemp - thisNum == 0){
                break;
            }
            if(rightTemp > thisNum) rightTemp = rightTemp-3;
            else if(rightTemp < thisNum) rightTemp = rightTemp + 3;

            rightCount++;
        }
        //cout<<"touching "<<thisNum<<" right Count : "<<rightCount<<endl;

        if(rightCount < leftCount){
            answer += "R";
            rightHand = thisNum;
        } 
        else if(rightCount > leftCount){
            answer +="L";
            leftHand = thisNum;
        }
        else{
            if(hand == "right"){
                answer += "R";
                rightHand = thisNum;
            }
            else{
                answer +="L";
                leftHand = thisNum;
            }
        }
       }


    }

    return answer;
}

int main(){
    cout<<solution(number,hands)<<endl;
}