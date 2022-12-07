#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class heap{
    int arr[100];
    int size;
    public:
    heap(){
        arr[0]=-1;
        size=0;
    }
    
    void insert(int x){
        size++;
        int idx=size;
        arr[size]=x;
        while(idx>1){
            int parent=idx/2;
            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
    }
    void printlist(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleted(){
     arr[1]=arr[size];
        size--;
        int i=1;
        while(i<=size){
            int prev=i;
            int left=2*i;
            int right=2*i+1;
            if(left<=size && arr[left]>arr[i]){
                i=left;
            }
            if(right<=size && arr[right]>arr[i]){
                i=right;
            }
            if(i!=prev){
                swap(arr[prev],arr[i]);
            }
            else{
                return;
            }
        }
    }
};
int main(){
    heap h;
    h.insert(10);
    h.insert(15);
    h.insert(13);
    h.insert(12);
    h.printlist();
    h.deleted();
    h.printlist();
}