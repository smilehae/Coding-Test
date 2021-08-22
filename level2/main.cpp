#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> compVec;
    int pick;
    //첫번째 사람
    int score1=0;
    for(int i=0;i<answers.size();i++){
        pick = i%5+1;
        if(answers[i]==pick) score1++;
    }
    int score2=0;
    for(int i=0;i<answers.size();i++){
        if(i%2==0) pick = 2;
        else{
            if(i%8==1) pick=1;
            else if(i%8==3) pick=3;
            else if(i%8==5)pick =4;
            else if(i%8==7)pick=5;
        }
        if(answers[i]==pick) score2++;

    }
    int score3=0;
    for(int i=0;i<answers.size();i++){
        if(i%10==0 || i%10==1) pick=3;
        else if(i%10==2 || i%10 ==3)pick=1;
        else if(i%10==4 || i%10==5)pick=2;
        else if(i%10==6 || i%10==7)pick=4;
        else pick=5;

        if(answers[i]==pick) score3++;
    }
    
    if(score1>score2 && score1>score3){
        answer.push_back(1);
    }
    else if(score2>score1 && score2>score3){
        answer.push_back(2);
    }
    else if(score3>score1 && score3>score2){
        answer.push_back(3);
    }
    else if(score1==score2 && score2>score3){
        answer.push_back(1);
        answer.push_back(2);
    }
    else if(score2==score3 && score2>score1){
        answer.push_back(2);
        answer.push_back(3);
    }
    else if(score3==score1 && score1>score2){
        answer.push_back(1);
        answer.push_back(3);
    }
    else{
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }

    cout<<score1<<" "<<score2<<" "<<score3<<"\n";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    
    return answer;
}

int main(){
    vector<int>myanswer={1,3,2,4,2};
    solution(myanswer);
}