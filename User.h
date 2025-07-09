#ifndef USER_H
#define USER_H

#include "Database.h"
#include <string>

class User {
private:
    int id_user;
    std::string username;
    std::string password;

public:
    User();
    User(int id, std::string uname, std::string pass);

    bool login(Database& db);
    void tambahUser(Database& db); // jika ingin tambah user baru
    static void tampilkanUser(Database& db); // hanya untuk admin
};

#endif
