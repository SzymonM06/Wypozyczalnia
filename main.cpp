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
string model; //model samochodu
string kolor; //kolor samochodu
string firma; //firma ktora wyprodukowala dany samochod
int rocznik; //rok produkcji samochodu
int przebieg; //przebieg samochodu
char potwierdzenie_dodania; //pyta o potwierdzenie wystawienia samochodu na wyporzyczenie
char potwierdzenie_zmiany_danych; // pyta czy chcesz zmienic dany wystawianego samochodu czy wyjsc z ap.

void dodawanie_do_bazy()/**
 * @brief Dodaje informacje samochodu wystawianego na wynajem do bazy 
 * 
 */
{
    cout <<"Podaj informacje dla samochodu ktorego chcialbys wystawic do naszej wyporzyczalni"//dialog z użytkownikiem
        <<endl
        <<"(Nie wstawiaj spacji lub polskich znakow!)"
        <<endl;
    cout<<"Firma: ";
    cin>> firma;
    cout<<"Model: ";
    cin >> model;
    cout << "Rocznik: ";
    cin >> rocznik;
    cout << "Przebieg: ";
    cin >> przebieg;
    cout <<"Kolor: ";
    cin >> kolor;
    cout <<endl<<"Dodaj samochod? (T/N)" <<endl; //potwierdzenie 
    cin >> potwierdzenie_dodania;
    if(potwierdzenie_dodania == 'T' || potwierdzenie_dodania == 't')
    {
        ofstream dodaj;
        dodaj.open("baza_samochodow.txt", ios::app);
        if(dodaj.is_open())
        {
            dodaj <<"Firma: " //wpisuje do bazy
                << firma 
                << " || Model: " 
                << model 
                << " || Rocznik: "
                << rocznik
                << " || Przebieg: " 
                << przebieg
                <<" || Kolor: "
                << kolor
                <<endl;
        }
        dodaj.close();
    }
}
int main()
{
    
    string imie_wyst; //imie osoby wystawiającej samochod na wypozyczenie 
    string nazwisko_wyst; //nazwisko osoby wystawiającej samochod na wypozyczenie 
    string adres_wyst; //adres osoby wystawiającej samochod na wypozyczenie 
    int num_tel_wyst; //numer telefonu osoby wystawiającej samochod na wypozyczenie 
    string email_wyst; // email osoby wystawiającej samochod na wypozyczenie 
    char potwierdzenie_danych_wyst; // potwierdzenie podanych danych osoby wystawiającej samochod na wypozyczenie 
    char czy_wyporzycza; //pyta czy urzytkownik wyporzycza samochod
    char czy_dodaje; //pyta czy urzytkownik dodaj samochod do wyporzyczalni 
    cout <<"+--------------------------------------------+"//powitanie
        <<endl
        <<"| Witam w naszej  internetowej wypozyczalni! |"
        <<endl
        <<"+--------------------------------------------+"
        <<endl
        <<endl
        <<"Czy chcesz wypozyczyc samochod? (T/N)"<<endl;
    cin >> czy_wyporzycza;
    if(czy_wyporzycza == 'T' || czy_wyporzycza == 't')//work in progress
    {
        cout<<"+-------------------------------------------+"<<endl;
        ifstream wczytywanie_bazy;
        wczytywanie_bazy.open("baza_samochodow.txt");
        int x=0; //liczba linii
        string samochod[x];
        string linia;
        while (getline(wczytywanie_bazy, linia))
        {
             x++;
             cout<<x<<"."<<linia<<"\n"<<"---------------------------------------------"<<endl;;
             
        }

        cout<<"+-------------------------------------------+"<<endl;
        cout << "Ilosc samochodow na wynajem: " << x<<endl;
        int x2=0;
        samochod[x];
        while(getline(wczytywanie_bazy,linia))
        {
            samochod[x2]=linia;
            x2++;
        }
        for(int i=0;i<x2;i++)
        {
            cout<<samochod[i];
        }
        int a;
        cout<<"Podaj numer ktory samochod chcesz wyswietlic"<<endl;
        cin>>a;
        cout<<samochod[a];
      
        wczytywanie_bazy.close();
    }
    else
    {
        cout << "Czy chcesz dodac samochod do wypozyczalni? (T/N)"<<endl;
        cin >> czy_dodaje;
        if(czy_dodaje == 'T' || czy_dodaje == 't')
        {
            cout <<"Podaj swoje dane (Nie wstawiaj spacji lub polskich znaków!)"
                <<endl
                <<"Imie: ";
            cin >> imie_wyst; //wyst - osoby wystawiajacej na wyporzyczenie 
            cout <<"Nazwisko: ";
            cin >>nazwisko_wyst;
            cout <<"Adres (Ulica_Numer_Miasto): ";
            cin >>adres_wyst;
            cout <<"Numer telefonu (+48_000_000_000):";
            cin >>num_tel_wyst;
            cout <<"Email: ";
            cin >>email_wyst;
            cout << "Wyslac dane? (T/N)"<<endl;
            cin >>potwierdzenie_danych_wyst;
            if(potwierdzenie_danych_wyst == 'T' || potwierdzenie_danych_wyst == 't')
            {
                ofstream dane_wystawiajacych;
                dane_wystawiajacych.open("baza_wystawiajacych.txt");
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
            }
            dodawanie_do_bazy();
        } 
        else
        {
            return 0;
        }
    }
}