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


void adjust(vector<int> &a,int i,int n){
    int j=2*i;
    int item=a[i];

    while (j<=n){
        if(j<n && a[j]<a[j+1]) j++;
        if(a[j]<=item) break;
        a[j/2]=a[j];
        j=2*j;
    }
    a[j/2]=item;
}

void heapify(vector<int> &a,int i,int n){
    int j=2*i;
    int item=a[i];
    while(j<=n){
        if(j<n && a[j]<a[j+1])j++;
        if(a[j]<=item)break;
        swap(a[j],a[i]);
        i=j;
        j=2*i;
    }
}

void maxHeapBottomUp(vector<int> &a){
    for(int i=(a.size()-1)/2;i>=1;i--){
        heapify(a,i,a.size()-1);
    }
}

int delMax(vector<int> &a){
    int max=a[1];
    a[1]=a[a.size()-1];
    heapify(a,1,a.size()-1);
    return max;
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
    cout<<"\nMax Heap Array using Bottom-Up Design: ";
    maxHeapBottomUp(a);
    printArray(a);

    cout<<"\nDeleted element is: "<<delMax(a)<<"\n";
    printArray(a);
}
