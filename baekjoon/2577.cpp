/*
    백준 2577. 세 자연수 ABC를 계산한 결과에서 0~9까지의 숫자가 몇번씩 쓰였는지 계산
*/

#include<cstdio>
#include<string>

int main(){
    int a,b,c;
    std::string mul;
    int arr[10]={};
    scanf("%d %d %d",&a,&b,&c);
    mul = std::to_string(a*b*c);

    //string 안의 char들을 한개씩 도는 3가지 방법
    /*
    for(char s:mul){
        printf("%d ",s-'0');
    }
    puts("");
    for(int i=0;i<mul.size();i++){
        printf("%d ",mul[i]-'0');
    }
    puts("");

    std::string::iterator it;
    for(it=mul.begin();it!=mul.end();it++){
        printf("%d ", *it-'0');
    }
    */

   for(char s:mul){
       arr[s-'0']++;
   }
    for(int i=0;i<10;i++){
        printf("%d\n",arr[i]);
    }
}