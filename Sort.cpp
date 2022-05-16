#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void InsertSort(vector<int> &arr, const int &len) {
    for(int i = 2, j = 1; i <= len; i++) {
        for(j = i, arr[0] = arr[i]; arr[j - 1] > arr[0] && j > 1; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = arr[0];
    }
}

void ShellSort(vector<int> &arr, const int &len) {
    for(int pace = len / 2; pace > 0; pace--) {
        for(int i = pace + 1, j = 0; i <= len; i++) {
            arr[0] = arr[i];
            for(j = i - pace; j > 0 && arr[j] > arr[0]; j -= pace) {
                arr[j + pace] = arr[j];
            }
            arr[j + pace] = arr[0];
        }
    }
}

void BubbleSort(vector<int> &arr, const int &len) {
    for(int cnt = 0; cnt < len - 1; cnt++) {
        bool flag = false;
        for(int i = len - 1; i > cnt; i--) {
            if(arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
        if(flag == false) {
            break;
        }
    }
}

int Partition(vector<int> &arr, int low, int high) {
    arr[0] = arr[low];
    while(low < high) {
        while(low < high && arr[high] >= arr[0]) {
            high--;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= arr[0]) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = arr[0];
    return low;
}

void QuickSort(vector<int> &arr, const int &low, const int &high) {
    if(low < high) {
        int pos = Partition(arr, low, high);
        QuickSort(arr, low, pos - 1);
        QuickSort(arr, pos + 1, high);
    }
}

void SelectSort(vector<int> &arr, const int &len) {
    for(int i = 1; i <= len; i++) {
        int tmp = arr[i], key = i;
        for(int j = i + 1; j <= len; j++) {
            if(arr[j] < tmp) {
                tmp = arr[j];
                key = j;
            }
        }
        swap(arr[i], arr[key]);
    }
}

void AdjustMaxHeap(vector<int> &arr, const int &root, const int &len) {
    for(int i = root, j = root * 2; j <= len; j *= 2) {
        if(j < len && arr[j] < arr[j + 1]) {
            j++;
        }
        if(arr[j] < arr[i]) {
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void BuildMaxHeap(vector<int> &arr, const int &len) {
    for(int i = len / 2; i > 0; i--) {
        AdjustMaxHeap(arr, i, len);
    }
}

void MaxHeapSort(vector<int> &arr, const int &len) {
    BuildMaxHeap(arr, len);
    for(int i = len; i > 0; i--) {
        swap(arr[i], arr[1]);
        AdjustMaxHeap(arr, 1, i - 1);
    }
}

int main() {
    vector<int> arr{0, 7, 6, 5, 4, 3, 2, 1};
    // InsertSort(arr, arr.size() - 1);
    // ShellSort(arr, arr.size() - 1);
    // BubbleSort(arr, arr.size() - 1);
    // QuickSort(arr, 1, arr.size() - 1);
    SelectSort(arr, arr.size() - 1);
    MaxHeapSort(arr, arr.size() - 1);
    for(int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
