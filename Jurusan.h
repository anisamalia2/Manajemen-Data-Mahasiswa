#ifndef JURUSAN_H
#define JURUSAN_H

#include <string>
#include "Database.h"

class Jurusan {
private:
    int id_jurusan;
    std::string nama_jurusan;

public:
    Jurusan();
    Jurusan(int id, const std::string& nama);

    void tambahJurusan(Database& db);
    static void tampilkanSemuaJurusan(Database& db);
    void ubahJurusan(Database& db);
    static void hapusJurusan(Database& db, int id);
};

#endif
