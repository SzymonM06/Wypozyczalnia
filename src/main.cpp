/**
 * @file main.cpp
 * @author SzymonM06 (Szymon Matłosz) i Dominikcsgo (Dominik Wnęk)
 * @brief Program służy jako internetowa wypozyczalnia samochodow.
 * @version 0.1
 * @date 2023-01-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout << "+------------------------------+" <<endl;
    cout << "| Witaj w naszej wypozyczalni! |" <<endl;
    cout << "+------------------------------+" <<endl; 


    vector<string> dane_zwracanego_samochodu;
    vector<string> dane;
    string imie, nazwisko, marka, model, dzien_wypozyczenia,miesiac_wypozyczenia,rok_wypozyczenia;
    
    int numer_rejestracyjny,numer_dowodu;

    while (true)
    {
        cout << "Podaj swoje imie: ";
        cin >> imie;
        cout << "Podaj swoje nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj numer swojego dowodu osobistego: ";
        cin >> numer_dowodu;
        cout << "Podaj numer rejestracyjny samochodu: ";
        cin >> numer_rejestracyjny;
        cout << "Podaj marke samochodu: ";
        cin >> marka;
        cout << "Podaj model samochodu: ";
        cin >> model;
        cout << "Podaj dzien wypozyczenia samochodu: ";
        cin >> dzien_wypozyczenia;
        cout << "Podaj miesiac wypozyczenia samochodu: ";
        cin >> miesiac_wypozyczenia;
        cout << "Podaj rok wypozyczenia samochodu: ";
        cin >> rok_wypozyczenia;

        // Zapisywanie danych do wektora
        dane.push_back(imie + ":" + nazwisko + ":" + to_string(numer_dowodu) + ":" + to_string(numer_rejestracyjny) + ":" + marka + ":" + model + " " + dzien_wypozyczenia+" "+ miesiac_wypozyczenia+" "+rok_wypozyczenia);

        // Wyświetlanie danych na ekranie
        cout << "Czy dane sa poprawne? (T/N): ";
        char potwierdzenie;
        cin >> potwierdzenie;
        if (potwierdzenie == 'T' || potwierdzenie == 't')
        {
            break;
        }
        else
        {
            dane.pop_back(); // Usuwanie ostatnio wprowadzonych danych z wektora
        }
    }

    // Zapisywanie danych do pliku tekstowego
    ofstream plik("dane_wypozyczajacego.txt",ios::app);
    if (plik.is_open())
    {
        for (auto &dana : dane)
        {
            plik << dana << endl;
        }
        plik.close();
        cout << "Dane zostaly zapisane do pliku dane.txt." << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku dane.txt." << endl;
    }

    return 0;
}
