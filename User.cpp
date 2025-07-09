#include "User.h"
#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

using namespace std;

User::User() {}

User::User(int id, string uname, string pass)
    : id_user(id), username(uname), password(pass) {
}

bool User::login(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "SELECT * FROM user WHERE username = ? AND password = ?"
        );
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        sql::ResultSet* res = pstmt->executeQuery();

        bool isLogin = res->next(); // true jika ada hasil
        delete res;
        delete pstmt;

        return isLogin;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal login: " << e.what() << endl;
        return false;
    }
}

void User::tambahUser(Database& db) {
    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO user (username, password) VALUES (?, ?)"
        );
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->execute();
        delete pstmt;
        cout << "✅ User berhasil ditambahkan.\n";
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menambahkan user: " << e.what() << endl;
    }
}

void User::tampilkanUser(Database& db) {
    try {
        sql::Statement* stmt = db.getConnection()->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM user");

        cout << "\n📋 Daftar User:\n";
        while (res->next()) {
            cout << "ID: " << res->getInt("id_user")
                << ", Username: " << res->getString("username") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "❌ Gagal menampilkan user: " << e.what() << endl;
    }
}