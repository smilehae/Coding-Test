#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

string changetoTwo(int n){
    cout<<"dealing with "<<n<<"\n";
    int remainder;
    int quotient = n;
    string changedString="";
    while(quotient>=2){
        
        remainder=quotient%2;
        quotient/=2;
        cout<<quotient<<"---"<<remainder<<"\n";
        changedString+=(char)(remainder+48);
        cout<<"put "<<(char)(remainder+48)<<" ";
    }
    changedString += (char)(quotient+48);
    reverse(changedString.begin(),changedString.end());
    cout<<n<<" is changed to "<<changedString<<"\n";
    return changedString;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int map[16][16];
    for(int i=0;i<n;i++){
        //arr1
        string changedString = changetoTwo(arr1[i]);
        string myString="";
        for(int j=n-changedString.size();j<n;j++){
            if(changedString[j]=='1'){
                myString[j]='#';
                cout<<"it's one\n";
            }
            else
            {
                myString[j]=' ';
                cout<<"it's zero\n";
            }
            
        }
        cout<<"pushing "<<myString<<" ";
        //arr2
    }
    
    return answer;
}

int main(){
    vector<int> ar1={9, 20, 28, 18, 11};
    vector<int> ar2= {30, 1, 21, 17, 28};
    vector<string> ans = solution(5,ar1,ar2);
    for(string elem : ans){
        cout<<elem<<"\n";
    }
}