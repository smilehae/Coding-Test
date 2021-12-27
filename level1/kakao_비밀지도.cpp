#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

//이진수로 바꾸기
string convertTo2(int num, int n){
    string str="";
    int lengthNum = (int)log2(num)+1;
       
    while(num>=2){
        if(num%2==0) str += "0";
        else str += "1";
        num = num/2;
    }
    str += "1";
    reverse(str.begin(),str.end());
     while(lengthNum<n){
        str.insert(0,"0");
        lengthNum++;
    }
  
    return str;
} 

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string str="";
    for(int i=0;i<arr1.size();i++){
        str = convertTo2(arr1[i],n);
        answer.push_back(str);
        str = convertTo2(arr2[i],n);
        
        for(int j=0;j<str.size();j++){
            answer[i][j] = answer[i][j] | str[j];
            
            if(answer[i][j]=='0')  answer[i][j]=' ';
            else answer[i][j]='#';
        }
        cout<<answer[i]<<"\n";
    }
    return answer;
}