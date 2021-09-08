#include <iostream>

using namespace std;
/*
    런타임에러로 고생했다. 배열의 인덱스가 0보다 작은 것에 접근한 것이 문제였다.
    x-arr[i]를 했는데, x가 arr[i]보다 작을 수도 있다는 것을 간과하였다.
*/
int arr[100002];
int tmp[2000002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tmp[arr[i]]=1;

    }
    cin>>x;

    for(int i=0;i<n;i++){
        if(arr[i]>x)continue;
        if(tmp[x-arr[i]]==1){
            ans++;
        }
    }

    cout<<ans/2;
}