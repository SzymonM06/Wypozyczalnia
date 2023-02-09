#include <iostream>
#include <vector>
#include "klasy.h"
class Baza_samochodow{
    public:
        void add(const Samochod & s);
        void display() const;
        string show() const;
    private:
        vector<Samochod> samochody_;
};