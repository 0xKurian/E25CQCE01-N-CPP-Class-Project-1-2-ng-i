#include <bits/stdc++.h>

using namespace std;

class QuickSortDemo{
    private:
    vector<int> arr;

    // In mảng VD: [ 10, 20, 30 ]
    void printArray(){
        cout << "[ ";
        for (int i=0; i<arr.size(); i++){
            cout << arr[i] << (i<arr.size()-1 ? ", " : "");
        }
        cout << " ]" << endl;
    }
};

// LOMUTO PARTITION
// l:left
// r: right
int LomutoPartition (int a[], int l, int r){
    int pivot=a[r];
    int i=l-1;
    for (int j=l; j<r; j++){
        if(a[i]<=pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;//đưa pivot về giữa
}
void Lomuto_QuickSort(int a[], int l, int r)
{
    if (l>r) return;
    int p=LomutoPartition(a, l, r);
    Lomuto_QuickSort(a, l, p-1);
    Lomuto_QuickSort(a, p+1, r);
}