#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
     int num;
    deque<int> deq;
    cin>>n;
    for(int i=0;i<n;i++){
        string order;
        cin>>order;
        if(order.compare("push_front")==0){
            cin>>num;
            deq.push_front(num);
        }
        else if(order.compare("push_back")==0){
            cin>>num;
            deq.push_back(num);
        }
        else if(order=="pop_front"){
            if(deq.empty()==true){
                cout<<"-1\n";
            }
            else{
                cout<<deq.front()<<"\n";
                deq.pop_front();
            }
        }
        else if(order=="pop_back"){
            if(deq.empty()==true){
                cout<<"-1\n";
            }
            else{
                cout<<deq.back()<<"\n";
                deq.pop_back();
            }
        }
        else if(order=="size"){
            cout<<deq.size()<<"\n";
        }
        else if(order=="empty"){
            if(deq.empty()) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(order=="front"){
             if(deq.empty()) cout<<"-1\n";
            else cout<<deq.front()<<"\n";
        }
        else if(order=="back"){
             if(deq.empty()) cout<<"-1\n";
            else cout<<deq.back()<<"\n";
        }
    }
}