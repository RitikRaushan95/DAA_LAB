#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int l, int h) {
    int p = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter all the elements in array \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entered array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quickSort(arr,0,4);
    cout<<"Sorted array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}