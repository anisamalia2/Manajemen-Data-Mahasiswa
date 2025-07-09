#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
#include "Database.h"
#include "Person.h"

class Mahasiswa : public Person {
private:
    std::string npm;
    int id_jurusan;

public:
    Mahasiswa();
    Mahasiswa(const std::string& npm, const std::string& nama, int id_jurusan); // ✅ Sesuaikan const &

    void tambahMahasiswa(Database& db);
    static void tampilkanSemuaMahasiswa(Database& db);
    void tampilkanData() const override;
};

#endif
