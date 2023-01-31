#include <iostream> 
#include <fstream>
using namespace std;
int main()
{
    char czywyporzycza;
    char czydodaje;
    cout <<"+-----------------------------+"
        <<endl
        <<"| Witam w naszej wypozyczalni |"
        <<endl
        <<"+-----------------------------+"
        <<endl
        <<endl
        <<"Czy chcialbys wypozyczyc samochod? (Y/N)"<<endl;
    cin >> czywyporzycza;
    if(czywyporzycza == 'Y')
    {

    }
    else
    {
        cout << "Czy chcialbys dodac samochod do wypozyczalni? (Y/N)"<<endl;
        cin >> czydodaje;
        if(czydodaje == 'Y')
        {

        } 
        else
        {
            return 0;
        }
    }
    fstream plik;
    plik.open("plik.txt");
    
    plik.close();
}