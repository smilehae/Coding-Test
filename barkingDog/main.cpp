#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100002];
int curNum=0;
 int mx = 0;
 int cnt=0;
 long long maxIndex = 0;

int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    maxIndex = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]!=curNum){
            cnt = 1;
            curNum = arr[i];
            cout<<"it's not same. now cur Num "<<curNum<<"\n";

        }
        else{
            cnt++;
             cout<<"it's same num. count is "<<cnt<<" and max is "<<mx<<"\n";

            if(cnt > mx){
                mx = cnt;
                maxIndex = arr[i];
                cout<<"num is chaned to "<<maxIndex<<"\n";

            }
        }

    }


    cout<<maxIndex;

}