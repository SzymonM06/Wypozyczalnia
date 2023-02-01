/**
 * @file main.cpp
 * @author SzymonM06 (Szymon Matłosz) i Dominikcsgo (Dominik Wnęk)
 * @brief Program służy jako aplikacja która działa jak Airbnb tylko że dla samochodów
 * Pozwala na wystawianie samochodów na wyporzyczenie oraz na wyporzyczenie wystawionych samochodów
 * Program zbiera informacje osób wystawiających samochody, osób wyporzyczających i wystawionych samochodów
 * @version 0.1
 * @date 2023-01-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream> 
#include <fstream>
using namespace std;
void wystawianie()/**
 * @brief Pyta o informacjie potrzebnę do wystawienia samochodu na wyporzyczenie oraz zapisuje je w bazach
 * 
 */
{
    string imie_wyst, nazwisko_wyst, adres_wyst, email_wyst, num_tel_wyst; //dane string wystawiającego
    char potwierdzenie_danych_wyst;
    string model, kolor, firma; //informacje o samochodzie string
    int rocznik, przebieg; //informacje o samochodzie int
    float cena_za_dzien; //info o samochodzie float
    char potwierdzenie_dodania; // potwierdzenia
    cout <<"Podaj swoje dane (Nie wstawiaj spacji lub polskich znakow!)"
        <<endl
        <<"Imie: ";
    cin >> imie_wyst; //wyst - osoby wystawiajacej na wyporzyczenie 
    cout <<"Nazwisko: ";
    cin >>nazwisko_wyst;
    cout <<"Adres (Ulica_Numer_Miasto): ";
    cin >>adres_wyst;
    cout <<"Numer telefonu (+48_000_000_000): ";
    cin >>num_tel_wyst;
    cin.ignore();
    cout <<"Email: ";
    cin >>email_wyst;
    cout << "Wyslac dane? (T/N)"<<endl;
    cin >>potwierdzenie_danych_wyst;
    if(potwierdzenie_danych_wyst == 'T' || potwierdzenie_danych_wyst == 't')
    {
        ofstream dane_wystawiajacych;
        dane_wystawiajacych.open("baza_wystawiajacych.txt", ios::app);
        dane_wystawiajacych << "Imie: "
                            << imie_wyst
                            << " || Nazwisko: "
                            <<nazwisko_wyst
                            <<" || Adres: "
                            <<adres_wyst
                            <<" || Numer telefonu: "
                            <<num_tel_wyst
                            <<" || Email: "
                            <<email_wyst;
        dane_wystawiajacych.close();
        cout <<"Podaj informacje dla samochodu ktorego chcialbys wystawic do naszej wyporzyczalni"<<endl
            <<"(Nie wstawiaj spacji lub polskich znakow!)"<<endl;
        cout<<"Firma: ";
        cin>> firma;
        cout<<"Model: ";
        cin >> model;
        cout << "Rocznik: ";
        cin >> rocznik;
        cout << "Przebieg: (tylko liczby, 5000 (dobrze), 5k (zle))";
        cin >> przebieg;
        cout <<"Kolor: ";
        cin >> kolor;
        cout <<"Cena za dzien: (PLN, tylko liczby)";
        cin >> cena_za_dzien;
        cout <<endl<<"Dodaj samochod? (T/N)" <<endl;
        cin >> potwierdzenie_dodania;
        if(potwierdzenie_dodania == 'T' || potwierdzenie_dodania == 't')
        {
            ofstream dodaj_samochod;
            dodaj_samochod.open("baza_samochodow.txt", ios::app);
            if(dodaj_samochod.is_open())
            {
                dodaj_samochod <<"Firma: "
                    << firma 
                    << " || Model: " 
                    << model 
                    << " || Rocznik: "
                    << rocznik
                    << " || Przebieg: " 
                    << przebieg
                    <<" || Kolor: "
                    << kolor
                    <<" || Cena za dzien: "
                    << cena_za_dzien<<endl;
            }
            dodaj_samochod.close();
        }
    }
}
void wypozyczanie()
{
    string imie_wyp, nazwisko_wyp, adres_wyp, email_wyp, num_tel_wyp; //dane string wyporzyczającego
    char potwierdzenie_danych_wyp;
    int id_samochodu; // id samochodu wybrane przez wypozyczajacego
    int x=0; //liczba linii
    string samochod[x];
    ifstream wczytywanie_baza_samochodow;
    wczytywanie_baza_samochodow.open("baza_samochodow.txt");
    if(wczytywanie_baza_samochodow.is_open())
    {
        cout<<endl<<"---------------------------------------------"<<endl;
        string linia;
        while (getline(wczytywanie_baza_samochodow, linia))
        {
            x++;
            cout<<x<<". "<<linia<<endl<<"---------------------------------------------"<<endl; 
        }
        cout<<endl;
        cout << "Ilosc samochodow na wynajem: " << x<<endl;
        int a = 0;
        for(string linia2;getline(wczytywanie_baza_samochodow, linia2);)
        {
            samochod[a]=linia2;
            a++;
        }
    }
    wczytywanie_baza_samochodow.close();
    cout <<"Wybierz samochod do wypozyczenia (numer ID): ";
    cin >> id_samochodu;
    id_samochodu = id_samochodu - 1;
    // cout << samochod[id_samochodu];

    

    cout <<"Podaj swoje dane (Nie wstawiaj spacji lub polskich znakow!)"
        <<endl
        <<"Imie: ";
    cin >> imie_wyp; //wyp - wypożyczający
    cout <<"Nazwisko: ";
    cin >>nazwisko_wyp;
    cout <<"Adres (Ulica_Numer_Miasto): ";
    cin >>adres_wyp;
    cout <<"Numer telefonu (+48_000_000_000):";
    cin >>num_tel_wyp;
    cout <<"Email: ";
    cin >>email_wyp;
    cout << "Wyslac dane? (T/N)"<<endl;
    cin >>potwierdzenie_danych_wyp;
    if(potwierdzenie_danych_wyp == 'T' || potwierdzenie_danych_wyp == 't')
    {
        ofstream dane_wyporzyczajacych;
        dane_wyporzyczajacych.open("baza_wyporzyczajacych.txt", ios::app);
        dane_wyporzyczajacych << "Imie: "
                            << imie_wyp
                            << " || Nazwisko: "
                            <<nazwisko_wyp
                            <<" || Adres: "
                            <<adres_wyp
                            <<" || Numer telefonu: "
                            <<num_tel_wyp
                            <<" || Email: "
                            <<email_wyp;
        dane_wyporzyczajacych.close();
    }
}
int main()
{
    char co_uzytkownik_chce;
    cout <<"+--------------------------------------------+"<<endl
        <<"| Witam w naszej  internetowej wypozyczalni! |"<<endl
        <<"+--------------------------------------------+"<<endl<<endl
        <<"Wyporzycz samochod (A)"<<endl
        <<"Wystaw samochod na wyporzyczenie (B)"<<endl
        <<"Wyjdz (jaki kolwiek inny znak)"<<endl;
    cin >> co_uzytkownik_chce;
    if(co_uzytkownik_chce == 'A' || co_uzytkownik_chce == 'a')
    {  
        wypozyczanie();
    }
    if(co_uzytkownik_chce == 'B' || co_uzytkownik_chce == 'b')
    {
        wystawianie(); 
    }
    if(co_uzytkownik_chce != 'A' || co_uzytkownik_chce != 'a' || co_uzytkownik_chce != 'B' || co_uzytkownik_chce != 'b')
    {
        return 0;
    }
}