#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

void showVector(vector<int> array){
    vector<int>::iterator it1;
    for(it1 = array.begin();it1!=array.end();it1++){
            cout<<*it1<<" ";
        }
    puts("");

}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    int tempAns;

    for(int i=0;i<commands.size();i++){
        it1 = array.begin();
        it2 = array.begin();
        advance(it1,commands[i][0]-1);
        advance(it2,commands[i][1]);
        temp = {it1,it2};

        sort(temp.begin(),temp.end());

        tempAns = temp[commands[i][2]-1];
        answer.push_back(tempAns);
    }


    return answer;
}

vector<int> myArray = {1, 5, 2, 6, 3, 7, 4};
vector<vector<int>> myCommand = {{2,5,3},{4,4,1},{1,7,3}};
vector<int> myAnswer;

int main(){
    myAnswer = solution(myArray,myCommand);
    vector<int>::iterator it;
    for(it = myAnswer.begin();it!=myAnswer.end();it++){
        cout<<*it<<" ";
    }
}