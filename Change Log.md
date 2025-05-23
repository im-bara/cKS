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
# 🛠️ Ver.0.0.42 (Skipped Update)

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
# 🛠️ Ver.0.0.56 (Update Released Soon)

### Issue :
- `Boolean` tidak bisa menggunakan `=` , issue ditemukan di grammar tidak mendeklarasikan = dengan benar
- `While` dimana tidak dapat merespon Call (?) 
- `Boolean` issue ketika menjelaskan tentang `intLebihKecil < intLebihBesar` karena struktur Grammarnya hanya Menerima output String 💀 udah di perbaiki (kayak nya)

### Fix :
- Grammar di perbaiki (?) jujur 💀 gw juga baru ngeh jir, dimana Outputnya selalu String. 
- Perbaikan grammar juga mempengaruhi beberapa struktur Abstract Syntax Tree yang harus di perbaiki.

### Feature Update :
- Else (WIP)
- For (WIP)

### Feature Goals :
- Dimana AST langsung diubah menjadi ByteCode, Alasan karena untuk meningkatkan Performance.
- Garbage Collection 💀 biar orang bego gak kena Memory Leak 
- Simplifikasi & Penambahan Grammar, Alasan code sekarang Masih kayak Mie berantakan Anjir

> Note semua Goals memiliki Low Priority jadi tidak akan di kerjakan lebih dulu jir. Masih pengen nambahin Fitur kayak Array, List dsb.