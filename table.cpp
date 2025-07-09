#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;
/*
int main()
{
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "stlcf.l1ans");

        sql::Statement* stmt = con->createStatement();

        // Buat database jika belum ada
        stmt->execute("CREATE DATABASE IF NOT EXISTS mahasiswa_db");
        con->setSchema("mahasiswa_db");

        // Buat semua tabel
        stmt->execute("CREATE TABLE IF NOT EXISTS jurusan ("
            "id_jurusan INT AUTO_INCREMENT PRIMARY KEY,"
            "nama_jurusan VARCHAR(100) NOT NULL)");

        stmt->execute("CREATE TABLE IF NOT EXISTS dosen ("
            "id_dosen INT AUTO_INCREMENT PRIMARY KEY,"
            "nama_dosen VARCHAR(100) NOT NULL)");

        stmt->execute("CREATE TABLE IF NOT EXISTS mata_kuliah ("
            "kode_mk VARCHAR(10) PRIMARY KEY,"
            "nama_mk VARCHAR(100) NOT NULL,"
            "sks INT NOT NULL,"
            "id_jurusan INT,"
            "id_dosen INT,"
            "FOREIGN  KEY (id_jurusan) REFERENCES jurusan(id_jurusan),"
            "FOREIGN KEY (id_dosen) REFERENCES dosen(id_dosen))");
            

        stmt->execute("CREATE TABLE IF NOT EXISTS mahasiswa ("
            "npm VARCHAR(20) PRIMARY KEY,"
            "nama VARCHAR(100) NOT NULL,"
            "id_jurusan INT,"
            "FOREIGN KEY (id_jurusan) REFERENCES jurusan(id_jurusan))"
           );

        stmt->execute("CREATE TABLE IF NOT EXISTS nilai ("
            "id_nilai INT AUTO_INCREMENT PRIMARY KEY,"
            "npm VARCHAR(20),"  // konsisten dengan mahasiswa
            "kode_mk VARCHAR(10),"
            "nilai FLOAT,"
            "FOREIGN KEY (npm) REFERENCES mahasiswa(npm)," // sesuai mahasiswa
            "FOREIGN KEY (kode_mk) REFERENCES mata_kuliah(kode_mk))");

        stmt->execute("CREATE TABLE IF NOT EXISTS user ("
            "id_user INT AUTO_INCREMENT PRIMARY KEY,"
            "username VARCHAR(50) NOT NULL UNIQUE,"
            "password VARCHAR(100) NOT NULL,"
            "role ENUM('admin', 'operator') NOT NULL)");

        cout << "Semua tabel berhasil dibuat dengan NPM sebagai kunci utama!" << endl;

        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }

    return 0;
}
*/