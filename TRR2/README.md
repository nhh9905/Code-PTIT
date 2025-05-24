# Các khái niệm cơ bản

<details>
<summary><h2>Định nghĩa đồ thị</h2></summary>
<p>

- Đơn đồ thị vô hướng: ![alt text](./img/image.png)
- Đa đồ thị vô hướng: ![alt text](./img/image-1.png)
- Giả đồ thị vô hướng: ![alt text](./img/image-2.png)
- Đơn đồ thị có hướng: ![alt text](./img/image-3.png)
- Đa đồ thị có hướng: ![alt text](./img/image-4.png)
## Một số thuật ngữ cơ bản trên đồ thị vô hướng
- Bậc của đỉnh, đỉnh cô lập, đỉnh treo: ![alt text](./img/image-5.png)
- Định lý về tổng bậc các đỉnh: ![alt text](./img/image-6.png)
- Đường đi, chu trình: ![alt text](./img/image-7.png)
Ví dụ: ![alt text](./img/image-8.png)
- Liên thông: ![alt text](./img/image-9.png)
Ví dụ: ![alt text](./img/image-10.png)
- Cầu, trụ: ![alt text](./img/image-11.png)
## Một số thuật ngữ cơ bản trên đồ thị có hướng
- Bán bậc của đỉnh
    - Kí hiệu bán bậc ra của đỉnh v: `deg+(v)`
    - Kí hiệu bán bậc vào của đỉnh v: `deg-(v)`

Ví dụ: ![alt text](./img/image-12.png)
- Định lý về tổng bán bậc các đỉnh: ![alt text](./img/image-13.png)
- Đường đi, chu trình: như đồ thị vô hướng
- Liên thông mạnh, liên thông yếu: ![alt text](./img/image-14.png)
- Định chiều được: ![alt text](./img/image-15.png)
## Một số dạng đồ thị đặc biệt
- Đồ thị đầy đủ: ![alt text](./img/image-16.png)
- Đồ thị vòng: ![alt text](./img/image-17.png)
- Đồ thị bánh xe: ![alt text](./img/image-18.png)
- Đồ thị hai phía: ![alt text](./img/image-19.png)
</p>
</details>

<details>
<summary><h2>Biểu diễn đồ thị trên máy tính</h2></summary>
<p>

## Biểu diễn đồ thị bằng ma trận kề
- Ma trận kề của đồ thị vô hướng: ![alt text](./img/image-23.png)
- Tính chất của ma trận kề đối với đồ thị vô hướng: ![alt text](./img/image-20.png)
- Ma trận kề của đồ thị có hướng: ![alt text](./img/image-24.png)
- Tính chất của ma trận kề đối với đồ thị có hướng: ![alt text](./img/image-21.png)
- Ưu và nhược điểm: ![alt text](./img/image-22.png)
- Ma trận trọng số: ![alt text](./img/image-25.png)
## Biểu diễn đồ thị bằng ma trận liên thuộc
- Đồ thị vô hướng: ![alt text](./img/image-26.png)
- Đồ thị có hướng: ![alt text](./img/image-27.png)
## Biểu diễn đồ thị bằng danh sách cạnh
- Ưu và nhược điểm: ![alt text](./img/image-28.png)
## Biểu diễn đồ thị bằng danh sách kề
- Ưu và nhược điểm: ![alt text](./img/image-29.png)
</p>
</details>

<details>
<summary><h2>Tìm kiếm trên đồ thị</h2></summary>
<p>

## DFS + BFS
- Độ phức tạp thuật toán:
    - Biểu diễn bằng ma trận kề: `O(n^2)`
    - Biểu diễn bằng danh sách cạnh: `O(n.m)`
    - Biểu diễn bằng danh sách kề: `O(max(n, m))`
- Chú ý:
    - Đồ thị vô hướng: Với DFS(u) = BFS(u) = V -> đồ thị liên thông
    - Đồ thị có hướng: Với DFS(u) = BFS(u) = V -> đồ thị liên thông yếu
    Trong đó V là tập các đỉnh
## Ứng dụng:
- Duyệt tất cả các đỉnh của đồ thị
- Duyệt tất cả các thành phần liên thông của đồ thị
- Tìm đường đi từ đỉnh s đến đỉnh t trên đồ thị
- Kiểm tra tính liên thông mạnh của đồ thị
- Duyệt các đỉnh trụ của đồ thị
- Duyệt các cạnh cầu của đồ thị
- Bài toán định chiều đồ thị
    - Định nghĩa: ![alt text](./img/image-30.png)
    - Định lý: ![alt text](./img/image-31.png)
</p>
</details>

<details>
<summary><h2>Đồ thị Euler và Hamilton</h2></summary>
<p>

## Đồ thị Euler (đi qua các cạnh của đồ thị 1 lần)
- Khái niệm và ví dụ: ![alt text](./img/image-34.png) ![alt text](./img/image-35.png)
- Điều kiện cần và đủ để đồ thị là Euler:
    - Đồ thị vô hướng: mọi đỉnh của đồ thị đều có bậc chẵn
    - Đồ thị có hướng: tất cả các đỉnh đều có bán bậc ra bằng bán bậc vào (đồ thị liên thông mạnh)
- Điều kiện cần và đủ để đồ thị là nửa Euler:
    - Đồ thị vô hướng: đồ thị có 0 hoặc 2 đỉnh bậc lẻ
    - Đồ thị có hướng:
        - Tồn tại đúng hai đỉnh 𝑢, 𝑣 ∈ 𝑉 sao cho 𝑑𝑒𝑔+(𝑢) − 𝑑𝑒𝑔−(𝑢) = 𝑑𝑒𝑔−(𝑣) − deg+(𝑣) = 1
        - Các đỉnh 𝑠 ≠ 𝑢, 𝑠 ≠ 𝑣 còn lại có 𝑑𝑒𝑔+(𝑠) = 𝑑𝑒𝑔−(𝑠)
        - Đường đi Euler sẽ xuất phát tại đỉnh 𝑢 và kết thúc tại đỉnh 𝑣
## Đồ thị Hamilton (đi qua các đỉnh của đồ thị 1 lần)
- Khái niệm và ví dụ: ![alt text](./img/image-36.png)
- Chưa có thuật toán hiệu quả để kiểm tra xem 1 đồ thị có phải Hamilton không.
</p>
</details>

<details>
<summary><h2>Spanning Trees</h2></summary>
<p>

## Cây và các tính chất của cây
- Định nghĩa: ![alt text](./img/image-32.png)
- Các tính chất của cây: ![alt text](./img/image-33.png)
## Cây khung của đồ thị
## Bài toán cây khung nhỏ nhất
- Thuật toán Kruskal
- Thuật toán Prim
</p>
</details>

<details>
<summary><h2>Shortest Path</h2></summary>
<p>

## Bài toán tìm đường đi ngắn nhất
- Trường hợp 1: s cố định, t thay đổi
    - Đồ thị ko có trọng số âm: Dijkstra
    - Đồ thị có trọng số âm nhưng ko có chu trình âm: Bellman-Ford
    - Đồ thị có chu trình âm: Ko có lời giải
- Trường hợp 2: s thay đổi và t thay đổi
    - Đồ thị ko có trọng số âm: lặp lại n lần Dijkstra
    - Đồ thị ko có chu trình âm: Floyd
## Thuật toán Dijkstra
- Mục đích:
    - Tìm đường đi ngắn nhất từ 1 đỉnh s tới các đỉnh còn lại.
    - Áp dụng cho đồ thị có hướng với trọng số ko âm.
## Thuật toán Bellman-Ford
- Mục đích:
    - Tìm đường đi ngắn nhất từ 1 đỉnh s tới các đỉnh còn lại.
    - Áp dụng cho đồ thị có hướng và không có chu trình âm (có thể có cạnh âm).
## Thuật toán Floyd
- Mục đích:
    - Tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh của đồ thị.
    - Áp dụng cho đồ thị có hướng và không có chu trình âm (có thể có cạnh âm).
</p>
</details>

<details>
<summary><h2>Bài toán luồng cực đại trong mạng</h2></summary>
<p>

## Phát biểu bài toán
## Thuật toán Ford-Fulkerson
</p>
</details>