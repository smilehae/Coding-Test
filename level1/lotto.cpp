#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findRank(int count){
    if(count==6) return 1;
    else if(count==5) return 2;
    else if(count==4) return 3;
    else if(count==3) return 4;
    else if(count==2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int corCount = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0)count++;
        for(int j=0;j<win_nums.size();j++){
            if(lottos[i] == win_nums[j]){
                corCount++;
            }
        }
    }

    int bestRank = findRank(count+corCount);
    int worstRank = findRank(corCount);
    answer.push_back(bestRank);
    answer.push_back(worstRank);
    
    return answer;
}

int main(){
    vector<int> myLotto = {45, 4, 35, 20, 3, 9};
    vector<int> winner  = {20, 9, 3, 45, 4, 35};
    vector<int> answer = solution(myLotto,winner);
    for(int elem:answer){
        cout<<elem<<" ";
    }
}