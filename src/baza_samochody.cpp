#include "./include/baza_samochody.h"

void Baza_samochodow::add(const Samochod & s){
    samochody_.push_back(s);
}
void Baza_samochodow::display() {
    cout << show();
}
string Baza_samochodow::show() {
    string result = "";
    for (auto && samochod : samochody_) {
        result += samochod.show();
    }
    return result;
}