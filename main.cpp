#include <bits/stdc++.h>

using namespace std;

class QuickSortDemo {
private:
    vector<int> arr;

    // In mảng VD: [ 10, 20, 30 ]
    void printArray() {
        cout << "[ ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
        }
        cout << " ]" << endl;
    }

    //  LOMUTO PARTITION
    // l:left
    // r: right
    int Partition_Lomuto(int l, int r) {
        int pivot = arr[r];
        int i = l - 1;
        
        cout << "  -> [Lomuto] Pivot chosen: " << pivot << " (at index " << r << ")" << endl;

        for (int j = l; j < r; j++) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
                
                // In ra bước swap
                if (i != j) {
                    cout << "    + Swapped " << arr[i] << " and " << arr[j] << ": ";
                    printArray();
                }
            }
        }
        ++i; // đưa pivot về giữa
        swap(arr[i], arr[r]);
        
        cout << "  -> Array after Lomuto partitioning: ";
        printArray();

        return i;
    }

    void QuickSort_Lomuto(int l, int r) {
        if (l >= r) return;
        
        cout << "\n[Step] Sorting sub-array from " << l << " to " << r << ":" << endl;
        int p = Partition_Lomuto(l, r);
        QuickSort_Lomuto(l, p - 1);
        QuickSort_Lomuto(p + 1, r);
    }


    // HOARE PARTITION
    // l:left
    // r: right
    int partition_Hoare(int l, int r) {
        int pivot = arr[l];
        int i = l - 1, j = r + 1;
        
        cout << "  -> [Hoare] Pivot chosen: " << pivot << " (at index " << l << ")" << endl;

        while (1) {
            do {
                ++i;
            } while (arr[i] < pivot);
            
            do {
                --j;
            } while (arr[j] > pivot);
            
            if (i < j) {
                swap(arr[i], arr[j]);
                cout << "    + Swapped " << arr[i] << " and " << arr[j] << ": ";
                printArray();
            } else {
                cout << "  -> Array after Hoare partitioning: ";
                printArray();
                return j;
            }
        }
    }

    void QuickSort_Hoare(int l, int r) {
        if (l >= r) return;
        
        cout << "\n[Step] Sorting sub-array from " << l << " to " << r << ":" << endl;
        int p = partition_Hoare(l, r);
        QuickSort_Hoare(l, p);
        QuickSort_Hoare(p + 1, r);
    }

    public:
    void inputData() {
        int inputSize;
        cout << "Enter the number of elements: ";
        cin >> inputSize;
        
        if (inputSize <= 0) {
            cout << "Error: Size must be greater than 0!" << endl;
            return;
        }

        arr.resize(inputSize); 
        for (int i = 0; i < inputSize; i++) {
            cout << "Enter element [" << i << "]: ";
            cin >> arr[i];
        }
    }
    void inputData() {
        int inputSize;
        cout << "Enter the number of elements: ";
        cin >> inputSize;
        
        if (inputSize <= 0) {
            cout << "Error: Size must be greater than 0!" << endl;
            return;
        }

        arr.resize(inputSize); 
        for (int i = 0; i < inputSize; i++) {
            cout << "Enter element [" << i << "]: ";
            cin >> arr[i];
        }
    }
    void inputData() {
        int inputSize;
        cout << "Enter the number of elements: ";
        cin >> inputSize;
        
        if (inputSize <= 0) {
            cout << "Error: Size must be greater than 0!" << endl;
            return;
        }

        arr.resize(inputSize); 
        for (int i = 0; i < inputSize; i++) {
            cout << "Enter element [" << i << "]: ";
            cin >> arr[i];
        }
    }
};