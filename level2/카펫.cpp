#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=sqrt(yellow);i++){

        if(yellow%i!=0) continue;

        int row = i;
        int col = yellow/i;
      //  cout<<row<<" "<<col<<" "<<(row+col)*2+4<<"\n";

        if(((row+col)*2+4)==brown){
         //   cout<<row+2<<" "<<col+2<<" is answer.";
            row += 2;
            col += 2;
            if(row < col){
                int temp = row;
                row = col;
                col = temp;
            }
            answer.push_back(row);
            answer.push_back(col);
            break;
        }

    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}

int main(){
    solution(8,1);
}