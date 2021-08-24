#include <iostream>
#include <stack>
#include <string>

using namespace std;

class STACK{
    private:
    int pointTop=0;
    int dat[10000]={0};
    public:
    void push(int num){
        dat[pointTop] = num;
        pointTop++;
    }
    void pop(){
        pointTop--;
    }
    int top(){
        return dat[pointTop-1];
    }
    bool empty(){
        if(pointTop==0) return true;
        else return false;
    }
    int size(){
        return pointTop;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    stack<int> S;
    STACK mystack;

    // for(int i=0;i<n;i++){
    //     string order;
    //     cin>>order;
    //     if(order=="push"){
    //         int num;
    //         cin>>num;
    //         S.push(num);
    //     }
    //     else if(order=="pop"){
    //         if(S.empty()) cout<<"-1"<<"\n";
    //         else{
    //             cout<<S.top()<<"\n";
    //             S.pop();
    //         }
    //     }
    //     else if(order=="size"){
    //         cout<<S.size()<<"\n";
    //     }
    //     else if(order=="empty"){
    //         if(S.empty()) cout<<"1"<<"\n";
    //         else cout<<"0"<<"\n";
    //     }
    //     else if(order=="top"){
    //         if(S.empty()) cout<<"-1"<<"\n";
    //         else cout<<S.top()<<"\n";
    //     }
    // }

     for(int i=0;i<n;i++){
        string order;
        cin>>order;
        if(order=="push"){
            int num;
            cin>>num;
            mystack.push(num);
        }
        else if(order=="pop"){
            if(mystack.empty()) cout<<"-1"<<"\n";
            else{
                cout<<mystack.top()<<"\n";
                mystack.pop();
            }
        }
        else if(order=="size"){
            cout<<mystack.size()<<"\n";
        }
        else if(order=="empty"){
            if(mystack.empty()) cout<<"1"<<"\n";
            else cout<<"0"<<"\n";
        }
        else if(order=="top"){
            if(mystack.empty()) cout<<"-1"<<"\n";
            else cout<<mystack.top()<<"\n";
        }
    }
}