#include <iostream>
#include <string>

using namespace std;

const int MX = 1000005;

class MYDEQ{
private:    
    int dat[2*MX+1];
    int head = MX, tail = MX;
public:
    void push_front(int x){
    head--;
    dat[head] = x;
    }

    void push_back(int x){
    dat[tail] = x;
    tail++;
    }

    void pop_front(){
    head++;
    }

    void pop_back(){
    tail--;
    }

    int front(){
    return dat[head];
    }

    int back(){
    return dat[tail-1];
    }
    bool empty(){
        if(head==tail) return true;
        else return false;
    }
    int size(){
        return tail-head;
    }
};

MYDEQ Q;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
      string order;
      cin>>order;
      if(order=="push_front"){
          int num;
          cin>>num;
          Q.push_front(num);
      }
      else if(order=="push_back"){
          int num;
          cin>>num;
          Q.push_back(num);
      }
      else if(order=="pop_front"){
          if(Q.empty()) cout<<"-1\n";
          else{
              cout<<Q.front()<<"\n";
              Q.pop_front();
          }
      }
      else if(order=="pop_back"){
          if(Q.empty()) cout<<"-1\n";
          else{
              cout<<Q.back()<<"\n";
              Q.pop_back();
          }
      }
      else if(order=="size"){
          cout<<Q.size()<<"\n";
      }
      else if(order=="empty"){
          if(Q.empty())cout<<"1\n";
          else cout<<"0\n";
      }
      else if(order=="front"){
          if(Q.empty())cout<<"-1\n";
          else cout<<Q.front()<<"\n";
      }
      else if(order=="back"){
          if(Q.empty())cout<<"-1\n";
          else cout<<Q.back()<<"\n";
      }

  }
}