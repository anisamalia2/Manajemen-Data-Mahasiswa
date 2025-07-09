#ifndef DATABASE_H
#define DATABASE_H

#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <string>

class Database {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    Database();
    ~Database();

    sql::Connection* getConnection();
};

#endif