#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Database.h"
#include "Mahasiswa.h"
#include "Jurusan.h"
#include "Dosen.h"
#include "MataKuliah.h"
#include "Nilai.h"
#include "User.h"

using namespace std;

//Fungsi input string
string inputString(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin >> ws, input);
    return input;
}

// Fungsi untuk membersihkan layar
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk menampilkan header
void tampilkanHeader() {
    cout << "========================================" << endl;
    cout << "    SISTEM MANAJEMEN MAHASISWA" << endl;
    cout << "========================================" << endl;
}

// Fungsi untuk pause
void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// Fungsi untuk input yang aman
int inputAngka(const string& pesan) {
    int angka;
    while (true) {
        cout << pesan;
        if (cin >> angka) {
            cin.ignore(); // Membersihkan buffer
            return angka;
        }
        else {
            cout << "Input tidak valid! Masukkan angka yang benar.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float inputFloat(const string& pesan) {
    float angka;
    while (true) {
        cout << pesan;
        if (cin >> angka) {
            cin.ignore();
            return angka;
        }
        else {
            cout << "Input tidak valid! Masukkan angka yang benar.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Fungsi login
bool loginUser(Database& db) {
    clearScreen();
    tampilkanHeader();
    cout << "LOGIN SISTEM\n" << endl;

    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    User user(0, username, password);
    if (user.login(db)) {
        cout << "\nLogin berhasil! Selamat datang, " << username << "!" << endl;
        pause();
        return true;
    }
    else {
        cout << "\n Login gagal! Username atau password salah." << endl;
        pause();
        return false;
    }
}

// Menu Mahasiswa
void menuMahasiswa(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << " MENU MAHASISWA\n" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-2): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << "TAMBAH MAHASISWA BARU\n" << endl;

            // Tampilkan daftar jurusan dan dosen terlebih dahulu
            cout << "Daftar Jurusan yang tersedia:" << endl;
            Jurusan::tampilkanSemuaJurusan(db);

            cout << "\nDaftar Dosen yang tersedia:" << endl;
            Dosen::tampilkanSemuaDosen(db);

            cout << "\n" << string(40, '-') << endl;

            string npm, nama;
            cout << "NPM: ";
            getline(cin, npm);
            cout << "Nama: ";
            getline(cin, nama);

            int id_jurusan = inputAngka("ID Jurusan: ");

            Mahasiswa mhs(npm, nama, id_jurusan);
            mhs.tambahMahasiswa(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            Mahasiswa::tampilkanSemuaMahasiswa(db);
            pause();
            break;
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}

// Menu Jurusan
void menuJurusan(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << "MENU JURUSAN\n" << endl;
        cout << "1. Tambah Jurusan" << endl;
        cout << "2. Tampilkan Semua Jurusan" << endl;
        cout << "3. Ubah Jurusan" << endl;
        cout << "4. Hapus Jurusan" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-4): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << "TAMBAH JURUSAN BARU\n" << endl;

            string nama_jurusan;
            cout << "Nama Jurusan: ";
            getline(cin, nama_jurusan);

            Jurusan jurusan(0, nama_jurusan);
            jurusan.tambahJurusan(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            Jurusan::tampilkanSemuaJurusan(db);
            pause();
            break;
        case 3: {
            clearScreen();
            tampilkanHeader();
            cout << "UBAH JURUSAN\n" << endl;

            Jurusan::tampilkanSemuaJurusan(db);

            int id = inputAngka("\nMasukkan ID Jurusan yang akan diubah: ");
            string nama_baru;
            cout << "Nama Jurusan Baru: ";
            getline(cin, nama_baru);

            Jurusan jurusan(id, nama_baru);
            jurusan.ubahJurusan(db);
            pause();
            break;
        }
        case 4: {
            clearScreen();
            tampilkanHeader();
            cout << "HAPUS JURUSAN\n" << endl;

            Jurusan::tampilkanSemuaJurusan(db);

            int id = inputAngka("\nMasukkan ID Jurusan yang akan dihapus: ");
            char konfirmasi;
            cout << "Yakin ingin menghapus? (y/n): ";
            cin >> konfirmasi;
            cin.ignore();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                Jurusan::hapusJurusan(db, id);
            }
            else {
                cout << " Penghapusan dibatalkan." << endl;
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            cout << " Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}

// Menu Dosen
void menuDosen(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << "MENU DOSEN\n" << endl;
        cout << "1. Tambah Dosen" << endl;
        cout << "2. Tampilkan Semua Dosen" << endl;
        cout << "3. Ubah Dosen" << endl;
        cout << "4. Hapus Dosen" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-4): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << "TAMBAH DOSEN BARU\n" << endl;

            string nama_dosen;
            cout << "Nama Dosen: ";
            getline(cin, nama_dosen);

            Dosen dosen(0, nama_dosen);
            dosen.tambahDosen(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            Dosen::tampilkanSemuaDosen(db);
            pause();
            break;
        case 3: {
            clearScreen();
            tampilkanHeader();
            cout << " UBAH DOSEN\n" << endl;

            Dosen::tampilkanSemuaDosen(db);

            int id = inputAngka("\nMasukkan ID Dosen yang akan diubah: ");
            string nama_baru;
            cout << "Nama Dosen Baru: ";
            getline(cin, nama_baru);

            Dosen dosen(id, nama_baru);
            dosen.ubahDosen(db);
            pause();
            break;
        }
        case 4: {
            clearScreen();
            tampilkanHeader();
            cout << " HAPUS DOSEN\n" << endl;

            Dosen::tampilkanSemuaDosen(db);

            int id = inputAngka("\nMasukkan ID Dosen yang akan dihapus: ");
            char konfirmasi;
            cout << "Yakin ingin menghapus? (y/n): ";
            cin >> konfirmasi;
            cin.ignore();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                Dosen::hapusDosen(db, id);
            }
            else {
                cout << " Penghapusan dibatalkan." << endl;
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            cout << " Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}

void menuMataKuliah(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << " MENU MATA KULIAH\n" << endl;
        cout << "1. Tambah Mata Kuliah" << endl;
        cout << "2. Tampilkan Semua Mata Kuliah" << endl;
        cout << "3. Ubah Mata Kuliah" << endl;
        cout << "4. Hapus Mata Kuliah" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-4): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << "TAMBAH MATA KULIAH BARU\n" << endl;

            string kode_mk, nama_mk;
            cout << "Kode Mata Kuliah: ";
            cin.ignore(); // Pastikan buffer bersih sebelum getline
            getline(cin, kode_mk);
            cout << "Nama Mata Kuliah: ";
            getline(cin, nama_mk);
            int sks = inputAngka("SKS: ");
            int id_jurusan = inputAngka("ID Jurusan: ");
            int id_dosen = inputAngka("ID Dosen: ");

            MataKuliah mk(kode_mk, nama_mk, sks, id_jurusan, id_dosen);
            mk.tambahMataKuliah(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            MataKuliah::tampilkanSemuaMataKuliah(db);
            pause();
            break;

        case 3: {
            clearScreen();
            tampilkanHeader();
            cout << "UBAH MATA KULIAH\n" << endl;

            MataKuliah::tampilkanSemuaMataKuliah(db);

            string kode_mk, nama_mk;
            cout << "\nMasukkan Kode Mata Kuliah yang akan diubah: ";
            cin.ignore(); // penting sebelum getline
            getline(cin, kode_mk);
            cout << "Nama Mata Kuliah Baru: ";
            getline(cin, nama_mk);
            int sks = inputAngka("SKS Baru: ");
            int id_jurusan = inputAngka("ID Jurusan Baru: ");
            int id_dosen = inputAngka("ID Dosen: ");

            MataKuliah mk(kode_mk, nama_mk, sks, id_jurusan, id_dosen);
            mk.ubahMataKuliah(db);
            pause();
            break;
        }
        case 4: {
            clearScreen();
            tampilkanHeader();
            cout << "HAPUS MATA KULIAH\n" << endl;

            MataKuliah::tampilkanSemuaMataKuliah(db);

            string kode_mk;
            cout << "\nMasukkan Kode Mata Kuliah yang akan dihapus: ";
            cin.ignore();
            getline(cin, kode_mk);
            char konfirmasi;
            cout << "Yakin ingin menghapus? (y/n): ";
            cin >> konfirmasi;
            cin.ignore();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                MataKuliah::hapusMataKuliah(db, kode_mk);
            }
            else {
                cout << "Penghapusan dibatalkan." << endl;
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}


// Menu Nilai
void menuNilai(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << "MENU NILAI\n" << endl;
        cout << "1. Tambah Nilai" << endl;
        cout << "2. Tampilkan Semua Nilai" << endl;
        cout << "3. Ubah Nilai" << endl;
        cout << "4. Hapus Nilai" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-4): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << " TAMBAH NILAI BARU\n" << endl;

            // Tampilkan referensi data
            cout << " Daftar Mahasiswa:\n";
            Mahasiswa::tampilkanSemuaMahasiswa(db);

            cout << "\n Daftar Mata Kuliah:\n";
            MataKuliah::tampilkanSemuaMataKuliah(db);

            cout << "\n" << string(50, '-') << endl;

            string npm = inputString("Masukkan NPM Mahasiswa: ");
            string kode_mk = inputString("Masukkan Kode Mata Kuliah: ");
            float nilai = inputFloat("Nilai (0-100): ");

            Nilai nilaiObj(0, npm, kode_mk, nilai);
            nilaiObj.tambahNilai(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            Nilai::tampilkanNilai(db);
            pause();
            break;
        case 3: {
            clearScreen();
            tampilkanHeader();
            cout << " UBAH NILAI\n" << endl;

            Nilai::tampilkanNilai(db);

            int id = inputAngka("\nMasukkan ID Nilai yang akan diubah: ");
            string npm = inputString("Masukkan NPM Baru: ");
            string kode_mk = inputString("Masukkan Kode Mata Kuliah Baru: ");
            float nilai_baru = inputFloat("Nilai Baru (0-100): ");

            Nilai nilaiObj(id, npm, kode_mk, nilai_baru);
            nilaiObj.ubahNilai(db);
            pause();
            break;
        }
        case 4: {
            clearScreen();
            tampilkanHeader();
            cout << " HAPUS NILAI\n" << endl;

            Nilai::tampilkanNilai(db);

            int id = inputAngka("\nMasukkan ID Nilai yang akan dihapus: ");
            char konfirmasi;
            cout << "Yakin ingin menghapus? (y/n): ";
            cin >> konfirmasi;
            cin.ignore();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                Nilai::hapusNilai(db, id);
            }
            else {
                cout << " Penghapusan dibatalkan." << endl;
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            cout << " Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}


// Menu User Management
void menuUser(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << " MENU MANAJEMEN USER\n" << endl;
        cout << "1. Tambah User" << endl;
        cout << "2. Tampilkan Semua User" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;

        pilihan = inputAngka("\nPilih menu (0-2): ");

        switch (pilihan) {
        case 1: {
            clearScreen();
            tampilkanHeader();
            cout << " TAMBAH USER BARU\n" << endl;

            string username, password;
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);

            User user(0, username, password);
            user.tambahUser(db);
            pause();
            break;
        }
        case 2:
            clearScreen();
            tampilkanHeader();
            User::tampilkanUser(db);
            pause();
            break;
        case 0:
            break;
        default:
            cout << " Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}

// Menu Utama
void menuUtama(Database& db) {
    int pilihan;
    do {
        clearScreen();
        tampilkanHeader();
        cout << " MENU UTAMA\n" << endl;
        cout << "1.  Manajemen Mahasiswa" << endl;
        cout << "2.  Manajemen Jurusan" << endl;
        cout << "3.  Manajemen Dosen" << endl;
        cout << "4.  Manajemen Mata Kuliah" << endl;
        cout << "5.  Manajemen Nilai" << endl;
        cout << "6.  Manajemen User" << endl;
        cout << "0.  Keluar" << endl;

        pilihan = inputAngka("\nPilih menu (0-6): ");

        switch (pilihan) {
        case 1:
            menuMahasiswa(db);
            break;
        case 2:
            menuJurusan(db);
            break;
        case 3:
            menuDosen(db);
            break;
        case 4:
            menuMataKuliah(db);
            break;
        case 5:
            menuNilai(db);
            break;
        case 6:
            menuUser(db);
            break;
        case 0:
            clearScreen();
            tampilkanHeader();
            cout << " Terima kasih telah menggunakan sistem!" << endl;
            cout << "Program akan keluar..." << endl;
            break;
        default:
            cout << " Pilihan tidak valid!" << endl;
            pause();
        }
    } while (pilihan != 0);
}

int main() {
    try {
        // Inisialisasi database
        Database db;

        // Login terlebih dahulu
        while (!loginUser(db)) {
            char coba_lagi;
            cout << "\nIngin mencoba login lagi? (y/n): ";
            cin >> coba_lagi;
            cin.ignore();

            if (coba_lagi != 'y' && coba_lagi != 'Y') {
                cout << "Program dihentikan." << endl;
                return 0;
            }
        }

        // Masuk ke menu utama setelah login berhasil
        menuUtama(db);

    }
    catch (const exception& e) {
        cerr << " Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
