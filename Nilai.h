#ifndef NILAI_H
#define NILAI_H

#include <string>
#include "Database.h"

class Nilai {
private:
    int id_nilai;
    std::string npm;
    std::string kode_mk;
    float nilai;

public:
    Nilai();
    Nilai(int id, const std::string& npm, const std::string& kode_mk, float nilai);

    void tambahNilai(Database& db);
    static void tampilkanNilai(Database& db);
    void ubahNilai(Database& db);
    static void hapusNilai(Database& db, int id);
};

#endif
