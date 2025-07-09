#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string nama;
public:
    Person();
    Person(string);
    virtual void tampilkanData() const;
    string getNama() const;
    void setNama(string);
};

#endif
