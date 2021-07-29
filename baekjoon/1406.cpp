/*
    백준 1406번. 에디터.
    영어 소문자를 기록할 수 있는 간단한 편집기 만들기.
    커서가 문장의 맨 앞, 맨 뒤, 문장 사이에 위치할 수 있다.
    최대 60만글자를 입력할 수 있고,  0.3초 안에 끝내야함

*/

#include<cstdio>
#include<list>

using namespace std;
list<char> L;

int main(){
    char initString[10001]={};
    int m;
    list<char>::iterator it;
    scanf("%s",initString);
    scanf("%d",&m);
    getchar();

    int count = 0;
    while(initString[count]!=0){
        L.push_back(initString[count]);
        count++;
    }
    it = L.end();

    for(int i=0;i<m;i++){
        char order;
        scanf("%c",&order);
        getchar();
        if(order=='L'){
            if(it!=L.begin()){
                it--;
                printf("moving left! it's pointing %c\n",*it);
            }
            else{
                printf("it's already at begin!\n");
            }
        }
        else if(order=='D'){
            //end가기 전까지만 이동가능!!
            if(it!=(L.end())){
                it++;
                printf("moving right! it's pointing %c\n",*it);
            }
            else{
                printf("it's already at the end!\n");
            }
        }
        else if(order=='P'){
            char newWord;
            scanf("%c",&newWord);
            getchar();
            L.insert(it,newWord);
            printf("now became ");
            for(char c:L){
                printf("%c ",c);
            }
            puts("");
        }
        else if(order=='B'){
            printf("position : %c\n",*it);
            if(it!=L.begin()){
                 printf("erased %c \n",*it);
                 list<char>::iterator it2;
                 it2 = it;
                L.erase(prev(it2));
                
                 printf("now became ");
                 for(char c:L){
                     printf("%c ",c);
                  }
            puts("");
            printf("iterator is pointing %c\n",*it);
            }
            else{
                printf("it's already begin \n");
            }
           
        }

    }

    for(char c:L){
        printf("%c ",c);
    }


}