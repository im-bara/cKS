# Change Log

---
## 🛠️ Ver.0.0.37 (Current)

### Known Issue :
- Statement `If` tidak bekerja dengan benar
- Token bermasalah ketika memanggil `if`
- `While` tidak memberikan Output. (BUGGED!?)
- Operasi Aritmatika tidak berfungsi ketika, Operator Lebih dari Dua

### Fixed :
- Integer bisa bekerja dengan baik (Issue, ketika menjalankan Operasi)
- Tidak Merespon String dengan baik. (Issue Fixed)

(Parser Bermasalah, karena selalu mengeluarkan Integer bukan string.)

### Feature Update :
- Token Debug di akses melalui `--debug` untuk mengidentifikasi Masalah Pada Token

---
## 🛠️ Ver.0.0.38 (Skipped Update)

### Issue :
- Statement `If` merespon `>` (lebih dari) tidak bekerja dengan benar
- `While` memberikan keluaran, Issue lanjutan dimana Infinite Loop.
- Issue Parser dengan respond `Func`, dimana Function tidak memberikan output

### Fix :
- If Statement bisa merespon dengan baik `<` (kurang dari)
- `Call` di perbaiki, dimana bisa di gunakan pada `if`.

### Feature Update :
- While Loop (Bugged)

---
# 🛠️ Ver.0.0.42 (Released Soon)

### Issue :
- Boolean Bugged
- Penambahan Aritmatika seperti `Greater_than (>)`, `Greater_equal (>=)`, `less_than (<)`, `less_equal (<=)`.
Tidak berfungsi dimana tidak dapat merespon dengan baik. dimana `While` tidak dapat memberikan Output
- Dengan adanya Issue Aritmatika, Operator dasar seperti `+`, `-`, `:`, `*`, kemungkinan besar tidak dapat berfungsi
Pada While

### Fix :

- `While` di perbaiki. (Jika menemukan issue langsung beri tahu)

- Ada beberapa Typo pada penulisan di `<BinaryOpNode>`, `<StatementNode>`, `<IfNode>`, `<WhileNode>`.

### Featured Update :

- `Boolean` (Bugged)

---
