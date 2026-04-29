

## 1. Mở Đầu & Cú Hook ELI5 (Giải thích như cho trẻ 5 tuổi)
**Thời lượng:** ~2 phút
**Slide:** 1 - 5

**Đức Duy:**
"Chào thầy cô và các bạn. Chào mừng mọi người đến với bài thuyết trình của nhóm mình. Hôm nay, tụi mình sẽ trình bày về một trong những thuật toán sắp xếp kinh điển nhất: **Quick Sort**. Nội dung sẽ đi qua 2 giai đoạn: **Comprehension** (Hiểu lý thuyết) và **Implementation** (Thực hành C++ & Demo).

Sau đây, mình xin nhường lời cho **Hưng** để bắt đầu. Và Hưng sẽ giúp mọi người hiểu bản chất của Quick Sort chỉ trong vòng 30 giây!"

**Hưng:**
"Cảm ơn Duy. Chào mọi người!

**[Ví dụ ELI5]** Trước khi đi vào code phức tạp, các bạn hãy tưởng tượng chúng ta đang **xếp hàng tập thể dục theo chiều cao**. Thay vì đi đo và so sánh từng người rất mất thời gian, bạn lớp trưởng sẽ làm thế này:

Bạn ấy nắm tay kéo ngẫu nhiên một bạn đứng ra làm mốc (gọi là **Pivot**). Sau đó hô: *'Ai thấp hơn mốc thì đứng hết sang trái, ai cao hơn thì qua phải!'*.

Lúc này, hàng tách làm 2 nhóm. Ở mỗi nhóm trái và phải, bạn lớp trưởng lại tiếp tục kéo một bạn làm mốc mới và hô y hệt như vậy. Cứ chia nhỏ ra và xếp, loáng một cái là cả lớp đã đứng đúng thứ tự từ thấp đến cao.

Đó chính xác là chiến lược **Divide & Conquer (Chia để trị)** của Quick Sort: Chọn Pivot, Phân hoạch (Partition), và Đệ quy."

---

## 2. Lý Thuyết Cốt Lõi & Độ Phức Tạp
**Thời lượng:** ~2.5 phút
**Slide:** 7 - 11

**Hưng:**
**[Chuyển Slide 10: Phân hoạch]**
"Việc hô hào '*thấp sang trái, cao sang phải*' trong lập trình gọi là Phân hoạch (Partition). Nhóm mình đã nghiên cứu 2 kỹ thuật phổ biến nhất:

* **🔵 Lomuto Partition:** Chọn phần tử cuối làm mốc. Dùng 1 con trỏ chạy từ đầu đến cuối. Cách này cực kỳ dễ code, dễ hiểu, nhưng lại bắt máy tính phải hoán đổi (swap) vị trí khá nhiều lần dù không cần thiết.
* **🔴 Hoare Partition:** Chọn phần tử đầu làm mốc. Dùng 2 con trỏ chạy ngược chiều nhau từ hai đầu mảng lại. Cách này code lắt léo hơn, nhưng nó tối ưu số lần swap và thực tế chạy nhanh hơn Lomuto khoảng 20%.

**[Chuyển Slide 11: Độ phức tạp]**
Nhờ chia để trị, hiệu năng của Quick Sort rất đáng nể. Thời gian chạy trung bình là $O(n \log n)$. Tuy nó có thể rơi vào trường hợp xấu nhất là $O(n^2)$ (nếu mảng đã sắp xếp sẵn mà mốc chọn không khéo), nhưng trong thực tế, nó vẫn là thuật toán được ưa chuộng bậc nhất vì khả năng tối ưu bộ nhớ đệm (cache-friendly).

Để thấy rõ sức mạnh này trên từng dòng code, mời mọi người quay lại với phần trình bày của Đức Duy."

---

## 3. Cấu Trúc C++ (OOP & Tối ưu)
**Thời lượng:** ~2 phút
**Slide:** 20 - 28

**Đức Duy:**
"Cảm ơn Hưng. Ở Giai đoạn 2, để dễ quản lý và mở rộng dự án, nhóm mình đã đóng gói thuật toán vào class `QuickSortDemo` theo tư duy **Hướng đối tượng (OOP)**.

**[Chuyển Slide 23-24: Tối ưu dữ liệu]**
Thay vì dùng mảng tĩnh dễ gây tràn bộ nhớ, nhóm mình sử dụng cấu trúc `vector<int>` kết hợp hàm `resize()`. Điều này giúp chương trình cấp phát bộ nhớ động linh hoạt đúng với số lượng phần tử mà người dùng nhập vào.

**[Chuyển Slide 26-28: Code Tracking]**
Bên cạnh đó, tụi mình đã lồng ghép một hàm `printArray()` ngay sau mỗi lệnh `swap()` trong 2 hàm phân hoạch Lomuto và Hoare. Mục đích là để chúng ta không chỉ nhận được mảng kết quả cuối cùng, mà còn theo dõi được từng nhịp hoán đổi dữ liệu. Và ngay sau đây, mình sẽ chứng minh điều đó qua phần Demo trực quan."

---

## 4. Demo Tương Tác & Kết Luận
**Thời lượng:** ~2.5 phút
**Slide:** Interactive Visualizer

**Đức Duy:**
**[Chuyển Slide Visualizer]**
"Mọi người đang nhìn thấy giao diện Visualizer do tụi mình xây dựng, chạy song song với logic C++.

**[Thao tác: Chọn thuật toán "Lomuto" -> Bấm "Tạo mảng" -> Bấm "Step" 3 lần]**
Đầu tiên là **Lomuto**. Ở bên phải là code C++ đang chạy. Mình sẽ bấm **Step** để đi từng bước. Các bạn thấy không? Khi lệnh `if` kiểm tra, 2 khối trên màn hình hiện **màu vàng** (So sánh). Khi điều kiện thỏa mãn, dòng code nhảy xuống lệnh `swap()`, khối dữ liệu chuyển sang **màu đỏ** (Hoán đổi).

**[Thao tác: Kéo thanh Tốc độ lên mức giữa -> Bấm "Play"]**
Bây giờ mình cho chạy tự động. Mọi người có thể thấy Lomuto làm việc rất chăm chỉ, các khối màu đỏ (swap) chớp liên tục.

**[Thao tác: Đổi sang thuật toán "Hoare" -> Bấm "Tạo mảng" mới -> Bấm "Play"]**
Nhưng hãy nhớ lại Hưng vừa nói Hoare tối ưu hơn. Mình đổi sang **Hoare**. Hai con trỏ đỏ và xanh chạy từ 2 đầu mảng lướt qua dữ liệu rất nhanh và **chỉ hoán đổi (chớp đỏ) khi thực sự cần thiết**. Số lần swap giảm đi rõ rệt.

**[Kết luận - Quay mặt về khán giả]**
Trực quan hóa thuật toán giúp chúng ta hiểu rằng: Không phải cứ code chạy ra kết quả đúng là xong, mà chọn cách triển khai nào (như Lomuto hay Hoare) sẽ quyết định chương trình của bạn chạy nhanh cỡ nào.

Đó cũng là thông điệp nhóm mình muốn truyền tải qua Mini Project này. Cảm ơn thầy cô và các bạn đã lắng nghe!