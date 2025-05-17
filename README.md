# ⚔️ KnightScript

> Bahasa pemrograman eksperimen menggunakan C++ sebagai Compiler Utama

KnightScript adalah bahasa pemrograman kecil yang dikembangkan menggunakan C++ sebagai latihan untuk memahami cara kerja **lexer**, **parser**, dan **interpreter** dari nol.

---

## 🚀 Fitur Utama

- Keyword khusus: `summon`, `call`, `say`, dan lainnya
- Support literal: string, number
- Operator dasar
- Mudah dikembangkan dan dimodifikasi
- Source code ringan dan terbuka

---

## 📦 Cara Install & Jalankan

### 1. Clone Repository
```bash
git clone https://github.com/im-bara/cKS.git
```

### 2. Compile
```bash
g++ knight.cpp ks_parser.cpp ks_lexer.cpp ks_evaluator.cpp -o ks
```

### 3. Jalaninnya
```bash
./ks <file.ks>
```

---
**Contoh Use Case**
```bash
summon Knight = 'Bara'

say Knight
```

---
### Grammar KnightScript
1.**Summon** = Variabel & Assignment
2.**Say** = Print
3.**Func** = Function
4.**Call** = Memanggil Fungsi



