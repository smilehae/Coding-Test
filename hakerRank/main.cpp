#include <sstream> //stringstream 쓰려면 sstream 필수!
#include <vector>
#include <iostream>
using namespace std;
/*
    stringstream.
    string내용을  stringstream에 복사하고, 
    cin>>num 이런 것과 마찬가지로 stringstream의 내용을 byte단위로 가져와서 읽어들인다.
*/
vector<int> parseInts(string str) {
	// Complete this function
    vector<int> answer;
    stringstream ss(str);
    int num;
    char ch;
    
  
    while(ss>>num){
        answer.push_back(num);
        ss>>ch;
    }
    
    return answer;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}