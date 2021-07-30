#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    std::queue<int> Q;    
    cin>>n;
    for(int i=0;i<n;i++){
        string order;
        cin>>order;
        if(order.compare("push")==0){
            int number;
           cin>>number;
            Q.push(number);
        }
        else if(order=="pop"){
            if(Q.empty()){
                cout<<"-1"<<"\n";
            }
            else{
               cout<<Q.front()<<"\n";
                Q.pop();
            }
        }
        else if(order.compare("size")==0){
            cout<<Q.size()<<"\n";
        }
        else if(order.compare("front")==0){
            if(Q.empty()){
                cout<<"-1"<<"\n";
            }
            else{
             cout<<Q.front()<<"\n";
            }
        }
         else if(order=="back"){
            if(Q.empty()){
                cout<<"-1"<<"\n";
            }
            else{
              cout<<Q.back()<<"\n";
            }
        }
        else if(order=="empty"){
            if(Q.empty()) cout<<"1"<<"\n";

            else   cout<<"0"<<"\n";
        }

    }

}