#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(int i=1;i<=N;i++){
        answer.push_back(i);
    }
    vector<int> failPlayerCount(N+1); //스테이지  1 2 3 .. N 도전중인 사람 수. arr[i] = i번 도전중. i-1번 완료.
    //결국 arr[i] = i번째 스테이지를 실패한 사람 수.
    vector<int> passCount(N+1); //N번째 스테이지를 지나간 사람 수
    vector<double>failRate(N); //1~N의 실패율
    
    for(int i=0;i<stages.size();i++){
        failPlayerCount[stages[i]-1]++;
    }
 
    for(int i=0;i<failPlayerCount.size();i++){
        int num=0;
        for(int j=0;j<=i-1;j++){
            num += failPlayerCount[j];
        }
        passCount[i] = stages.size()-num;
    }
    
    for(int i=0;i<failRate.size();i++){
        failRate[i] = (double)failPlayerCount[i]/(double)passCount[i];
        //cout<<failRate[i]<<" ";
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1-i;j++){
            if(failRate[j]<failRate[j+1]){ 
                swap(failRate[j],failRate[j+1]);
                swap(answer[j],answer[j+1]);
            }
        }
    }
  
    
    return answer;
}

int main(){
    vector<int> myStages={2,1,2,6,2,4,3,3};
    vector<int> answer = solution(5,myStages);
    for(int elem: answer){
        cout<<elem<<" ";
    }
}