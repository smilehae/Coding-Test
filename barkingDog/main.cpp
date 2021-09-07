#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int * arr,int num){
    for(int i=0;i<num;i++){
        for(int j=0;j<num-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수
int n=10;

//정렬이 되어 있는 start~mid와  mid~end를 합친다.
void merge(int start,int end){
    int mid = (start+end)/2;
    int pLeft = start;
    int pRight = mid;
    int pCur = start;
    while(1){
        if(pLeft>=mid && pRight>=end) {
            break;
        }
        if(pLeft>=mid){
            tmp[pCur] = arr[pRight++];
        }
        else if(pRight>=end){
            tmp[pCur] = arr[pLeft++];
        }
        else if(arr[pLeft]> arr[pRight]){
            tmp[pCur] = arr[pRight++];
        }
        else{
            tmp[pCur] = arr[pLeft++];
        }
        pCur++;
    }
    for(int i=start;i<end;i++){
        arr[i] = tmp[i];
    }

}

void merge_sort(int start,int end){
    //길이가 1일 경우 리턴.
    if(end-start==1) return;

    int mid = (start+end)/2;
    merge_sort(start,mid); //여기서 처음 포함, 끝 불포함.
    merge_sort(mid,end);
    merge(start,end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    merge_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}