#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk membersihkan buffer input agar tidak terjadi infinite loop atau skip input
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi untuk menahan layar sebelum kembali ke menu
void pauseScreen() {
    printf("\n[Tekan Enter untuk kembali ke Menu Utama]");
    clearBuffer();
    getchar();
    system("cls");
}

// Fungsi untuk menampilkan tata tertib kafetaria agar mahasiswa makan dengan nyaman dan tenang
void tampilkanTataTertib() {
    printf("==================================================\n");
    printf("     ATURAN KENYAMANAN & KETENANGAN KAFETARIA     \n");
    printf("==================================================\n");
    printf("1. Mahasiswa wajib antre dengan tertib.\n");
    printf("2. Dilarang berbicara saat mengunyah makanan\n");
    printf("   (Silent Dining mode on).\n");
    printf("3. Letakkan alat makan kotor pada tempat yang\n");
    printf("   disediakan secara perlahan.\n");
    printf("4. Kelompok piket wajib memastikan meja bersih\n");
    printf("   sebelum meninggalkan area.\n");
    printf("5. Menjaga volume suara seminimal mungkin saat\n");
    printf("   berdiskusi setelah makan.\n");
    printf("==================================================\n");
}

// Fungsi untuk mengecek sistem makan berdasarkan hari
void cekSistemMakan() {
    char hari[20];
    printf("Masukkan Hari (Senin-Minggu): ");
    scanf("%19s", hari);
    
    printf("\n>>> STATUS OPERASIONAL HARI %s <<<\n", hari);
    if (strcasecmp(hari, "Senin") == 0 || strcasecmp(hari, "Selasa") == 0 || 
        strcasecmp(hari, "Rabu") == 0 || strcasecmp(hari, "Kamis") == 0) {
        printf("- Pagi   : Sistem Piket\n");
        printf("- Siang  : Sistem Piket\n");
        printf("- Malam  : Sistem Piket\n");
    } else if (strcasecmp(hari, "Jumat") == 0) {
        printf("- Pagi   : Sistem Piket\n");
        printf("- Siang  : Sistem Piket\n");
        printf("- Malam  : Sistem Prasmanan\n");
    } else if (strcasecmp(hari, "Sabtu") == 0) {
        printf("- Pagi   : Sistem Prasmanan\n");
        printf("- Siang  : Sistem Prasmanan\n");
        printf("- Malam  : TUTUP (Makan di luar kampus)\n");
    } else if (strcasecmp(hari, "Minggu") == 0) {
        printf("- Pagi   : TUTUP (Makan di luar kampus)\n");
        printf("- Siang  : TUTUP (Makan di luar kampus)\n");
        printf("- Malam  : TUTUP (Makan di luar kampus)\n");
    } else {
        printf("Hari tidak valid! Pastikan pengetikan benar.\n");
    }
}

// Fungsi untuk melihat pembagian lokasi dan kelompok
void tampilkanLokasi() {
    printf("==================================================\n");
    printf("        PEMBAGIAN LOKASI & KELOMPOK PIKET         \n");
    printf("==================================================\n");
    printf("[1] Kantin Lama (KL)\n");
    printf("    - Pembagian: KL Atas dan KL Bawah\n\n");
    printf("[2] Kantin Baru 1 (KB 1)\n");
    printf("    - Pembagian: Lantai 1 dan Lantai 2\n");
    printf("    - Total Kelompok Piket: 16 Kelompok\n\n");
    printf("[3] Kantin Baru 2 (KB 2)\n");
    printf("    - Pembagian: Lantai 1 dan Lantai 2\n");
    printf("    - Total Kelompok Piket: 16 Kelompok\n\n");
    printf("[4] Kantin Baru Tengah (KB Tengah)\n");
    printf("    - Pembagian: Atas dan Bawah\n");
    printf("    - Total Kelompok Piket: 8 Kelompok\n");
    printf("==================================================\n");
}

// Fungsi untuk melihat jadwal jam operasional
void tampilkanWaktuMakan() {
    printf("==================================================\n");
    printf("                 JADWAL JAM MAKAN                 \n");
    printf("==================================================\n");
    printf(">>> JADWAL SISTEM PIKET <<<\n");
    printf("- PAGI\n");
    printf("  Waktu Makan : 06:10 WIB\n");
    printf("  Waktu Piket : 06:45 WIB\n\n");
    printf("- SIANG\n");
    printf("  Waktu Piket : 12:05 WIB\n");
    printf("  Waktu Makan : 12:30 WIB\n\n");
    printf("- MALAM\n");
    printf("  Waktu Makan : 18:10 WIB\n");
    printf("  Waktu Piket : 18:45 WIB\n\n");
    printf("--------------------------------------------------\n");
    printf(">>> JADWAL SISTEM PRASMANAN <<<\n");
    printf("- PAGI  : 06:30 - 08:45 WIB\n");
    printf("- SIANG : 11:00 - 13:00 WIB\n");
    printf("- MALAM : 18:30 - 20:45 WIB\n");
    printf("==================================================\n");
}

int main() {
    int pilihan;
    bool isRunning = true;

    // Bersihkan layar saat program pertama kali jalan
    system("cls");

    while (isRunning) {
        printf("==================================================\n");
        printf("        SISTEM INFORMASI KAFETARIA IT DEL         \n");
        printf("==================================================\n");
        printf("1. Cek Menu & Sistem Berdasarkan Hari\n");
        printf("2. Cek Pembagian Lokasi Kantin & Kelompok\n");
        printf("3. Cek Jadwal Jam Makan (Piket & Prasmanan)\n");
        printf("4. Standar Kenyamanan & Ketertiban\n");
        printf("5. Keluar Program\n");
        printf("==================================================\n");
        printf("Pilih menu (1-5): ");
        
        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput tidak valid! Harap masukkan angka.\n");
            clearBuffer();
            pauseScreen();
            continue;
        }

        printf("\n");
        switch (pilihan) {
            case 1:
                cekSistemMakan();
                pauseScreen();
                break;
            case 2:
                tampilkanLokasi();
                pauseScreen();
                break;
            case 3:
                tampilkanWaktuMakan();
                pauseScreen();
                break;
            case 4:
                tampilkanTataTertib();
                pauseScreen();
                break;
            case 5:
                printf("Terima kasih! Jangan lupa cuci tangan sebelum makan.\n");
                isRunning = false;
                break;
            default:
                printf("Pilihan tidak tersedia di menu.\n");
                pauseScreen();
                break;
        }
    }
    return 0;
}