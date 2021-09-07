#include <iostream>
#include <map>

using namespace std;
long long arr[100002];
map<long long, int> myMap;
 int mx = 0;
 long long maxIndex = 0;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        myMap[arr[i]]++;
    }

    for(map<long long,int>::iterator it=myMap.begin();it!=myMap.end();it++){
       
        if(it->second>mx){
            mx = it->second;
            maxIndex = it->first;
        }
    }

    cout<<maxIndex;

}