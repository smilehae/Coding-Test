#include <cstdint>
#include <string>
#include<iostream>

using namespace std;

std::string add_binary(uint64_t a, uint64_t b) {
    string answer ="";
    uint64_t result = a + b;
    int rest;
    if(result == 0) return "0";
    while(result > 0 ){
        if(result % 2 == 1){
           // answer += "1";
           answer.insert(0,1,'1');
        }
        else{
           // answer += "0";
           answer.insert(0,1,'0');

        }
        result = result/2;
    }
    
    return answer;
}

int main(){
    cout<<add_binary(1,18)<<endl;
}