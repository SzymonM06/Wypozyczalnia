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
#include <sstream>
using namespace std;

string szukajUzytkownika(const string& fileName, const string& dowod) {
    ifstream file(fileName);
    string line;

    while (getline(file, line)) {
        stringstream iss(line);
        string extractedID;

        if (getline(iss, extractedID, ':')) {
            if (extractedID == dowod) {
                return line;
            }
        }
    }

    return "";
}

int main()
{
    system("@chcp 65001 >nul & cls"); //batch, Polskie znaki
    string imie, nazwisko, marka, model, dzien_wypozyczenia, miesiac_wypozyczenia, rok_wypozyczenia, numer_dowodu, numer_rejestracyjny;
    int co_uzytkownik_chce;
    cout << "+------------------------------+" << endl;
    cout << "| Witaj w naszej wypożyczalni! |" << endl;
    cout << "+------------------------------+" << endl;

    cout << endl << "Co chcesz zrobic?" << endl
         << "1. Wypożyczyć samochód" << endl
         << "2. Oddać wypozyczony samochód" << endl
         << "3. Wyświetlić liste samochodów" << endl
         << "4. Wyjść" << endl << endl;
    cin >> co_uzytkownik_chce;
    cout << endl;

    if (co_uzytkownik_chce == 1)
    {
        vector<string> dane;
        while (true)
        {
            cout << endl << "Podaj swoje imie: ";
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
            cout << "Podaj dzień wypozyczenia samochodu: ";
            cin >> dzien_wypozyczenia;
            cout << "Podaj miesiac wypozyczenia samochodu: ";
            cin >> miesiac_wypozyczenia;
            cout << "Podaj rok wypozyczenia samochodu: ";
            cin >> rok_wypozyczenia;

            // Zapisywanie danych do wektora

            dane.push_back(imie + ":" + nazwisko + ":" + numer_dowodu + ":" + numer_rejestracyjny + ":" + marka + ":" + model + ":" + dzien_wypozyczenia + "." + miesiac_wypozyczenia + "." + rok_wypozyczenia);

            // Wyświetlanie danych na ekranie
            cout << "Czy dane są poprawne? (T/N): ";
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
        ofstream plik("dane_uzytkownika.txt", ios::app);
        if (plik.is_open())
        {
            for (auto &dana : dane)
            {
                plik << dana << endl;
            }
            plik.close();
            cout << endl << "Dane zostały zapisane." << endl << endl;
        }
        else
        {
            cout << endl << "Nie udało sie otworzyc pliku dane_uzytkownika.txt." << endl << endl;
        }
    }
    else if (co_uzytkownik_chce == 2)
    {
        cout << "Podaj swoje imie: ";
        cin >> imie;
        cout << "Podaj swoje nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj numer swojego dowodu osobistego: ";
        cin >> numer_dowodu;
        cout << "Podaj numer rejestracyjny samochodu: ";
        cin >> numer_rejestracyjny;  
        string nazwaPliku = "dane_uzytkownika.txt";
        string foundLine = szukajUzytkownika(nazwaPliku, numer_dowodu);
        if (!foundLine.empty()) {
            cout << foundLine << endl;
        } else {
            cout << "Nie znaleziono użytkownika, upewnij sie że dobrze wpisany jest numer dowodu." << endl;
        }
    }
    else if(co_uzytkownik_chce == 3) 
    {
        string linia;
        ifstream mojPlik("baza_samochodow.txt");
        if(mojPlik.is_open())
        {
            while(!mojPlik.eof())
            {
                getline(mojPlik, linia);
                cout << linia << endl;
            }
            mojPlik.close();
        }
        else cout << "Nie można otworzyć pliku";
    }
}
