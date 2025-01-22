// #include <iostream>
// #include <vector>

// using namespace std;

// void makeArray(vector<int> &a, int n){
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
// }
// void printArray(vector<int> &a){
//     for(int i=0;i<a.size();i++){
//         cout<<a[i]<<" ";
//     }
// }
// void insertElement(vector<int> &a, int idx, int x) {
//     int item=x;
//     int i=idx;
//     while(i>0 && a[(i-1)/2]<item) {
//         a[i]=a[(i-1)/2];
//         i=(i-1)/2;
//     }
//     a[i] = item;
// }

// void maxHeapTopDown(vector<int> &a){
//     for(int i=1;i<a.size();i++){
//         insertElement(a,i,a[i]);
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter the size of Vector:";
//     cin>>n;
//     vector<int> a(n);
//     vector<int> b=a;
//     cout<<"Enter Array elaements: ";
//     makeArray(a,n);
//     cout<<"Entered Array is: ";
//     printArray(a);
//     maxHeapTopDown(a);
//     cout<<"Max Heap Array using Top Down Design: ";
//     printArray(a);
// }






#include <iostream>
#include <vector>

using namespace std;

void makeArray(vector<int> &a, int n){
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }
}
void printArray(vector<int> &a){
    for(int i=1;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
void insertElement(vector<int> &a, int idx, int x) {
    int item=x;
    int i=idx;
    while(i>1 && a[i/2]<item) {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i] = item;
}

void maxHeapTopDown(vector<int> &a){
    for(int i=2;i<=a.size();i++){
        insertElement(a,i,a[i]);
    }
}

int main(){
    int n;
    cout<<"Enter the size of Vector:";
    cin>>n;
    vector<int> a;
    cout<<"Enter Array elaements: ";
    makeArray(a,n);
    cout<<"Entered Array is: ";
    printArray(a);
    maxHeapTopDown(a);
    cout<<"\nMax Heap Array using Top Down Design: ";
    printArray(a);
}