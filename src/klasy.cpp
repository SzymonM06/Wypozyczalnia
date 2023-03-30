#include "./include/klasy.h"


Samochod::Samochod(string firma,
                    string model,
                    string rocznik,
                    string przebieg,
                    string kolor,
                    string cena_za_dzien) 
    : firma_(firma),
    model_(model),
    rocznik_(rocznik),
    przebieg_(przebieg),
    kolor_(kolor),
    cena_za_dzien_(cena_za_dzien)
{}

Samochod::Samochod()
{
    
}

string Samochod::show()
{
    return firma_ 
        + "; " + model_ 
        + "; " + rocznik_ 
        + "; " + przebieg_ 
        + "; " + kolor_ 
        + "; " + cena_za_dzien_;
}