#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> v1 = {1,2,3,4,5,6};

    //C++ 11부터 추가됨. 이걸 int &item :v1 이렇게 쓰면, 실제 값이 변함.
    for(int item:v1){
        cout<<item<<" ";
    }
    cout<<"\n";

    //인덱스로 접근
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n";

    //iterator로 접근
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

}