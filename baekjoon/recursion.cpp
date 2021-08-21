#include<iostream>

//N부터 1까지 출력
void func1(int n){
    if(n==0)return;
   // std::cout<<n<<" ";
    func1(n-1);
}

//1부터 N까지의 합 구함
//각자 부분합 리턴.
int func2(int n){
    if(n==0){
        return 0;
    }
    return func2(n-1)+n;
}

//a^b를 m으로 나눈 나머지?
/*
    1. a를 b번 곱하고 %m
*/
using ll = long long;
ll func3(ll a, ll b, ll m){
    ll val=1;
    while(b--){
        val *= a %m;
    }
    return val;
}

int main(){
    std::cout<<func3(6,100,5);
  
}

