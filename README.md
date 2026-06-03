# Warnet Management System

> Project Akhir Mata Kuliah Struktur Data 2026
>
> Bahasa Pemrograman : C++
>
> Implementasi : Linked List, Priority Queue, Stack, dan Array

---

# Latar Belakang

Dalam operasional sebuah warnet, pengelolaan pelanggan menjadi salah satu aspek penting untuk menjaga kelancaran pelayanan. Jumlah komputer yang terbatas sering kali menyebabkan pelanggan harus menunggu giliran untuk menggunakan layanan yang tersedia. Selain itu, beberapa pelanggan memiliki status keanggotaan seperti VIP atau Member yang berhak mendapatkan prioritas pelayanan dibandingkan pelanggan biasa.

Apabila pengelolaan pelanggan dan antrian dilakukan secara manual, dapat terjadi berbagai permasalahan seperti kesalahan pencatatan pelanggan, antrian yang tidak teratur, serta kesulitan dalam melihat riwayat penggunaan komputer. Kondisi tersebut dapat mengurangi efisiensi pelayanan dan menimbulkan ketidaknyamanan bagi pelanggan.

Berdasarkan permasalahan tersebut, dibuatlah aplikasi Warnet Management System yang memanfaatkan struktur data Linked List, Priority Queue, Stack, dan Array untuk membantu pengelolaan data pelanggan, antrian prioritas, penggunaan komputer, serta riwayat pelanggan yang telah selesai menggunakan layanan.

---

# Tujuan dan Manfaat

## Tujuan

- Mengimplementasikan struktur data ke dalam aplikasi nyata.
- Membuat sistem pengelolaan pelanggan warnet berbasis C++.
- Mengatur antrian pelanggan berdasarkan tingkat prioritas.
- Mengelola penggunaan komputer secara lebih terstruktur.
- Menyimpan riwayat pelanggan yang telah selesai menggunakan layanan.

## Manfaat

- Membantu pengelola warnet dalam mengatur pelanggan.
- Mempermudah pengelolaan antrian berdasarkan prioritas.
- Mengurangi kemungkinan kesalahan pencatatan data.
- Memudahkan pemantauan penggunaan komputer.
- Menjadi contoh penerapan struktur data dalam kehidupan nyata.

---

# Penjelasan Aplikasi

Warnet Management System merupakan aplikasi yang digunakan untuk membantu proses pengelolaan pelanggan warnet.

Fitur utama aplikasi:

## Manajemen Data Pelanggan

Data yang disimpan:

- ID Pelanggan
- Nama Pelanggan
- Status Pelanggan

Kategori pelanggan:

- VIP
- Member
- Non Member

## Priority Queue

Pelanggan akan masuk ke dalam antrian berdasarkan prioritas.

Urutan prioritas:

1. VIP
2. Member
3. Non Member

Pelanggan dengan prioritas lebih tinggi akan memperoleh giliran terlebih dahulu.

## Pengelolaan Komputer

Sistem menyediakan 5 komputer aktif.

Jika terdapat komputer kosong, pelanggan akan langsung ditempatkan pada komputer tersebut.

## Riwayat Pelanggan

Pelanggan yang selesai menggunakan komputer akan disimpan ke dalam Stack sehingga riwayat penggunaan dapat ditampilkan kembali.

---

# Struktur Data yang Digunakan

| Struktur Data | Fungsi |
|--------------|---------|
| Linked List | Menyimpan database pelanggan |
| Priority Queue | Mengatur antrian berdasarkan prioritas |
| Stack | Menyimpan riwayat pelanggan selesai |
| Array | Menyimpan data pelanggan yang sedang menggunakan komputer |

---

# Gambar Rancangan Antarmuka

## Menu Utama

```text
========== WARNET ==========

1. Tambah Pelanggan
2. Masuk Antrian
3. Tampilkan Database
4. Tampilkan Antrian
5. Tampilkan PC Aktif
6. Pelanggan Selesai Bermain
7. Tampilkan Riwayat
8. Keluar

Pilihan :
```

## Tampilan PC Aktif

```text
=== KOMPUTER AKTIF ===

PC 1 : Andi (Member)
PC 2 : Budi (Non Member)
PC 3 : Putra (VIP)
PC 4 : Kosong
PC 5 : Kosong
```

## Tampilan Priority Queue

```text
=== PRIORITY QUEUE ===

1. Putra (VIP)
2. Gina (Member)
3. Karin (Member)
4. Fajar (Non Member)
5. Hasan (Non Member)
```

## Tampilan Riwayat

```text
=== RIWAYAT SELESAI ===

1. Andi (Member)
2. Caca (VIP)
3. Budi (Non Member)
```

---

# Rancangan Pengerjaan Proyek

## Tahap Analisis

- Menentukan kebutuhan sistem.
- Menentukan struktur data yang digunakan.
- Menentukan fitur utama aplikasi.

## Tahap Perancangan

- Merancang database pelanggan menggunakan Linked List.
- Merancang antrian menggunakan Priority Queue.
- Merancang riwayat pelanggan menggunakan Stack.
- Merancang sistem komputer aktif menggunakan Array.

## Tahap Implementasi

- Implementasi Linked List.
- Implementasi Priority Queue.
- Implementasi Stack.
- Implementasi Array komputer aktif.
- Integrasi seluruh fitur aplikasi.

## Tahap Pengujian

- Pengujian penambahan pelanggan.
- Pengujian antrian prioritas.
- Pengujian penggunaan komputer.
- Pengujian penyimpanan riwayat pelanggan.

---

# Pembagian Tugas Tim

## Naren

- Analisis kebutuhan sistem
- Implementasi Linked List
- Implementasi Priority Queue
- Presentasi proyek

## Kian

- Implementasi Stack
- Implementasi Array komputer aktif
- Pengujian program
- Presentasi proyek

---

# Teknologi yang Digunakan

- C++
- Visual Studio Code
- Git
- GitHub

---

# Kesimpulan

Warnet Management System merupakan aplikasi yang dirancang untuk membantu pengelolaan pelanggan warnet secara lebih terstruktur. Dengan memanfaatkan Linked List, Priority Queue, Stack, dan Array, sistem mampu mengelola data pelanggan, mengatur antrian berdasarkan prioritas, mengelola penggunaan komputer, serta menyimpan riwayat pelanggan yang telah selesai menggunakan layanan.

---
