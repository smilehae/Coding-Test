#include<cstdio>
#include<algorithm>
/*
    주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N) 을 작성하라. 이때 arr의 각 수는 0~100사이, N은 1000이하.

    SOL1. O(N^2)
    두개씩 더해가면서 이중루프로 100이 되면 리턴 1 안되면 리턴 0

    SOL2. O(N)
    100짜리 배열을 만들어서, 각 값에 접근하면서 배열에 저장. 새로운 값에 접근하면, 해당 배열의 100-새로운값 에 접근해서 값이 있음 리턴 1 다 꽝이면 0
*/
using namespace std;

int func2(int arr[], int N){
    int arr2[101]; //0에서 100
    fill(arr2,arr2+101,0);
    for(int i=0;i<N;i++){
        //arr2의 해당 위치(100-현재값)에 이미 값이 있다면, 현재값과 합치면 100이므로 1!
        if(arr2[100-arr[i]]==1) return 1;
        //접근할떄, 이미 이 지점 지남! 이라고 알려줌
        arr2[arr[i]] = 1;
    }
    return 0;
}
int main(){
    int arr[]={4,13,63,87};
    printf("%d",func2(arr,4));
}