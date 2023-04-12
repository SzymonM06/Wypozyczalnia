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
int main()
{
    char co_uzytkownik_chce;
    cout << "+--------------------------------------------+" << endl
         << "| Witam w naszej  internetowej wypozyczalni! |" << endl
         << "+--------------------------------------------+" << endl
         << endl
         << "Wyporzycz samochod (A)" << endl
         << "Wystaw samochod na wyporzyczenie (B)" << endl
         << "Wyjdz (jaki kolwiek inny znak)" << endl;
    cin >> co_uzytkownik_chce;
}