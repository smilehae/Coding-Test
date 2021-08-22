#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

// 벡터 한번 돌면서 더 큰 값 없음 queue에 넣고 있음 가장 앞 1개 지우고 뒤에 pushback시키기.count증가. 
//아님 일단 전부 queue에 넣고 pair<int,int(location)> 하고 findif로 priority랑 비교해서 
//  myvector.erase (myvector.begin(),myvector.begin()+3);

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>>myqueue;
    vector<pair<int,int>>printVec;

    for(int i=0;i<priorities.size();i++){
       myqueue.push_back(make_pair(i,priorities[i]));
    }

    while(!myqueue.empty()){
        pair<int,int>cur = myqueue.front();
        myqueue.pop_front();
        bool isBest = true;
        for(int i=0;i<myqueue.size();i++){
            if(cur.second < myqueue[i].second) isBest = false;
        }
        if(!isBest){
            myqueue.push_back(cur);
        }
        else{
            answer++;
            if(cur.first==location) break;
        }
    }
    
   
    return answer;
}

int main(){
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    cout<<solution(priorities,0);
}