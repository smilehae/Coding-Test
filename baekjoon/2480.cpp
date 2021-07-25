#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
   int arr[3];
   int money;
   scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);

   sort(arr,arr+3);

   if(arr[0]==arr[1] && arr[1]==arr[2]){
       money = 10000 + arr[0]*1000;
   }
   else if(arr[0] == arr[1] || arr[1]==arr[2]){
       money = 1000 + arr[1]*100;
   }
   else{
       money = arr[2]*100;
   }


    printf("%d",money);

}