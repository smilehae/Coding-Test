#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void showBoard(vector<vector<int>> board, vector<int> moves){
       for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> S;

 
    for(int i=0;i<moves.size();i++){
        int index = moves[i]-1;
        int element=0;
        //cout<<"this is "<<i+1<<"th move. selected "<<moves[i]<<"\n";
        for(int j=0;j<board.size();j++){
            if(board[j][index]!=0){
                element = board[j][index];
               // showBoard(board,moves);

                //cout<<"found it in "<<j<<"th vector. break\n";
                board[j][index]=0;
                if(!S.empty()){
                    if(S.top()==element){
                        answer+=2;
                        //cout<<"met another "<<element<<". pop became "<<answer<<"\n";
                        S.pop();
                    }
                    else{
                        S.push(element);
                       // cout<<"pushed "<<element<<"\n";
                    }
                }
                else{
                    S.push(element);
                   // cout<<"pushed "<<element<<"\n";

                }

                break;
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> myBoard={{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> myMove={1,5,3,5,1,2,1,4};
    cout<<solution(myBoard,myMove);
}