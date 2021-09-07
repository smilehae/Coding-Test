#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    int start = 0;
    int end = s.find(":");
    string answer = "";
    string ampm = s.substr(s.size()-2,s.size());
    s.erase(s.size()-2,s.size());
    if(ampm=="PM"){
        int hour = stoi(s.substr(0,2));
        if(hour !=12)hour +=12;
        s.replace(0,2,to_string(hour));
        return s;
    }
    else{
        string hour = s.substr(0,2);
        if(hour == "12"){
            hour ="00";
           s.replace(0,2,hour);
        }
        return s;
    }
    // while(end!=string::npos){
    //     string str = s.substr(start,end);
        
    // }
    return answer;
}


int main(){
    string mystring = "07:05:45PM";
    cout<<timeConversion(mystring);
}