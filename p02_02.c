#include <stdio.h>
#include <stdlib.h> // Library tambahan untuk alokasi memori dinamis (malloc & free)

int main() {
    int N;
    int kode_kategori;
    int total_stok = 0;

    // 1. Meminta input jumlah total data
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    // Validasi agar N tidak negatif atau nol
    if (N <= 0) {
        printf("Jumlah data harus lebih dari 0!\n");
        return 1; // Keluar dari program dengan kode error
    }

    // Menggunakan malloc untuk membuat array dinamis berdasarkan nilai N
    // Ini lebih aman daripada array statis int stok[1000] agar memori efisien
    int *stok = (int *)malloc(N * sizeof(int));
    if (stok == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    // 2. Meminta input deret stok (s1, s2, ..., sN)
    printf("Masukkan %d deret stok (pisahkan dengan spasi/enter):\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &stok[i]);
    }

    // 3. Meminta input kode kategori
    printf("\n--- Pilihan Kategori ---\n");
    printf("1 : Kategori Seragam (Urutan Ganjil)\n");
    printf("2 : Kategori Sembako (Urutan Genap)\n");
    printf("Masukkan kode kategori yang ingin dihitung (1 atau 2): ");
    scanf("%d", &kode_kategori);

    // 4. Proses perhitungan stok berdasarkan pola selang-seling gambar
    for (int i = 0; i < N; i++) {
        if (kode_kategori == 1 && (i % 2 == 0)) {
            // Urutan ganjil (indeks 0, 2, 4...) -> Seragam
            total_stok += stok[i];
        } 
        else if (kode_kategori == 2 && (i % 2 != 0)) {
            // Urutan genap (indeks 1, 3, 5...) -> Sembako
            total_stok += stok[i];
        }
    }

    // 5. Output hasil
    if (kode_kategori == 1 || kode_kategori == 2) {
        printf("\n=> Total stok untuk kategori %d adalah: %d pcs\n", kode_kategori, total_stok);
    } else {
        printf("\n=> Error: Kode kategori tidak valid. Harap masukkan 1 atau 2.\n");
    }

    // Membebaskan memori yang dialokasikan agar tidak terjadi memory leak
    free(stok); 

    return 0;
}