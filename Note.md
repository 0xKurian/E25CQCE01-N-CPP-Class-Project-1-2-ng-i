# Giai đoạn 1: Nội dung nghiên cứu (Comprehension)

Dưới đây là những kiến thức cốt lõi về thuật toán Quick Sort mà nhóm đã nghiên cứu và áp dụng để triển khai dự án:

## 1. Quick Sort là gì?
**Quick Sort** là một thuật toán sắp xếp hiệu suất cao, hoạt động dựa trên chiến lược **"Chia để trị" (Divide and Conquer)**. 
* Thuật toán bắt đầu bằng việc chọn ra một phần tử làm mốc, gọi là **Chốt (Pivot)**.
* Tiếp theo, tiến hành phân tách mảng ban đầu thành hai mảng con:
  * Một mảng chứa toàn bộ các phần tử **nhỏ hơn** Pivot.
  * Một mảng chứa toàn bộ các phần tử **lớn hơn** Pivot.
* Cuối cùng, thuật toán liên tục gọi đệ quy chính nó để lặp lại quá trình phân hoạch và sắp xếp trên các mảng con cho đến khi toàn bộ mảng được sắp xếp hoàn chỉnh.

## 2. Cách chọn Chốt (Pivot)
Để giữ cho mã nguồn đơn giản, tường minh và dễ hiểu nhất đối với người mới tiếp cận thuật toán, nhóm quyết định chọn **phần tử cuối cùng** của mảng (hoặc mảng con) làm Pivot.

## 3. Hàm Phân hoạch (Partition) hoạt động ra sao?
Hàm Partition đóng vai trò là "trái tim" của thuật toán Quick Sort. Cơ chế hoạt động của nó như sau:
* Hàm sử dụng một biến chốt giữ (trong code là biến `i`) để theo dõi vị trí ranh giới cuối cùng của các phần tử nhỏ hơn Pivot.
* Khi dùng một vòng lặp duyệt qua mảng, nếu phát hiện phần tử nào có giá trị **nhỏ hơn hoặc bằng** Pivot, hệ thống sẽ tiến hành **đổi chỗ (swap)** phần tử đó với phần tử ở vị trí `i + 1` (sau khi đã tăng `i`).
* Kết thúc vòng lặp, thao tác cuối cùng là đưa Pivot (đang nằm ở cuối mảng) vào vị trí `i + 1`. Lúc này, Pivot đã được đặt vào **đúng vị trí định danh** của nó: chia cắt mảng thành hai nửa trái (nhỏ hơn) và phải (lớn hơn).

## 4. Độ phức tạp thuật toán (Complexity)
Việc đánh giá hiệu năng của Quick Sort được thể hiện qua hai khía cạnh:

* **Độ phức tạp thời gian (Time Complexity):**
  * **Trường hợp tốt nhất & Trung bình (Best/Average Case):** $O(n \log n)$. Đạt được khi Pivot chia mảng thành hai nửa tương đối bằng nhau ở mỗi lần đệ quy.
  * **Trường hợp xấu nhất (Worst Case):** $O(n^2)$. Xảy ra khi mảng đầu vào đã được sắp xếp sẵn (thuận hoặc nghịch) và thuật toán luôn chọn phần tử cuối làm Pivot. Điều này dẫn đến việc phân hoạch bị lệch hoàn toàn (một bên 0 phần tử, bên kia $n-1$ phần tử).
* **Độ phức tạp không gian (Space Complexity):** * Tốn $O(\log n)$ trong trường hợp trung bình. Tuy Quick Sort sắp xếp trực tiếp trên mảng gốc (in-place) và không cần mảng phụ, bộ nhớ vẫn bị tiêu tốn bởi **Ngăn xếp gọi hàm (Call Stack)** để phục vụ cho các lệnh gọi đệ quy.
# Giai đoạn 2: Lập trình C++ (Implementation)

Trong giai đoạn này, nhóm tập trung vào việc chuyển đổi các kiến thức lý thuyết từ Giai đoạn 1 thành mã nguồn thực tế sử dụng ngôn ngữ C++ theo hướng đối tượng (OOP).

## Danh sách các công việc đã hoàn thành

- [x] **Tạo cấu trúc Class (Class Skeleton):** Xây dựng lớp `QuickSortDemo` để bao đóng toàn bộ dữ liệu và phương thức.
- [x] **Khai báo Private Data:** Sử dụng `std::vector` để lưu trữ mảng dữ liệu và biến lưu kích thước mảng nhằm tối ưu bộ nhớ.
- [x] **Viết Public Method - inputData():** Hàm cho phép người dùng chủ động nhập số lượng và giá trị các phần tử.
- [x] **Viết thuật toán chính - partition() & quickSort():** Cài đặt logic đệ quy và phân hoạch dựa trên Pivot là phần tử cuối.
- [x] **Thêm tính năng "Step-by-step":** Tích hợp việc in trạng thái mảng sau mỗi lần hoán đổi (swap) để theo dõi luồng chạy.
- [x] **Viết Public Method - displayFinalResult():** Hàm hiển thị kết quả cuối cùng sau khi đã sắp xếp.

## Mã nguồn triển khai
<details>
<summary><b>QuickSortDemo.cpp</b></summary>