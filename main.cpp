/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream> 
#include <fstream>
using namespace std;
int main()
{
    char czy_wyporzycza; //pyta czy urzytkownik wyporzycza samochod
    char czy_dodaje; //pyta czy urzytkownik dodaj samochod do wyporzyczalni 
    char potwierdzenie_dodania;
    string model; //model samochodu
    string kolor; //kolor samochodu
    string firma;

    cout <<"+-------------------------------------------+"
        <<endl
        <<"| Witam w naszej  internetowej wypozyczalni! |"
        <<endl
        <<"+-------------------------------------------+"
        <<endl
        <<endl
        <<"Czy chcialbys wypozyczyc samochod? (T/N)"<<endl;
    cin >> czy_wyporzycza;
    if(czy_wyporzycza == 'T' || czy_wyporzycza == 't')
    {
        int wielkosc_tablicy;
        string tab[wielkosc_tablicy];
        ifstream wczytywanie_bazy;
        wczytywanie_bazy.open("baza.txt");
        if(wczytywanie_bazy.is_open())
        {
            wczytywanie_bazy >> wielkosc_tablicy;
            for(int i=0;i<wielkosc_tablicy;i++)
            {
                wczytywanie_bazy >> tab[i];
            }
        }
        wczytywanie_bazy.close();
        for(int i=0; i<wielkosc_tablicy; i++)
        {
            cout << tab[i];
        }
    }
    else
    {
        cout << "Czy chcialbys dodac samochod do wypozyczalni? (T/N)"<<endl;
        cin >> czy_dodaje;
        if(czy_dodaje == 'T' || czy_dodaje == 't')
        {
            cout <<"Podaj informacje dla samochodu ktorego chcialbys wystawic do naszej wyporzyczalni"
                <<endl;
            cout<<"Firma: ";
            cin>> firma;
            cout<<"Model: ";
            cin >> model;
            cout << "Rocznik: ";

            cout << "Przebieg: ";

            cout <<"Kolor: ";
            cin >> kolor;
            cout <<endl<<"Dodaj samochod? (T/N)" <<endl;
            cin >> potwierdzenie_dodania;
            if(potwierdzenie_dodania == 'T' || potwierdzenie_dodania == 't')
            {
                ofstream dodaj;
                dodaj.open("baza.txt", ios::app);
                if(dodaj.is_open())
                {
                    dodaj <<"Firma: "<< firma << " || Model: " << model <<" || Kolor: " << kolor <<endl;
                }
                dodaj.close();
            }
            
        } 
        else
        {
            return 0;
        }
    }
}