#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool solution(vector<string> phone_book){
    bool answer = true;
    unordered_map<string,int> mymap;
    
    for(string elem:phone_book){
        mymap[elem]=1;
    }
    // for(unordered_map<string,int>::iterator it=mymap.begin();it!=mymap.end();it++){
    //     cout<<it->first<<":"<<it->second<<"\n";
    // }

    for(int i=0;i<phone_book.size();i++){
        string phone_num="";
        for(int j=0;j<phone_book[i].size();j++){
            phone_num+=phone_book[i][j];
            if(mymap.find(phone_num)!=mymap.end()){
                if(phone_num != phone_book[i]){
                    answer=false;
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<string> myphone= {"119", "97674223", "1195524421"};
    cout<<solution(myphone);
}