/*
    프로그래머스 LV2 : 해시 : 전화번호 목록
    
    전화번호에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어 인 것 확인
    구조대 119
    지영석 11 9552 4421
    -> 접두어 true

    phone_book의 string 중 하나라도 접두어인 경우가  있으면 false, 그렇지 않으면 true

*/

#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

// 이렇게 접두어가 일치해야함.
vector<string>myphone = {"5633333","11921119","563333333333333333","14","23","114353443"};

bool solution(vector<string>phone_book){
    bool answer = true;
    vector<string>::iterator it;
    string left;
    string right;
    bool misMatch = false;

    //데이터가 100만이라 신중할 필요 o
    //처음에 정렬 : string이라서 접두사가 일치한다면 서로 근접함
    sort(phone_book.begin(),phone_book.end());
    //두개씩 보면서, 첫번째거 suffix가 두번째 꺼가 되는지 보면 될 듯
    for(int i=0;i<phone_book.size()-1;i++){
        left = phone_book[i];
        right = phone_book[i+1];
        //cout<<"comparing "<<left<<" "<<right<<endl;
        misMatch = false;
        for(int j=0;j<left.size();j++){
            if(left[j]!=right[j]){
               // cout<<"mismatch at index "<<j<<endl;
                misMatch = true;
                break;
            }
        }
        if(!misMatch){
            //cout<<"matching prefix"<<endl;
            answer = false;
            break;
        }
    }

   

    return answer;
}

int main(){
    cout<<solution(myphone)<<endl;
}