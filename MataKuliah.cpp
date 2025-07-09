#include "MataKuliah.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

// Constructor default
MataKuliah::MataKuliah() : kode_mk(""), nama_mk(""), sks(0), id_jurusan(0), id_dosen(0) {}

// Constructor dengan parameter
MataKuliah::MataKuliah(const string& kode_mk, const string& nama_mk, int sks, int id_jurusan, int id_dosen)
    : kode_mk(kode_mk), nama_mk(nama_mk), sks(sks), id_jurusan(id_jurusan), id_dosen(id_dosen) {
}

// Tambah data ke tabel mata_kuliah
void MataKuliah::tambahMataKuliah(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO mata_kuliah (kode_mk, nama_mk, sks, id_jurusan, id_dosen) VALUES (?, ?, ?, ?, ?)"
        );
        pstmt->setString(1, kode_mk);
        pstmt->setString(2, nama_mk);
        pstmt->setInt(3, sks);
        pstmt->setInt(4, id_jurusan);
        pstmt->setInt(5, id_dosen);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Mata kuliah berhasil ditambahkan.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menambahkan mata kuliah: " << e.what() << endl;
    }
}

// Tampilkan seluruh mata kuliah dengan JOIN jurusan dan dosen
void MataKuliah::tampilkanSemuaMataKuliah(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT mk.kode_mk, mk.nama_mk, mk.sks, j.nama_jurusan, d.nama_dosen "
            "FROM mata_kuliah mk "
            "JOIN jurusan j ON mk.id_jurusan = j.id_jurusan "
            "JOIN dosen d ON mk.id_dosen = d.id_dosen"
        );

        cout << "\n📘 Daftar Mata Kuliah:\n";
        while (res->next()) {
            cout << "Kode: " << res->getString("kode_mk")
                << ", Nama MK: " << res->getString("nama_mk")
                << ", SKS: " << res->getInt("sks")
                << ", Jurusan: " << res->getString("nama_jurusan")
                << ", Dosen Pengampu: " << res->getString("nama_dosen") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menampilkan mata kuliah: " << e.what() << endl;
    }
}

// Ubah data mata kuliah berdasarkan kode_mk
void MataKuliah::ubahMataKuliah(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "UPDATE mata_kuliah SET nama_mk = ?, sks = ?, id_jurusan = ?, id_dosen = ? WHERE kode_mk = ?"
        );
        pstmt->setString(1, nama_mk);
        pstmt->setInt(2, sks);
        pstmt->setInt(3, id_jurusan);
        pstmt->setInt(4, id_dosen);
        pstmt->setString(5, kode_mk);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Mata kuliah berhasil diperbarui.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal mengubah mata kuliah: " << e.what() << endl;
    }
}

// Hapus data berdasarkan kode_mk
void MataKuliah::hapusMataKuliah(Database& db, const string& kode_mk) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "DELETE FROM mata_kuliah WHERE kode_mk = ?"
        );
        pstmt->setString(1, kode_mk);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Mata kuliah berhasil dihapus.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menghapus mata kuliah: " << e.what() << endl;
    }
}