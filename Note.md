# Giai đoạn 1: Nội dung nghiên cứu (Comprehension)

Dưới đây là những kiến thức cốt lõi về thuật toán Quick Sort mà nhóm đã nghiên cứu và áp dụng để triển khai dự án:

## 1. Quick Sort là gì?
**Quick Sort** là một thuật toán sắp xếp hiệu suất cao, hoạt động dựa trên chiến lược **"Chia để trị" (Divide and Conquer)**. 
* Thuật toán bắt đầu bằng việc chọn ra một phần tử làm mốc, gọi là **Chốt (Pivot)**.
* Tiếp theo, tiến hành phân tách mảng ban đầu thành hai mảng con:
  * Một mảng chứa toàn bộ các phần tử **nhỏ hơn hoặc bằng** Pivot.
  * Một mảng chứa toàn bộ các phần tử **lớn hơn hoặc bằng** Pivot.
* Cuối cùng, thuật toán liên tục gọi đệ quy chính nó để lặp lại quá trình phân hoạch và sắp xếp trên các mảng con cho đến khi toàn bộ mảng được sắp xếp hoàn chỉnh.

## 2. Cách chọn Chốt (Pivot)
Thay vì chỉ dùng một cách cố định, trong dự án này nhóm đã tích hợp và cài đặt cả **hai chiến lược phân hoạch kinh điển** để có thể linh hoạt so sánh:
* **Chiến lược Lomuto:** Chọn **phần tử cuối cùng** của mảng/mảng con đang xét làm Pivot. Mã nguồn cực kỳ đơn giản và dễ hiểu cho người mới bắt đầu.
* **Chiến lược Hoare:** Chọn **phần tử đầu tiên** của mảng/mảng con đang xét làm Pivot. Chiến lược này phức tạp hơn một chút nhưng tối ưu hơn trong thực tế nhờ giảm thiểu được số lần hoán đổi (swap).

## 3. Hàm Phân hoạch (Partition) hoạt động ra sao?
Cơ chế "trái tim" của thuật toán thay đổi tùy thuộc vào phương pháp người dùng lựa chọn:

* **Phân hoạch Lomuto (`Partition_Lomuto`):** Dùng một biến `i` để đánh dấu ranh giới các phần tử nhỏ hơn Pivot. Thuật toán duyệt qua đoạn `[l, r-1]` bằng một vòng lặp; mỗi khi gặp phần tử nhỏ hơn hoặc bằng Pivot, nó sẽ dồn phần tử đó về nửa bên trái. Cuối cùng, đặt Pivot vào đúng vị trí ranh giới `i`.
* **Phân hoạch Hoare (`partition_Hoare`):** Sử dụng hai con trỏ `i` (chạy từ trái sang phải) và `j` (chạy từ phải sang trái). Chúng sẽ dừng lại khi phát hiện cặp phần tử nằm sai vị trí (phần tử lớn nằm bên trái, phần tử nhỏ nằm bên phải Pivot) và tiến hành hoán đổi chúng cho nhau. Quá trình lặp lại liên tục cho đến khi hai con trỏ vượt qua nhau.

## 4. Độ phức tạp thuật toán (Complexity)
Việc đánh giá hiệu năng của Quick Sort được thể hiện qua hai khía cạnh:

* **Độ phức tạp thời gian (Time Complexity):**
  * **Trường hợp tốt nhất & Trung bình (Best/Average Case):** $O(n \log n)$. Đạt được khi Pivot chia mảng thành hai nửa tương đối bằng nhau ở mỗi lần đệ quy. 
  * **Trường hợp xấu nhất (Worst Case):** $O(n^2)$. Xảy ra khi mảng đầu vào đã được sắp xếp sẵn và thuật toán rơi vào tình huống phân hoạch bị lệch hoàn toàn (một bên 0 phần tử, bên kia $n-1$ phần tử).
* **Độ phức tạp không gian (Space Complexity):** Tốn $O(\log n)$ trong trường hợp trung bình. Do thuật toán thao tác trực tiếp trên mảng gốc (in-place) và không cần mảng phụ, bộ nhớ chỉ bị tiêu tốn bởi **Ngăn xếp gọi hàm (Call Stack)** để phục vụ cho các lệnh đệ quy.

---

# Giai đoạn 2: Lập trình C++ (Implementation)

Trong giai đoạn này, nhóm chuyển đổi kiến thức lý thuyết thành mã nguồn thực tế bằng ngôn ngữ C++ theo hướng đối tượng (OOP), cho phép người dùng tùy chọn cách thức phân hoạch.

## Danh sách các công việc đã hoàn thành

- [x] **Tối ưu thư viện & Cấu trúc Class:** Sử dụng thư viện tổng hợp `<bits/stdc++.h>` để bao hàm nhanh mọi tiện ích chuẩn. Xây dựng lớp `QuickSortDemo` để bao đóng toàn bộ biến và hàm.
- [x] **Quản lý dữ liệu an toàn:** Sử dụng `vector<int> arr` thay cho mảng thuần túy, kết hợp với hàm `resize()` trong `inputData()` giúp linh hoạt cấp phát bộ nhớ dựa trên số lượng phần tử người dùng nhập, đồng thời tự động dọn dẹp bộ nhớ chống rò rỉ.
- [x] **Đa dạng hóa Thuật toán đệ quy:** Cài đặt thành công hai cặp hàm phân hoạch và đệ quy độc lập: `Partition_Lomuto` / `QuickSort_Lomuto` và `partition_Hoare` / `QuickSort_Hoare` với tham số đầu vào `l` (left) và `r` (right) chuẩn xác.
- [x] **Tính năng "Step-by-step":** Lồng ghép hàm `printArray()` khéo léo vào sau mỗi lệnh `swap()` để hiển thị trực tiếp quá trình di chuyển của các phần tử trên Console.
- [x] **Menu điều hướng:** Hoàn thiện giao diện console tại hàm `startSorting()` cho phép người dùng lựa chọn thuật toán minh họa (Lomuto hoặc Hoare) thông qua việc nhập số.

## Mã nguồn triển khai
<details>
<summary><b>QuickSortDemo.cpp</b></summary>

```cpp
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

    // LOMUTO PARTITION
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

    void startSorting() {
        if (arr.empty()) return; 
        
        int choice;
        cout << "\n========================================\n";
        cout << "   CHOOSE PARTITION METHOD FOR DEMO     \n";
        cout << "========================================\n";
        cout << "1. Lomuto Partition (Last element pivot)\n";
        cout << "2. Hoare Partition (First element pivot)\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        cout << "\n========================================\n";
        cout << "   STARTING QUICK SORT (STEP-BY-STEP)   \n";
        cout << "========================================\n";
        cout << "Initial Array: ";
        printArray();
        
        int r = arr.size() - 1; 

        if (choice == 1) {
            QuickSort_Lomuto(0, r);
        } else if (choice == 2) {
            QuickSort_Hoare(0, r);
        } else {
            cout << "Invalid choice! Defaulting to Hoare Partition...\n";
            QuickSort_Hoare(0, r);
        }
    }

    void displayFinalResult() {
        if (arr.empty()) return;
        cout << "\n========================================\n";
        cout << "             FINAL RESULT               \n";
        cout << "========================================\n";
        cout << "Sorted Array: ";
        printArray();
        cout << "========================================\n";
    }
};

int main() {
    QuickSortDemo qSortProject;

    qSortProject.inputData();
    qSortProject.startSorting();
    qSortProject.displayFinalResult();

    return 0;
}