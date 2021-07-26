#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
   int arr[4];
   int count;

  for(int i=1;i<=3;i++){
    scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);
    count = arr[0]+arr[1]+arr[2]+arr[3];
    switch(count){
    case 0: 
        puts("D");
        break;
    case 1:
        puts("C");
        break;
     case 2:
        puts("B");
        break;       
    case 3:
        puts("A");
        break;
    case 4:
        puts("E");
        break;
    }
  }

}