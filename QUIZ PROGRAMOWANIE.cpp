#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

int wybor_w_menu=0;
bool zlaopcja;
int dlugosc=80;
HANDLE kolor = GetStdHandle(STD_OUTPUT_HANDLE);
string cos_z_klawiatury;


int main()
{
    while(wybor_w_menu!=14)
    {
        SetConsoleTextAttribute(kolor, 15);
        system("cls");
        for(int i=0; i<dlugosc; i++)
        cout<<char(177);
        SetConsoleTextAttribute(kolor, 14);
        cout<<endl<<"                 Programowanie projekt QUIZ Student CDV 2016"<<endl<<endl;
        SetConsoleTextAttribute(kolor, 15);
        for(int i=0; i<dlugosc; i++)
        cout<<char(177);
        SetConsoleTextAttribute(kolor, 12);
        cout<<endl<<"                          Wybierz swoja dziedzine :) "<<char(2)<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"==============================================================================="<<endl<<endl;
                                                                  SetConsoleTextAttribute(kolor, 10);
        cout<<"  1.  Sport "<<endl;                               SetConsoleTextAttribute(kolor, 10);
        cout<<"  2.  Samochody "<<endl;                           SetConsoleTextAttribute(kolor, 10);
        cout<<"  3.  Panstwa Swiata "<<endl;                      SetConsoleTextAttribute(kolor, 10);
        cout<<"  4.  Matematyka "<<endl;                          SetConsoleTextAttribute(kolor, 10);
        cout<<"  5.  Alkohole "<<endl;                            SetConsoleTextAttribute(kolor, 10);
        cout<<"  6.  Historia Polski "<<endl;                     SetConsoleTextAttribute(kolor, 10);
        cout<<"  7.  Stolice Swiata "<<endl;                      SetConsoleTextAttribute(kolor, 10);
        cout<<"  8.  Programowanie "<<endl;                       SetConsoleTextAttribute(kolor, 10);
        cout<<"  9.  Biblia "<<endl;                              SetConsoleTextAttribute(kolor, 10);
        cout<<" 10.  Pilka nozna "<<endl;                         SetConsoleTextAttribute(kolor, 10);
        cout<<" 11.  Koniec programu "<<endl<<endl;
        cout<<"|| Michal Kubczak CDV ||"<<endl<<endl;             SetConsoleTextAttribute(kolor, 15);

        cout<<"==============================================================================="<<endl;
        SetConsoleTextAttribute(kolor, 12);
        cout<<"      Twoj wybor (wpisz nr wybranej opcji): ";
        SetConsoleTextAttribute(kolor, 15);
        cin>>cos_z_klawiatury;

  
        zlaopcja=false;
        for(int i=0; i<cos_z_klawiatury.length(); i++)
        {
            if ((cos_z_klawiatury[i]<48)||(cos_z_klawiatury[i]>57)) zlaopcja=true;
    
        }
        if (zlaopcja==false) wybor_w_menu=atoi(cos_z_klawiatury.c_str());

 
        string temat, nick;
        string tresc[5], odpA[5], odpB[5], odpC[5], odpD[5], poprawna[5];
        string odpowiedz;
        int punkty=0;

 
        int nr_linii=1;
        string linia;
        int nr_pytania=0;
        fstream plik;



        switch(wybor_w_menu)
        {
            case 1: plik.open("pytania/pytania1.txt",ios::in); break;
            case 2: plik.open("pytania/pytania2.txt",ios::in); break;
            case 3: plik.open("pytania/pytania3.txt",ios::in); break;
            case 4: plik.open("pytania/pytania4.txt",ios::in); break;
            case 5: plik.open("pytania/pytania5.txt",ios::in); break;
            case 6: plik.open("pytania/pytania6.txt",ios::in); break;
            case 7: plik.open("pytania/pytania7.txt",ios::in); break;
            case 8: plik.open("pytania/pytania8.txt",ios::in); break;
            case 9: plik.open("pytania/pytania9.txt",ios::in); break;
            case 10: plik.open("pytania/pytania10.txt",ios::in); break;
            case 11: {
                        cout<<endl<<"Koniec programu! Dzieki za gre!"<<endl;
                        exit(0);
                    } break;
            default: zlaopcja=true; break;
        }

        if (plik.good()==false)
        {
            cout<<"Och nie! Nie udalo sie otworzyc pliku z pytaniami!"<<endl<<endl;
        }

        else if (zlaopcja==true) 
        {
            cout<<endl;
            SetConsoleTextAttribute(kolor, 12);
            cout<<"==============================================================================="<<endl;
            cout<<"                         Nie ma takiej opcji w menu!"<<endl;
            cout<<"==============================================================================="<<endl<<endl;
            SetConsoleTextAttribute(kolor, 12);
            cout<<"Sproboj wprowadzic liczbe z zakresu od 1-10, w przeciwnym razie nigdy nie uda ci sie zagrac!"<<endl;
            SetConsoleTextAttribute(kolor, 15);
            system("pause");
        }
        else 
        {
            while(getline(plik,linia))
            {
                switch(nr_linii)
                {
                    case 1: temat=linia;                    break;
                    case 2: linia;                          break;
                    case 3: tresc[nr_pytania] = linia;      break;
                    case 4: odpA[nr_pytania] = linia;       break;
                    case 5: odpB[nr_pytania] = linia;       break;
                    case 6: odpC[nr_pytania] = linia;       break;
                    case 7: odpD[nr_pytania] = linia;       break;
                    case 8: poprawna[nr_pytania] = linia;   break;
                }
                if (nr_linii==8)
                {
                    nr_linii=2;
                    nr_pytania++;
                }
                nr_linii++;
            }

            plik.close();

            system("cls");
            for(int i=0; i<dlugosc; i++)
            cout<<char(177);
            cout<<endl<<"                             WYBRANO QUIZ: ";
            SetConsoleTextAttribute(kolor, 14);
            cout<<temat<<endl<<endl;
            SetConsoleTextAttribute(kolor, 15);
            for(int i=0; i<dlugosc; i++)
            cout<<char(177);

            for (int i=0; i<=4; i++)
            {
                SetConsoleTextAttribute(kolor, 14);
                cout<<endl<<tresc[i]<<endl;
                SetConsoleTextAttribute(kolor, 15);
                cout<<"==============================================================================="<<endl;
                cout<<"A. "<<odpA[i]<<endl;
                cout<<"B. "<<odpB[i]<<endl;
                cout<<"C. "<<odpC[i]<<endl;
                cout<<"D. "<<odpD[i]<<endl;
                cout<<"==============================================================================="<<endl;
                SetConsoleTextAttribute(kolor, 14);
                cout<<"Twoja odpowiedz (a,b,c,d): ";
                cin>>odpowiedz;

                transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);

                if (odpowiedz==poprawna[i])
                {
                    SetConsoleTextAttribute(kolor, 10);
                    cout<<endl<<"Just like that! Zdobywasz punkt!"<<endl;
                    punkty++;
                }
                else
                {
                    SetConsoleTextAttribute(kolor, 12);
                    cout<<endl<<"Noob! Zle odpowiedziales, Brak punktu! Poprawna odpowiedz to: "<<poprawna[i]<<endl;
                }
                SetConsoleTextAttribute(kolor, 15);
            }
            SetConsoleTextAttribute(kolor, 11);
            cout<<endl<<"Udalo ci sie odpowiedziec na 5 pytan!"<<endl;
            cout<<"Twoje punkty z danej dziedziny zycia to: "<<temat<<" -> ";
            SetConsoleTextAttribute(kolor, 15);
            cout<<punkty<<"/5"<<endl<<endl;
            if (punkty==5)
            {
                SetConsoleTextAttribute(kolor, 12);
                cout<<"Gratuluje jestes mistrzem w swojej dziedzinie!"<<endl<<endl;
                SetConsoleTextAttribute(kolor, 15);
            }
            system("pause");
        }
    }
    system("pause");
        return 0;
}
