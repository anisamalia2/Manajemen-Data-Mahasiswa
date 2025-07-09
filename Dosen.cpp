#include "Dosen.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

Dosen::Dosen() : Person(), id_dosen(0) {}

Dosen::Dosen(int id, const string& nama) : Person(nama), id_dosen(id) {}

void Dosen::tambahDosen(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO dosen (nama_dosen) VALUES (?)"
        );
        pstmt->setString(1, getNama()); // nama dari Person
        pstmt->execute();
        delete pstmt;

        cout << "✅ Dosen berhasil ditambahkan.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menambahkan dosen: " << e.what() << endl;
    }
}

void Dosen::tampilkanSemuaDosen(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM dosen");

        cout << "\n📋 Daftar Dosen:\n";
        while (res->next()) {
            cout << "ID: " << res->getInt("id_dosen")
                << ", Nama: " << res->getString("nama_dosen") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menampilkan dosen: " << e.what() << endl;
    }
}

void Dosen::ubahDosen(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "UPDATE dosen SET nama_dosen = ? WHERE id_dosen = ?"
        );
        pstmt->setString(1, getNama());
        pstmt->setInt(2, id_dosen);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Dosen berhasil diperbarui.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal mengubah dosen: " << e.what() << endl;
    }
}

void Dosen::hapusDosen(Database& db, int id) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "DELETE FROM dosen WHERE id_dosen = ?"
        );
        pstmt->setInt(1, id);
        pstmt->execute();
        delete pstmt;

        cout << "✅ Dosen berhasil dihapus.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menghapus dosen: " << e.what() << endl;
    }
}

void Dosen::tampilkanData() const {
    cout << "ID Dosen: " << id_dosen << ", Nama: " << getNama() << endl;
}
