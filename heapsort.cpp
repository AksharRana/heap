#include<iostream>
using namespace std;
void maxheapify(int A[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    while(l<n&&A[l]>A[largest]){
        largest=l;
    }
    while(r<n&&A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        maxheapify(A,n,largest);
    }
}
void heapsort(int A[],int n){
    for(int i=n/2-1;i>=0;i--){        //Building the max heap
        maxheapify(A,n,i);
    }
    for(int i=n-1;i>=0;i--){          //Deletion from the heap
        swap(A[0],A[i]);
        maxheapify(A,i,0);
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    int n=5;
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}