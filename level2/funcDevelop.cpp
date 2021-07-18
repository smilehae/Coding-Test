/*
프로그래머스 레벨2 : 스택/큐 : 기능개발

93 30 55 // 1 30 5 이런 식으로 들어오면, 93%, 30%, 55%의 진도율이 현재 달성되었고, 하루에 1%, 30%, 5%가 달성된다는 뜻
뒤에 것이 배포되려면 앞의 것이 완료되어야 함. 언제 완료? 

생각1 : 브루트포스
- 그냥 progresses 한바퀴 돌면서 각자 걸리는 시간 산출해서 배열에 넣기
- 배열의 요소를 싹 돌면서, 뒤에 있는 값 들 중, 해당 값보다 작은 값은 해당 값으로 바꾸기
10일 1일 5일 소요 -> 10일 10일 10일로 변경
- 날짜 같은 것끼리 갯수 해서 스택에 넣고, 나중에 리턴


Queue의 특징
- push(element) 해서 뒤에 요소 추가
-pop() 해서 앞부터 요소 삭제
-front() back()으로 원소 반환 가능
- empty() size() 존재
*/

#include <string>
#include <vector>
#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

vector<int>myprogress={93, 30, 55};
vector<int>myspeed={1,30,5};
vector<int>myanswer;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> myqueue;
    int days;
    //일단, 프로그래스와 스피드를 이용해서 걸리는 시간 산출
    //2.3일 이런식으로 걸리면- >3일 걸림으로 바꿔줌 : ceil이용
    for(int i=0;i<progresses.size();i++){
        days = ceil((double)(100-progresses[i])/(double)speeds[i]);
       // cout<<days<<endl;
        
        if(myqueue.empty()==true){
           // cout<<"this queue is empty. pushing "<<days<<endl;
            myqueue.push(days);
        }
        else{
            if(myqueue.back()> days){
               // cout<<"back is bigger than 'days'. so pushing back again"<<endl;
                myqueue.push(myqueue.back());
            }
            else{
               // cout<<"my 'days' is bigger than back. pushing my 'days'"<<endl;
                myqueue.push(days);
            }
        }

    }
   
    int count = 1;
    int day = 0;

    while(myqueue.empty()==false){
        //가장 처음 값이 들어옴 -> 이거의 값을 셀 거임
      //  cout<<"queue front value : "<<myqueue.front()<<endl;

        if(day==0){
            day = myqueue.front();
          //  cout<<"day is "<<day<<endl;
        }
        else{
            if(day == myqueue.front()){
                count++;
              //  cout<<count<<" things finishes in day "<<day<<endl;

            }
            else{
                answer.push_back(count);
             //   cout<<"pushing back "<<count<<" to answer"<<endl;
                day = myqueue.front();
                count = 1;
              //  cout<<"this can be finished in day "<<day<<endl;
            }
        }
        myqueue.pop();
    }
    answer.push_back(count);
 //   cout<<"pushing back "<<count<<" to answer"<<endl;
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<< " ";
    }
    return answer;
}

int main(){
    myanswer = solution(myprogress,myspeed);
}