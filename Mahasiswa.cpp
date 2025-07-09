#include "Mahasiswa.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

Mahasiswa::Mahasiswa() : Person(), npm(""), id_jurusan(0) {}

Mahasiswa::Mahasiswa(const string& npm, const string& nama, int id_jurusan)
    : Person(nama), npm(npm), id_jurusan(id_jurusan) {
}

void Mahasiswa::tambahMahasiswa(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO mahasiswa (npm, nama, id_jurusan) VALUES (?, ?, ?)"
        );
        pstmt->setString(1, npm);
        pstmt->setString(2, getNama()); // ambil dari class Person
        pstmt->setInt(3, id_jurusan);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Mahasiswa berhasil ditambahkan." << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menambahkan mahasiswa: " << e.what() << endl;
    }
}

void Mahasiswa::tampilkanSemuaMahasiswa(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT m.npm, m.nama, j.nama_jurusan FROM mahasiswa m "
            "JOIN jurusan j ON m.id_jurusan = j.id_jurusan "
        );

        cout << "\n📋 Daftar Mahasiswa:\n";
        while (res->next()) {
            cout << "NPM: " << res->getString("npm")
                << ", Nama: " << res->getString("nama")
                << ", Jurusan: " << res->getString("nama_jurusan")
                << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menampilkan mahasiswa: " << e.what() << endl;
    }
}

void Mahasiswa::tampilkanData() const {
    cout << "NPM: " << npm << ", Nama: " << getNama()
        << "ID Jurusan: " << id_jurusan
        << endl;
}
