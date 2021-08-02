/*
    백준 1697 
    수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

    수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

    이 문제를 뭐로 풀어야 할까?
    결국 수빈이를 찾는 가장 빠른 시간을 구하는 거고, 수빈이 처음 위치 넣고 + 1 -1 *x 해서 bfs를 돌려서, 동생이 있는 위치에 있는 거리를 쓰면 될 것이다.

    board의 크기를 뭐로 설정해야 할까?
    본문에서 수빈이가 100000의 밖으로 들어갔다가 나올 수도 있다.
    따라서, 0~100000해서 한정하면 안된다. 
    단, +1 해서 나가는건 손해이고, *2로 나갔다가 -1로 돌아올바에는, -1하고 *2하는게 -1이 2번 줄어서 낫기 때문에, 저 범위 내에서만 확인하는 것이 좋다.


*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue<int> Q;
int board[100001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    if(n==k) {
        cout<<"0";
        return 0;
    }
    fill(board,board+100001,-1);
    
    board[n]=0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        //cout<<"poped "<<cur<<" distance "<<board[cur]<<"\n";
        int dx = cur+1;
        if(dx>0 && dx<100001){
            if(board[dx]==-1){
                if(dx==k){
                    cout<<board[cur]+1;
                    break;
                }
                board[dx]=board[cur]+1;
                Q.push(dx);
               // cout<<"visiting "<<dx<<" distance "<<board[dx]<<"\n";
               
            }
        }

        dx = cur-1;
        if(dx>0 && dx<100001){
            if(board[dx]==-1){
                 if(dx==k){
                    cout<<board[cur]+1;
                    break;
                }
                board[dx]=board[cur]+1;
                Q.push(dx);
              //  cout<<"visiting "<<dx<<" distance "<<board[dx]<<"\n";
                
            }
        }

        dx = cur*2;
        if(dx>0 && dx<100001){
            if(board[dx]==-1){
                 if(dx==k){
                    cout<<board[cur]+1;
                    break;
                }
                board[dx]=board[cur]+1;
                Q.push(dx);
                 //cout<<"visiting "<<dx<<" distance "<<board[dx]<<"\n";

            }
        }
        
        
    }


    

}