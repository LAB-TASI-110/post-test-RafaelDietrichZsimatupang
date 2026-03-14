#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi variabel
    char kode_kota[10];
    char nama_kota[20];
    float x, berat_butet, berat_ucok, total_berat;
    float ongkos_per_kg, ongkos_dasar, total_ongkos, diskon;
    int is_luar_pulau;

    printf("==========================================\n");
    printf("   Sistem Kasir Ekspedisi Del-Express\n");
    printf("==========================================\n");

    // Looping program agar berjalan terus sampai diinput END
    while (1) {
        printf("\nMasukkan Kode Kota Tujuan (atau ketik END untuk berhenti): ");
        scanf("%s", kode_kota);

        // Cek kondisi berhenti
        if (strcmp(kode_kota, "END") == 0) {
            printf("\nTerima kasih telah menggunakan layanan Del-Express!\n");
            break;
        }

        printf("Masukkan berat isi paket Butet (x kg)    : ");
        scanf("%f", &x);

        // 1. Logic Perhitungan Berat (Sesuai gambar dan info tambahan)
        berat_butet = x + 1.0;          // Berat isi (x) + berat dus Butet (1 kg)
        berat_ucok = 1.5 * berat_butet; // Berat Ucok 3/2 dari total berat Butet
        total_berat = berat_butet + berat_ucok;

        // 2. Logic Penentuan Kota dan Harga
        is_luar_pulau = 0; // Reset status luar pulau (0 = False, 1 = True)
        
        if (strcmp(kode_kota, "MDN") == 0) {
            strcpy(nama_kota, "Medan");
            ongkos_per_kg = 8000;
        } else if (strcmp(kode_kota, "BLG") == 0) {
            strcpy(nama_kota, "Balige");
            ongkos_per_kg = 5000;
        } else if (strcmp(kode_kota, "JKT") == 0) {
            strcpy(nama_kota, "Jakarta");
            ongkos_per_kg = 12000;
            is_luar_pulau = 1; // Jakarta luar pulau
        } else if (strcmp(kode_kota, "SBY") == 0) {
            strcpy(nama_kota, "Surabaya");
            ongkos_per_kg = 13000;
            is_luar_pulau = 1; // Surabaya luar pulau
        } else {
            printf("[!] Kode kota tidak valid. Silakan coba lagi.\n");
            continue; // Ulangi loop dari awal jika input salah
        }

        // 3. Logic Perhitungan Ongkos dan Promo
        ongkos_dasar = total_berat * ongkos_per_kg;
        diskon = 0;

        // Syarat promo ongkir lebaran: total berat > 10kg
        if (total_berat > 10.0) {
            diskon = ongkos_dasar * 0.10; // Diskon 10%
        }
        
        total_ongkos = ongkos_dasar - diskon;

        // 4. Output Struk Pembayaran
        printf("\n------------------------------------------\n");
        printf("             STRUK PEMBAYARAN             \n");
        printf("               DEL-EXPRESS                \n");
        printf("------------------------------------------\n");
        printf("Kota Tujuan          : %s\n", nama_kota);
        printf("Berat Paket Butet    : %.2f kg\n", berat_butet);
        printf("Berat Paket Ucok     : %.2f kg\n", berat_ucok);
        printf("Total Berat          : %.2f kg\n", total_berat);
        printf("Total Ongkos Kirim   : Rp %.0f\n", total_ongkos);
        
        // Cetak Info Promo
        printf("Info Promo Diperoleh :\n");
        int dapat_promo = 0;
        
        if (total_berat > 10.0) {
            printf(" - Diskon Ongkir 10%% (Promo Lebaran)\n");
            dapat_promo = 1;
        }
        if (is_luar_pulau == 1) {
            printf(" - Asuransi Gratis (Pengiriman Luar Pulau)\n");
            dapat_promo = 1;
        }
        if (dapat_promo == 0) {
            printf(" - (Tidak ada promo yang memenuhi syarat)\n");
        }
        printf("------------------------------------------\n");
    }

    return 0;
}