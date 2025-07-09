#include "Person.h"
#include <iostream>

Person::Person() : nama("") {}
Person::Person(string n) : nama(n) {}

void Person::tampilkanData() const {
    cout << "Nama: " << nama << endl;
}

string Person::getNama() const {
    return nama;
}

void Person::setNama(string n) {
    nama = n;
}
