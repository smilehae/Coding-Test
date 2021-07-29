#include<iostream>
#include <list>

using namespace std;

int main(){
    list<int> L = {1,2};
    list<int>::iterator it = L.begin();
    L.push_front(10); //10 1 2
    cout<<*it<<endl;//1
    L.push_back(5); //10 1 2 5
    L.insert(it,6); // 10 6 1 2 5 it앞에 6 삽입, it는 여전히 1 가리킴
    it++; //it이 2 가리킴
    it = L.erase(it); //it이 가리키는거 지우고, 그 다음 위치를 반환
    // 2 삭제 후 5 가리킴
    cout<<*it<<"\n";

    // C 11이상!
    for(int i : L){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(list<int>::iterator i=L.begin();i!=L.end();i++){
        cout<<*i<<" ";
    }
}