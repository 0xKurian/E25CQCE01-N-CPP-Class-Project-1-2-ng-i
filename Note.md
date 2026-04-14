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
* **Chiến lược Lomuto:** Chọn **phần tử cuối cùng** của mảng/mảng con làm Pivot. Mã nguồn cực kỳ đơn giản và dễ hiểu cho người mới bắt đầu.
* **Chiến lược Hoare:** Chọn **phần tử đầu tiên** của mảng/mảng con làm Pivot. Chiến lược này phức tạp hơn một chút nhưng tối ưu hơn trong thực tế nhờ giảm thiểu được số lần hoán đổi (swap).

## 3. Hàm Phân hoạch (Partition) hoạt động ra sao?
Cơ chế "trái tim" của thuật toán thay đổi tùy thuộc vào phương pháp người dùng lựa chọn:

* **Phân hoạch Lomuto (`lomutoPartition`):** Dùng một biến `i` để đánh dấu ranh giới các phần tử nhỏ hơn Pivot. Thuật toán duyệt qua mảng bằng một vòng lặp; mỗi khi gặp phần tử nhỏ hơn hoặc bằng Pivot, nó sẽ dồn phần tử đó về nửa bên trái. Cuối cùng, đặt Pivot vào đúng vị trí ranh giới `i + 1`.
* **Phân hoạch Hoare (`hoarePartition`):** Sử dụng hai con trỏ `i` (chạy từ đầu mảng sang phải) và `j` (chạy từ cuối mảng sang trái). Chúng sẽ dừng lại khi phát hiện cặp phần tử nằm sai vị trí (phần tử lớn nằm bên trái, phần tử nhỏ nằm bên phải Pivot) và tiến hành hoán đổi chúng cho nhau. Quá trình lặp lại cho đến khi hai con trỏ vượt qua nhau.

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



## Mã nguồn triển khai
<details>
<summary><b>QuickSortDemo.cpp</b></summary>
