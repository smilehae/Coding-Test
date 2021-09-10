#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<pair<string,pair<string,string>>> myTag;
    int n,q;
    string str,tag,attr,value,dummy;
    string tagNum="";
    char ch;
    cin>>n>>q;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        stringstream ss(str);
        ss>>tag;
        if(tag[1]!='/'){
            tagNum += tag[4];
            cout<<tagNum<<"\n";
            cout<<"\nadding about tag "<<tagNum<<"\n";
            while(ss>>attr){
                ss>>dummy>>ch>>value;
                if(value[value.size()-1]=='>'){
                    value.erase(value.size()-2,value.size());
                }
                else{
                    value.erase(value.size()-1,value.size());
                }
                cout<<attr<<" = "<<value<<"\n";
                myTag.push_back(make_pair(tagNum,make_pair(attr,value)));
                cout<<"putting tag"<<tagNum<<" "<<attr<<" = "<<value<<"\n";
            }
        }
        else{
            int pos = tagNum.find(tag[5]);
            tagNum.erase(pos,1);
            cout<<"pos : "<<pos<<"\n";
            cout<<"tagNum : "<<tagNum<<"\n";
        }
        
    } 

    cout<<"showing vectors...\n";
    for(vector<pair<string,pair<string,string>>>::iterator it=myTag.begin();it!=myTag.end();it++){
        cout<<"tag"<<it->first<<" "<<it->second.first<<" = "<<it->second.second<<"\n";
    }

//지금 생각한 대로 하면, 11번 태그 -> 2번 태그랑 1번 태그 -> 12번 태그랑 구별이 안된다. 구별하려면 , 를 넣거나 추가 조치를 해야 할 것 같은데.. 일단 보자
    for(int i=0;i<q;i++){
        string str;
        string tagNum = "";
        cin>>str;
        for(char elem : str){
            if(elem >= '0' && elem <='9'){
                //cout<<elem<<" ";
                tagNum+=elem;
                // if(myTag.find(tagNum)==myTag.end()){
                //     cout<<"Not Found!\n";
                // }
                // else{
                //     myTag[tagNum]
                // }
            }
        }
        
    }
    return 0;
}
