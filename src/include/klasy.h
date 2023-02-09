#include <iostream>
using namespace std;
class Samochod{
    public:
        Samochod(
            string firma,
            string model,
            string rocznik,
            string przebieg,
            string kolor,
            string cena_za_dzien);
        string show() const;
    private: 
        string firma_;
        string model_;
        string rocznik_;
        string przebieg_;
        string kolor_;
        string cena_za_dzien_;
};
