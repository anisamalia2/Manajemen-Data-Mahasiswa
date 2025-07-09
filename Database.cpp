#include "Database.h"
#include <iostream>

Database::Database() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "stlcf.l1ans");
        con->setSchema("mahasiswa_db");
    }
    catch (sql::SQLException& e) {
        std::cerr << "Koneksi database gagal: " << e.what() << std::endl;
        exit(1);
    }
}

Database::~Database() {
    delete con;
}

sql::Connection* Database::getConnection() {
    return con;
}