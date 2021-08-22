#include<vector>
#include<iostream>
#include<cmath>
#include<queue>

/*
기능개발.
7 3 9일 걸리는 프로세스가 있으면, 큐에 7 7 10 이렇게 넣고 앞쪽부터 빼서 갯수 세면 됨.
*/
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>answer;
    queue<int> timeQueue;
    for(int i=0;i<progresses.size();i++){
        int leftTime = ceil((100-progresses[i])/(double)speeds[i]);
        if(timeQueue.empty()==true){
            timeQueue.push(leftTime);
        }
        else{
            if(leftTime<timeQueue.back())leftTime = timeQueue.back();
            timeQueue.push(leftTime);
        }
    }

//1 2 3 4
    int count = 0;
    while(!timeQueue.empty()){
       int prev = timeQueue.front();
       timeQueue.pop();
        count++;
        if(timeQueue.front()!=prev){
            answer.push_back(count);
            count = 0;
        }
    }


    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}

int main(){
    vector<int>progress={95, 90, 99, 99, 80, 99};
    vector<int>speed={1, 1, 1, 1, 1, 1};
    solution(progress,speed);

}

/*

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> myqueue;
    int days;

    for(int i=0;i<progresses.size();i++){
        days = ceil((double)(100-progresses[i])/(double)speeds[i]);
        
        if(myqueue.empty()==true){
            myqueue.push(days);
        }
        else{
            if(myqueue.back()> days){
                myqueue.push(myqueue.back());
            }
            else{
                myqueue.push(days);
            }
        }

    }
   
    int count = 1;
    int day = 0;

    while(myqueue.empty()==false){
        if(day==0){
            day = myqueue.front();
        }
        else{
            if(day == myqueue.front()){
                count++;
            }
            else{
                answer.push_back(count);
                day = myqueue.front();
                count = 1;
            }
        }
        myqueue.pop();
    }
    answer.push_back(count);
 
    return answer;
}
*/