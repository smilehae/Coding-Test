#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


//4칸짜리 배열에서 최대값을 반환
int findBiggest(int arr[]){
    
    //방법 1. algorithm 헤더 + sort 사용. 기본적으로 quick sort기반.
    // sort(arr,arr+4);
    // return arr[3];

    //방법 2. for문 돌리기
    //int max = 0;
    // for(int i=0;i<4;i++){
    //     if(arr[i]>max) max = arr[i];
    // }
    // return max;

    //이방법 굳. 가장 큰 원소가 있는 곳의 iterator를 반환해준다.
    //자매품 min_element
    //알고리즘 헤더.
    return *max_element(arr,arr+4);
    //*max_element(arr,arr+4,cmp) 이렇게 cmp함수 같이 사용도 가능.
}

//N이 5만 이하이다 : 기준이 1초일시 O(nlogn)까지 가능이다.
//이 풀이는 O(N) 풀이이므로 세이프.
int func1(int N){
    int total=0;
    for(int i=1;i<=N;i++){
        if(i%3 ==0 || i%5==0){
            total += i;
        }
    }
    return total;
}

int func2(int arr[],int N){
    bool isHundred = false;
    //O(n^2)풀이
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         if(i==j)continue;
    //         if(arr[i]+arr[j]==100){
    //             isHundred=true;
    //         }
    //     }
    // }

    //O(n) 풀이
    int keepArr[1000]={0};
    for(int i=0;i<N;i++){
        keepArr[arr[i]]=1;
        if(keepArr[100-arr[i]]==1) isHundred = true;
    }
    return isHundred;
}

//N은 10억 이하 자연수 : 시간복잡도 : O(root(N))
int func3(int N){
    for(int i=1;i<=sqrt(N);i++){
       if(i*i==N)return 1;
    }
    return 0;
}

int func4(int N){
    int ans =1;
    while(1){
        if(ans*2>N)break;
        ans *=2;
    }
    return ans;
}

int main(){
    int myArr[4] ={3,4,5,2};
    int arr[]={1,52,48};
   
   cout<<func4(1024);
}