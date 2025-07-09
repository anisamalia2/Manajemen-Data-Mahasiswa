#include "Jurusan.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

Jurusan::Jurusan() {}

Jurusan::Jurusan(int id, const string& nama) : id_jurusan(id), nama_jurusan(nama) {}

void Jurusan::tambahJurusan(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO jurusan (nama_jurusan) VALUES (?)"
        );
        pstmt->setString(1, nama_jurusan);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Jurusan berhasil ditambahkan.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menambahkan jurusan: " << e.what() << endl;
    }
}

void Jurusan::tampilkanSemuaJurusan(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM jurusan");

        cout << "\n📋 Daftar Jurusan:\n";
        while (res->next()) {
            cout << "ID: " << res->getInt("id_jurusan")
                << ", Nama: " << res->getString("nama_jurusan") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menampilkan jurusan: " << e.what() << endl;
    }
}

void Jurusan::ubahJurusan(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "UPDATE jurusan SET nama_jurusan = ? WHERE id_jurusan = ?"
        );
        pstmt->setString(1, nama_jurusan);
        pstmt->setInt(2, id_jurusan);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Jurusan berhasil diperbarui.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal mengubah jurusan: " << e.what() << endl;
    }
}

void Jurusan::hapusJurusan(Database& db, int id) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "DELETE FROM jurusan WHERE id_jurusan = ?"
        );
        pstmt->setInt(1, id);
        pstmt->execute();
        delete pstmt;

        cout << "🗑️ Jurusan berhasil dihapus.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menghapus jurusan: " << e.what() << endl;
    }
}