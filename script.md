## 1. Mở Đầu & Cú Hook ELI5 (Giải thích đơn giản)
**Thời lượng:** ~2 phút
**Slide:** 1 - 5

**Đức Duy:**
"Chào thầy cô và các bạn. Chào mừng mọi người đến với bài thuyết trình của nhóm mình. Hôm nay, tụi mình sẽ trình bày về một trong những thuật toán sắp xếp kinh điển nhất: **Quick Sort**. Nội dung sẽ đi qua 2 giai đoạn: **Comprehension** (Hiểu lý thuyết) và **Implementation** (Thực hành C++ & Demo).

Để bắt đầu, mình sẽ giải thích bản chất của Quick Sort thông qua một hình ảnh mà chắc hẳn lớp mình ai cũng quen thuộc: **Thầy giáo đang sắp xếp một xấp bài kiểm tra C++ vừa chấm xong theo điểm số từ thấp đến cao**.

**[Ví dụ ELI5]** Hãy tưởng tượng thầy đang cầm trên tay 50 tờ bài làm lộn xộn. Thay vì thầy phải ngồi lật từng tờ so sánh từ đầu đến cuối rất tốn sức, thầy sẽ áp dụng tư duy của một lập trình viên:

Đầu tiên, thầy rút đại một tờ bài bất kỳ ra làm 'mốc' (**Pivot**). Giả sử tờ đó được 7 điểm.
Sau đó, thầy chia xấp bài thành 2 chồng:
* Chồng bên trái là những bài **từ 7 điểm trở xuống**.
* Chồng bên phải là những bài **trên 7 điểm**.

Lúc này, thầy chưa có một xấp bài hoàn chỉnh, nhưng thầy đã phân loại được nhóm điểm cao và điểm thấp. Tiếp theo, thầy chỉ cần nhờ hai bạn trợ giảng làm y hệt như vậy với hai chồng bài nhỏ đó. Cứ chia nhỏ, chia nhỏ mãi cho đến khi mỗi chồng chỉ còn đúng 1 tờ bài duy nhất. Khi gộp lại theo đúng thứ tự trái - phải, xấp bài đã được sắp xếp xong. Đó chính là triết lý **Divide & Conquer (Chia để trị)** của Quick Sort."

---

## 2. Lý Thuyết Cốt Lõi & Độ Phức Tạp
**Thời lượng:** ~2.5 phút
**Slide:** 6 - 10

**Đức Duy:**
**[Chuyển Slide 9: Cơ chế Phân hoạch]**
"Việc hô hào '*thấp sang trái, cao sang phải*' trong lập trình gọi là Phân hoạch (Partition). Nhóm mình đã nghiên cứu 2 kỹ thuật phổ biến nhất:

* **🔵 Lomuto Partition (Bên trái):** Chọn phần tử cuối làm mốc. Dùng 1 con trỏ chạy từ đầu đến cuối. Cách này cực kỳ dễ code, dễ hiểu, nhưng lại bắt máy tính phải hoán đổi (swap) vị trí khá nhiều lần dù không cần thiết.
* **🔴 Hoare Partition (Bên phải):** Chọn phần tử đầu làm mốc. Dùng 2 con trỏ chạy ngược chiều nhau từ hai đầu mảng lại. Cách này code lắt léo hơn, nhưng tối ưu số lần swap và chạy thực tế nhanh hơn Lomuto khoảng 20%.

**[Chuyển Slide 10: Độ phức tạp]**
Nhờ chia để trị, hiệu năng của Quick Sort rất đáng nể. Thời gian chạy trung bình là $O(n \log n)$. Tuy nó có thể rơi vào trường hợp xấu nhất là $O(n^2)$ (nếu mảng đã sắp xếp sẵn mà mốc chọn không khéo), nhưng thực tế nó vẫn là thuật toán được ưa chuộng nhất vì khả năng tối ưu bộ nhớ đệm.

Để thấy rõ sức mạnh này trên từng dòng code C++, mời mọi người theo dõi phần trình bày của bạn **Hưng**."

---

## 3. Cấu Trúc C++ (OOP & Tối ưu)
**Thời lượng:** ~2 phút
**Slide:** 11 - 20

**Hưng:**
"Cảm ơn Duy. Ở Giai đoạn 2, để dễ quản lý và mở rộng dự án, nhóm mình đã đóng gói thuật toán vào class `QuickSortDemo` theo tư duy **Hướng đối tượng (OOP)**.

**[Chuyển Slide 13-14: Checklist công việc]**
Thay vì dùng mảng tĩnh dễ gây tràn bộ nhớ, nhóm mình sử dụng cấu trúc `vector<int>` kết hợp hàm `resize()`. Điều này giúp chương trình cấp phát bộ nhớ động linh hoạt đúng với số lượng phần tử mà người dùng nhập vào.

**[Chuyển Slide 16-20: Phân tích mã nguồn]**
Bên cạnh đó, tụi mình lồng ghép hàm `printArray()` ngay sau mỗi lệnh `swap()` trong 2 hàm phân hoạch Lomuto và Hoare. Mục đích là để chúng ta không chỉ nhận được mảng kết quả cuối cùng, mà còn theo dõi được từng nhịp hoán đổi dữ liệu. Và ngay sau đây, mình sẽ chứng minh điều đó qua phần Demo trực quan."

---

## 4. Demo Tương Tác & Kết Luận
**Thời lượng:** ~2.5 phút
**Slide:** 21 - 23

**Hưng:**
**[Chuyển Slide 21: Minh họa Visualizer]**
"Mọi người đang nhìn thấy giao diện Visualizer do tụi mình xây dựng, chạy song song với logic C++.

**[Thao tác: Chọn thuật toán "Lomuto" -> Bấm "Tạo mảng" -> Bấm "Step" 3 lần]**
Đầu tiên là **Lomuto**. Ở bên phải là code C++ đang chạy. Mình sẽ bấm **Step** để đi từng bước. Các bạn thấy không? Khi lệnh `if` kiểm tra, 2 khối trên màn hình hiện **màu vàng (So sánh)**. Khi điều kiện thỏa mãn, dòng code nhảy xuống lệnh `swap()`, khối dữ liệu chuyển sang **màu đỏ (Hoán đổi)**.

**[Thao tác: Kéo thanh Tốc độ lên mức giữa -> Bấm "Play"]**
Bây giờ mình cho chạy tự động. Mọi người có thể thấy Lomuto làm việc rất chăm chỉ, các khối màu đỏ chớp liên tục.

**[Thao tác: Đổi sang thuật toán "Hoare" -> Bấm "Tạo mảng" mới -> Bấm "Play"]**
Nhưng hãy nhớ lại Duy vừa nói Hoare tối ưu hơn. Mình đổi sang **Hoare**. Hai con trỏ đỏ và xanh chạy từ 2 đầu mảng lướt qua dữ liệu rất nhanh và **chỉ hoán đổi khi thực sự cần thiết**. Số lần swap giảm đi rõ rệt.

**[Chuyển Slide 22-23: Kết luận & Cảm ơn]**
Trực quan hóa thuật toán giúp chúng ta hiểu rằng: Không phải cứ code chạy ra kết quả đúng là xong, mà chọn cách triển khai nào (như Lomuto hay Hoare) sẽ quyết định chương trình của bạn chạy nhanh cỡ nào.

Đó cũng là thông điệp nhóm mình muốn truyền tải qua Mini Project này. Cảm ơn thầy cô và các bạn đã lắng nghe!"