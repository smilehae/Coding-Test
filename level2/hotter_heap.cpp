#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>   // std::greater


using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;
    priority_queue <int, vector<int>,greater<int>> Q;
    for(int elem : scoville){
        Q.push(elem);
    }
    while(Q.top()<K){
        int first = Q.top(); Q.pop();
        int second = Q.top();Q.pop();
        int newFood = first + (2 * second);
        Q.push(newFood);
        cout<<"chosen "<<first<<" and "<<second<<". made "<<newFood<<"\n";
        count++;
        if(count==scoville.size()){
            return -1;
        }
    }
    return count;
}

int main(){
    vector<int> mySco = {3,2,1,9,10,12};
    int k = 7;
    cout<<"\nanswer : "<<solution(mySco,k);
}