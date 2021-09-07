#include<iostream>

using namespace std;

int arr[1000001];
int tmp[1000001];

void merge(int start, int end){
    //start~mid-1, mid~end-1까지를 비교해서 하나의 arr로 만든다.
    int mid = (start+end)/2;
    int leftP=start;
    int rightP=mid;
    for(int i=start;i<end;i++){
        if(leftP==mid){
            tmp[i] = arr[rightP++];
        }
        else if(rightP==end){
            tmp[i] = arr[leftP++];
        }
        else if(arr[leftP]> arr[rightP]){
            tmp[i] = arr[rightP++];
        }
        else{
            tmp[i] = arr[leftP++];
        }
    }

    for(int i=start;i<end;i++){
        arr[i] = tmp[i];
    }
}

//start에서 end 직전까지 sort.
void merge_sort(int start,int end){
    if(end-start==1) return; //길이가 1이면 리턴.
    int mid = (start+end)/2;
    merge_sort(start,mid);
    merge_sort(mid,end);
    merge(start,end);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}