#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<int> winCount(weights.size(),0);
    vector<int> totalCount(weights.size(),0);
    vector<int> eggCount(weights.size(),0);

    //전체 승률 계산
    for(int i=0;i<head2head.size();i++){
        for(int j=0;j<head2head[i].size();j++){
            if(head2head[i][j]=='W'){
                winCount[i]++;
                totalCount[i]++;
                totalCount[j]++;
                if(weights[i]<weights[j]) eggCount[i]++;
            }
        }
    }
    for(int i=0;i<head2head.size();i++){
        cout<<"winning cout for "<<i+1<<" is "<<winCount[i]<<"("<<((float)winCount[i]/(float)totalCount[i])*100<<") eggCount is "<<eggCount[i]<<"\n";
        answer.push_back(i+1);
    }


    // for(int i=0;i<head2head.size();i++){
    //     for(int j=0;j<head2head.size();j++){
    //         if(winCount[j]>winCount[i]){
    //             cout<<j+1<<" is better than "<<i+1<<"\n";
    //             int temp = answer[i];
    //             answer[i] = answer[j];
    //             answer[j] = temp;
    //         }
    //         else if(eggCount[j]>eggCount[i]){
    //             cout<<j+1<<" is won bigger than "<<i+1<<"\n";
    //              int temp = answer[i];
    //             answer[i] = answer[j];
    //             answer[j] = temp;
    //         }

    //     }
    // }

    for(int j=0;j<head2head.size()-1;j++){
        for(int i=0;i<head2head.size()-1;i++){
            cout<<"comparing "<<answer[i+1]<<" and "<<answer[i]<<"\n";
            if(winCount[i+1]>winCount[i]){
                cout<<answer[i+1]<<" is better than "<<answer[i]<<"\n";
                int temp = answer[i];
                answer[i] = answer[i+1];
                answer[i+1] = temp;
            }
             else if(eggCount[i+1]>eggCount[i]){
                cout<<answer[i+1]<<" is won egg than "<<answer[i]<<"\n";
               int temp = answer[i];
                answer[i] = answer[i+1];
                answer[i+1] = temp;
            }
        }
    }
    
    return answer;
}

int main(){
    vector<int> myWeight = {50,82,75,120};
    vector<string> heading = {"NLWL","WNLL","LWNW","WWLN"};
    vector<int> ans = solution(myWeight,heading);
    for(int elem: ans){
        cout<<elem<<" ";
    }
}