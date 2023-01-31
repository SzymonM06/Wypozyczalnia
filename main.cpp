/**
 * @file main.cpp
 * @author Szymon Matłosz i Dominik Wnęk
 * @brief Program służy jako aplikacja dla wyporzyczalni aut 
 * która pozwala na wyświetlanie, dodawanie i edytowanie danych o samochodach wystawnionych na wynajem
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
        int x=0; //liczba linii
        ifstream wczytywanie_bazy;
        wczytywanie_bazy.open("baza_samochodow.txt");
        string placeholder;
        while (getline(wczytywanie_bazy, placeholder))
        x++;
        cout << x;
        wczytywanie_bazy.close();
    }
    else
    {
        cout << "Czy chcesz dodac samochod do wypozyczalni? (T/N)"<<endl;
        cin >> czy_dodaje;
        if(czy_dodaje == 'T' || czy_dodaje == 't')
        {
            cout <<"Podaj swoje dane"
                <<endl
                <<"Imie: ";
            cin >> imie_wyst; //wyst - osoby wystawiajacej na wyporzyczenie 
            cout <<"Nazwisko: ";
            cin >>nazwisko_wyst;
            cout <<"Adres: ";
            cin >>adres_wyst;
            cout <<"Numer telefonu: ";
            cin >>num_tel_wyst;
            cout <<"Email: ";
            cin >>email_wyst;
            cout << "Wyslac dane? (T/N)";
            cin >>potwierdzenie_danych_wyst;
            if(potwierdzenie_danych_wyst == 'T' || potwierdzenie_danych_wyst == 't')
            {
                ofstream wystawiajacych;
                wystawiajacych.open("baza_wystawiajacych.txt");
                wystawiajacych.close();
            }
            dodawanie_do_bazy();
        } 
        else
        {
            return 0;
        }
    }
}