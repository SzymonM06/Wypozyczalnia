#ifndef BAZA_SAMOCHODY
#define BAZA_SAMOCHODY

#include <iostream>
#include <vector>
#include "klasy.h"

class Baza_samochodow
{
private:
    vector<Samochod> samochody_;

public:
    void add(const Samochod &s);
    void display();
    string show();
};

#endif