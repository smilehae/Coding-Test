#include <iostream>
#include <vector>
#include <map>

using namespace std;

// int arr[2000002];
// vector<int> myVec;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int num;
//         cin>>num;
//         arr[num+1000000]++;
//     }

//     for(int i=0;i<2000002;i++){
//         if(arr[i]!=0){
//             for(int j=0;j<arr[i];j++){
//                 // cout<<i-1000000<<"\n";
//                 myVec.push_back(i-1000000);
//             }
//         }
//     }
//     for(int i=0;i<myVec.size();i++){
//         cout<<myVec[i]<<"\n";
//     }
  
// }

vector<int>vec;
map<int,int> mymap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        mymap[num]++;
    }

    for(map<int,int>::iterator it=mymap.begin();it!=mymap.end();it++){
       // cout<<"there is "<<it->second<<" numbers of "<<it->first<<"\n";
        for(int i=0;i<it->second;i++){
            vec.push_back(it->first);
        }
    }

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<"\n";
    }
}