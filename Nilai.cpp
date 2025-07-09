#include "Nilai.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

using namespace std;

Nilai::Nilai()
    : id_nilai(0), npm(""), kode_mk(""), nilai(0.0f) {
}

Nilai::Nilai(int id, const string& npm, const string& kode_mk, float nilai)
    : id_nilai(id), npm(npm), kode_mk(kode_mk), nilai(nilai) {
}

void Nilai::tambahNilai(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO nilai (npm, kode_mk, nilai_angka) VALUES (?, ?, ?)"
        );
        pstmt->setString(1, npm);
        pstmt->setString(2, kode_mk);
        pstmt->setDouble(3, nilai);
        pstmt->execute();
        delete pstmt;
        cout << "Nilai berhasil ditambahkan.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "Gagal menambahkan nilai: " << e.what() << endl;
    }
}

void Nilai::tampilkanNilai(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT n.id_nilai, m.nama AS nama_mahasiswa, mk.nama_mk, n.nilai "
            "FROM nilai n "
            "JOIN mahasiswa m ON n.npm = m.npm "
            "JOIN mata_kuliah mk ON n.kode_mk = mk.kode_mk"
        );

        cout << "\n Daftar Nilai Mahasiswa:\n";
        while (res->next()) {
            cout << "ID Nilai     : " << res->getInt("id_nilai")
                << ", Mahasiswa  : " << res->getString("nama_mahasiswa")
                << ", Mata Kuliah: " << res->getString("nama_mk")
                << ", Nilai      : " << res->getDouble("nilai") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "Gagal menampilkan nilai: " << e.what() << endl;
    }
}

void Nilai::ubahNilai(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "UPDATE nilai SET npm = ?, kode_mk = ?, nilai = ? WHERE id_nilai = ?"
        );
        pstmt->setString(1, npm);
        pstmt->setString(2, kode_mk);
        pstmt->setDouble(3, nilai);
        pstmt->setInt(4, id_nilai);
        pstmt->execute();
        delete pstmt;
        cout << "Nilai berhasil diperbarui.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "Gagal memperbarui nilai: " << e.what() << endl;
    }
}

void Nilai::hapusNilai(Database& db, int id) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "DELETE FROM nilai WHERE id_nilai = ?"
        );
        pstmt->setInt(1, id);
        pstmt->execute();
        delete pstmt;
        cout << "Nilai berhasil dihapus.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "Gagal menghapus nilai: " << e.what() << endl;
    }
}