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
    char czywyporzycza; //pyta czy urzytkownik wyporzycza samochod
    char czydodaje; //pyta czy urzytkownik dodaj samochod do wyporzyczalni 
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
    cin >> czywyporzycza;
    if(czywyporzycza == 'T' || czywyporzycza == 't')
    {

    }
    else
    {
        cout << "Czy chcialbys dodac samochod do wypozyczalni? (T/N)"<<endl;
        cin >> czydodaje;
        if(czydodaje == 'T' || czydodaje == 't')
        {
            cout <<"Podaj informacje dla samochodu ktorego chcialbys wystawic do naszej wyporzyczalni"
                <<endl;
            cout<<"Firma: ";
            cin>> firma;
            cout<<"Model: ";
            cin >> model;
            cout <<"Kolor: ";
            cin >> kolor;
            cout <<endl<<"Dodaj samochod? (T/N)" <<endl;
            cin >> potwierdzenie_dodania;
            if(potwierdzenie_dodania == 'T' || potwierdzenie_dodania == 't')
            {
                fstream plik;
                plik.open("plik.txt");
                    plik <<"Firma: "<< firma << " || Model: " << model <<" || Kolor: " << kolor;
                plik.close();
            }
            
        } 
        else
        {
            return 0;
        }
    }
}