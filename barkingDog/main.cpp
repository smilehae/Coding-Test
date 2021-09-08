#include<vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

//방법 1. 혼자 떨어진 친구 : sort 이후 가장 앞이나 뒤면 바로 뒤나 앞과 같지 않으면 얘가 외톨이. 중간 친구 ) 앞뒤랑 다르면 외톨이.
int lonelyinteger(vector<int> a) {
    
    int ans = 0;
    sort(a.begin(),a.end());
    
    if(a[0]!=a[1]){
        return a[0];
    }
    if(a[a.size()-1]!=a[a.size()-2]){
        return a[a.size()-1];
    }
    
    for(int i=1;i<a.size()-1;i++){
       if(a[i]!=a[i-1] && a[i]!=a[i+1]){
           ans = a[i];
           break;
       }
    }
    return ans;
}

int main(){
    vector<int> vec={1,1,2};
    cout<<lonelyinteger(vec)<<" ";
}
