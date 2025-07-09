#ifndef DOSEN_H
#define DOSEN_H

#include <string>
#include "Database.h"
#include "Person.h"

class Dosen : public Person {
private:
    int id_dosen;

public:
    Dosen();
    Dosen(int id, const std::string& nama);

    void tambahDosen(Database& db);
    static void tampilkanSemuaDosen(Database& db);
    void ubahDosen(Database& db);
    static void hapusDosen(Database& db, int id);
    void tampilkanData() const override;
};

#endif
