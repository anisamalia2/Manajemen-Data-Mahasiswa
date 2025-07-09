#ifndef MATAKULIAH_H
#define MATAKULIAH_H

#include <string>
#include "Database.h"

class MataKuliah {
private:
    std::string kode_mk;
    std::string nama_mk;
    int sks;
    int id_jurusan;
    int id_dosen;

public:
    MataKuliah();
    MataKuliah(const std::string& kode_mk, const std::string& nama_mk, int sks, int id_jurusan, int id_dosen);

    void tambahMataKuliah(Database& db);
    static void tampilkanSemuaMataKuliah(Database& db);
    void ubahMataKuliah(Database& db);
    static void hapusMataKuliah(Database& db, const std::string& kode_mk);
};

#endif