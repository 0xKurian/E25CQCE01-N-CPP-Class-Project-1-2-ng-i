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