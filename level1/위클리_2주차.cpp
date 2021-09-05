#include <string>
#include <vector>
#include <iostream>

using namespace std;

string giveRank(int num){
    if(num>=90){
        return "A";
    }
    else if(num>=80){
        return "B";
    }
    else if(num>=70){
        return "C";
    }
    else if(num>=50){
        return "D";
    }
    else{
        return "F";
    }
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i=0;i<scores.size();i++){
        int max=0;
        int min=101;
        int sum=0;

        for(int j=0;j<scores[i].size();j++){
            //scores[i][i]는 아래에서 따로 판단할 예정.
            if(i==j) continue;

            if(scores[j][i]>max){
                max = scores[j][i];
            }
        
            if(scores[j][i]<min){
                min = scores[j][i];
            }
           
            sum += scores[j][i];
        
        }
        //조건에서, scores[i][i]가 유일한 큰거 또는 유일한 작은거면 제외 : 기존 작은거보다 작거나 기존 큰거보다 큰 경우면 제외
        if(scores[i][i]>max || scores[i][i]<min){
            sum = sum/(scores.size()-1);
        }
        else{
            sum += scores[i][i];
            sum = sum / (scores.size());
        }
        answer += giveRank(sum);
    }
   

    
    return answer;
}

int main(){
    vector<vector<int>>myVec=	{{100, 90, 98, 88, 65},{ 50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65},{ 24, 90, 94, 75, 65}};
    vector<vector<int>>vec2={{70,49,90},{68,50,38},{73,31,100}};

    cout<<solution(myVec);
}
