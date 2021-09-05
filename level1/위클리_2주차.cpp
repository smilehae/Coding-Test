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
    int max=0;
    int min=-1;
    int scoresFinal[10]={0};
    int sizeOfEach[10]={0};
    bool isOnlyMax = true;
    bool isOnlyMin = true;
    vector<int> total(scores.size(),0);
    
    for(int i=0;i<scores.size();i++){
        max=0;
        min=101;
        for(int j=0;j<scores[i].size();j++){
            cout<<scores[j][i]<<" ";
            if(scores[j][i]>max){
                isOnlyMax = true;
                 max = scores[j][i];
            }
            else if(scores[j][i]==max){
                isOnlyMax = false;
            }
             if(scores[j][i]<min){
                isOnlyMin = true;
                 min = scores[j][i];
            }
            else if(scores[j][i]==min){
                isOnlyMin = false;
            }
            scoresFinal[j] = scores[j][i];
        }
        cout<<"max : "<<max<<" min : "<<min<<"\n";
        for(int k=0;k<scores[i].size();k++){
            cout<<scoresFinal[k]<<" ";
            if(scoresFinal[k]==max && max==scores[i][i]&&isOnlyMax || scoresFinal[k]==min &&min==scores[i][i]&&isOnlyMin ){
                cout<<"self giving high~ low\n";
                continue;
            }
            total[i]+=scoresFinal[k];
            sizeOfEach[i]++;
            cout<<"adding "<<scoresFinal[k]<<" total became "<<total[i]<<"\n";
        }
        cout<<"\n";
    }
   
    
    for(int i=0;i<scores.size();i++){
        cout<<total[i]<<"/";
        cout<<sizeOfEach[i]<<"=";
        cout<<giveRank(total[i]/sizeOfEach[i]);
        cout<<"("<<giveRank(total[i]/sizeOfEach[i])<<")\n";
        answer+=giveRank(total[i]/sizeOfEach[i]);
    }
    
    
    return answer;
}

int main(){
    vector<vector<int>>myVec=	{{100, 90, 98, 88, 65},{ 50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65},{ 24, 90, 94, 75, 65}};
    vector<vector<int>>vec2={{70,49,90},{68,50,38},{73,31,100}};

    cout<<solution(myVec);
}
