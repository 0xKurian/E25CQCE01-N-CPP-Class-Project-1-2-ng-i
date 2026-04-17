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

//  PARTITION
// l:left
// r: right
namespace Lomuto_Partition {
    int Partition (int a[], int l, int r){
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
    void QuickSort(int a[], int l, int r)
    {
        if (l>r) return;
        int p=Partition(a, l, r);
        QuickSort(a, l, p-1);
        QuickSort(a, p+1, r);
    }
}

// HOARE PARTITION
// l:left
// r: right
namespace Hoare_partition{
    int partition(int a[], int l, int r){
        int pivot=a[l];
        int i=l-1, j=r+1;
        while(1){
            do{
                ++i;
            } while (a[i]<pivot);
            do{
                --j;
            } while (a[j]>pivot);
            if (i<j) swap(a[i], a[j]);
            else return j;
        }
    }
    void QuickSort(int a[], int l, int r){
        if (l>=r) return;
        int p=partition(a, l, r);
        QuickSort(a, l, p);
        QuickSort(a, p+1, r);
    }
}