#include<iostream>
#include<utility> //이 헤더에 pair 존재

using namespace std;

int main(){
    std::pair<int,int> t1 = std::make_pair(6,13);
    pair<int,int> t2 = {4,15}; //c++11
    cout<<t2.first<<" "<<t2.second<<'\n';
    //pair에는 대소관계가 설정되어 있어서, first끼리 비교 후 같으면 second끼리 비교
    if(t2<t1) cout<<"t2<t1"<<'\n';
}

