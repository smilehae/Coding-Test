#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(string new_id) {
    string answer = "";
    int periodCount = 0;
    string::iterator periodPos;


    for(string::iterator it=new_id.begin();it!=new_id.end();it++){
        //1단계. 대문자를 소문자로.
        if(*it>='A' && *it <='Z'){
            *it += ('a'-'A');
        }

        //2단계. 특수문자 없애기
        if(*it<'a' || *it>'z'){
            if(*it<'0' || *it>'9'){
                if(*it!='-' && *it!='_' &&*it!='.'){
                    cout<<"found it. erase\n";
                    //erase하면 바로 뒤로 iterator로 넘어가므로, it--를 해서 막는다.
                    it = new_id.erase(it);
                    it--;
                }
            }
        }

    }
    cout<<"after level 2 "<<new_id<<"\n";

    for(string::iterator it=new_id.begin();it!=new_id.end();it++){

      if(periodCount==0 && *it=='.'){
          cout<<"changing periodPos.\n";
            periodPos = it;
        }
        if(*it == '.'){
            periodCount++;
            cout<<"this is .  count became "<<periodCount<<"\n";

        }

        //전에는 .가 있었다. & 지금 자리는 . 아님
        if(periodCount!=0 && *it=='.' && *next(it)!='.'){
            cout<<"erasing "<<periodCount-1<<". \n";
            it = new_id.erase(periodPos,periodPos+periodCount-1);
            cout<<new_id<<"\n";
            periodCount=0; 

        }

    }
    cout<<"level 3 : "<<new_id<<"\n";


//4단계  : 마침표 제거
    if(new_id[0]=='.'){
        new_id.erase(0,1);
    }

    if(new_id[new_id.size()-1]=='.'){
        cout<<"erasing .\n";
        new_id.erase(new_id.size()-1,1);
    }

    cout<<"level 4 : "<<new_id<<"\n";

    if(new_id=="") new_id="a";



    cout<<"id is "<<new_id<<"\n";

    new_id = new_id.substr(0,15);

    if(new_id[new_id.size()-1]=='.'){
        new_id.erase(new_id.size()-1,1);
    }

    cout<<"level 6 : "<<new_id<<"\n";

    
    if(new_id.size()<=2){
        while(new_id.size()<3){
            new_id.insert(new_id.end(),new_id[new_id.size()-1]);
        }

    }
    cout<<"level 7 : "<<new_id<<"\n";

    answer = new_id;
    return answer;
}

int main(){
    string str="abcdefghijklmn.p";
    cout<<solution(str);
}