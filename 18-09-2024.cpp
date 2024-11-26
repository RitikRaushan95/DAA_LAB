#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMinMax(vector<int>& arr, int low, int high) {
    vector<int> result(2);

    if (low == high) {
        result[0] = arr[low];
        result[1] = arr[low];
        return result;
    }

    if (high == low + 1) {
        result[0] = min(arr[low], arr[high]);
        result[1] = max(arr[low], arr[high]);
        return result;
    }

    int mid = (low + high)/2;

    vector<int> leftResult = findMinMax(arr, low, mid);
    vector<int> rightResult = findMinMax(arr, mid + 1, high);

    result[0] = min(leftResult[0], rightResult[0]);
    result[1] = max(leftResult[1], rightResult[1]);

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    vector<int> result = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << result[0] << endl;
    cout << "Maximum element: " << result[1] << endl;

    return 0;
}
