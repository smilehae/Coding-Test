#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

/*
    배열을 지그재그로 만들기.
    방법 1. vector의 성질을 이용하기
    방법 2. 열심히 swap 하기
*/

void findingSeq (vector<int> a, int n){
    int mid = ((n+1)/2)-1;
    sort(a.begin(),a.end());
    swap(a[mid],a[n-1]);
    int st = mid+1;
    int ed = n-2;
    while(st<=ed){
        swap(a[st],a[ed]);
        st = mid + 1;
        ed = ed-1;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    vector<int>myVec={1,7,2,6,5,4,3};
    findingSeq(myVec,7);

    
}

