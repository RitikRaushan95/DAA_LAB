#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> & arr){
    for(auto a:arr){
        cout<<a<<" ";
    }
}
void insertionSort(vector<int> & arr){
    for(int i=1;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printArray(arr);
        cout<<"\n";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    insertionSort(arr);
    cout<<"\nSorted array is ";
    printArray(arr);
}