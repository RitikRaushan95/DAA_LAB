#include <iostream>
#include <vector>
using namespace std;

void findMinMax(const vector<int> &arr, int low, int high, int &min, int &max) {
    if (low == high) {
        min = arr[low];
        max = arr[low];
    }
    else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            max = arr[low];
            min = arr[high];
        } else {
            max = arr[high];
            min = arr[low];
        }
    }
    else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        findMinMax(arr, low, mid, min1, max1);
        findMinMax(arr, mid + 1, high, min2, max2);

        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
    }
}

vector<int> makeArray(int n){
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    return a;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr = makeArray(n);
    int min, max;

    findMinMax(arr, 0,  n-1, min, max);

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}
