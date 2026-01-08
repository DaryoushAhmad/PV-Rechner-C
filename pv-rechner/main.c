/*
Daryoush Ahmad und Henri Schleiermacher
PV-Rechner
06.01.2026
in diesem Programm werden zwei Projekte umgesetzt
1.Berechnung der Bestrahlungsstärken von verschiedenen Standorten
2.Berechnung des ertrages einer PV-Anlage.
*/
#include "get.h"


int main(void)
{
    //Öffnen der Ausgabe-Datei
    FILE* pAusgabe = fopen("Ausgabe.txt", "w");

    //Überprüfung ob Datei geöffnet worden konnte
    if (pAusgabe == NULL)
    {
        printf("Datei konnte nicht geöffnet werden");
        return 1;
    }

    //Initialisierung der Daten
    BestrahlungRohDaten TageBestrahlung[12] = { { "Jan", 0.52, 31,},{ "Feb", 1.13, 28,},{ "Mrz", 2.23, 31,},{ "Apr", 3.55, 30,} ,
                                                { "Mai", 4.67, 31,},{ "Jun", 5.44, 30,},{ "Jul", 4.82, 31,} ,{ "Aug", 4.34, 31,},
                                                { "Sep", 2.79, 30,},{ "Okt", 1.49, 31,},{ "Nov", 0.67, 30,},{ "Dez", 0.40, 31,} };

    int StadtAuswahl = 2;
    Ort Hamburg[12] = { { "Jan",0, 0,0},{ "Feb",0, 0,0},{ "Mrz",0, 0,0},{ "Apr",0, 0,0},
                        { "Mai",0, 0,0},{ "Jun",0, 0,0},{ "Jul",0, 0,0},{ "Aug",0, 0,0},
                        { "Sep",0, 0,0},{ "Okt",0, 0,0},{ "Nov",0, 0,0},{ "Dez",0, 0,0} };



    Ort Berlin[12] = { { "Jan", 19, 0,0 }, { "Feb", 33, 0,0 }, { "Mrz", 75, 0,0 }, { "Apr", 128, 0,0 },
                       { "Mai",160, 0,0 }, { "Jun",166, 0,0 }, { "Jul",158, 0,0 }, { "Aug", 134, 0,0 },
                       { "Sep", 94, 0,0 }, { "Okt", 51, 0,0 }, { "Nov", 26, 0,0 }, { "Dez",  15, 0,0 }
    };

    Ort Kassel[12] = { { "Jan", 20, 0,0 }, { "Feb", 34, 0,0 }, { "Mrz", 77, 0,0 }, { "Apr", 123, 0,0 },
                       { "Mai",150, 0,0 }, { "Jun",162, 0,0 }, { "Jul",154, 0,0 }, { "Aug", 132, 0,0 },
                       { "Sep", 90, 0,0 }, { "Okt", 52, 0,0 }, { "Nov", 25, 0,0 }, { "Dez",  16, 0,0 }
    };


    Ort Stuttgart[12] = { { "Jan", 29, 0,0 }, { "Feb", 45, 0,0 }, { "Mrz", 85, 0,0 }, { "Apr", 130, 0,0 },
                          { "Mai",153, 0,0 }, { "Jun",174, 0,0 }, { "Jul",164, 0,0 }, { "Aug", 140, 0,0 },
                          { "Sep", 99, 0,0 }, { "Okt", 62, 0,0 }, { "Nov", 36, 0,0 }, { "Dez",  24, 0,0 }
    };

    Ort Freiburg[12] = { { "Jan", 29, 0,0 }, { "Feb", 45, 0,0 }, { "Mrz", 84, 0,0 }, { "Apr", 129, 0,0 },
                         { "Mai",153, 0,0 }, { "Jun",172, 0,0 }, { "Jul",166, 0,0 }, { "Aug", 141, 0,0 },
                         { "Sep",104, 0,0 }, { "Okt", 63, 0,0 }, { "Nov", 38, 0,0 }, { "Dez",  24, 0,0 }
    };

    Ort* staedte[5] = { &Hamburg, &Berlin, &Kassel, &Stuttgart, &Freiburg };

    winkel Monate[12] = { {1.44, 1.57, 1.63  },{1.40, 1.50, 1.54  },{1.17, 1.19, 1.15  },{1.08, 1.05, 0.98  },
                          {1.00, 0.94, 0.85  },{0.96, 0.90, 0.81  },{0.97, 0.91, 0.83  },{1.03, 1.00, 0.92  },
                          {1.17, 1.18, 1.14  },{1.30, 1.37, 1.38  },{1.47, 1.61, 1.68  },{1.42, 1.55, 1.61  } };
    //Umrechnung der Rohdaten (Tägliche Bestrahlungsstärke) in Monatliche
    BerrechnungBestrahlungHamburg(TageBestrahlung, Hamburg);


    //Aufgabe 2-3
//#ifdef AUFGABE_1

    printf("Bitte Waehle deine Stadt aus\n");
    printf("Hamburg(1)  Berlin(2)   Kassel(3)   Stuttgart(4)    Freiburg(5)\n");
    while (scanf("%d", &StadtAuswahl) != 1 || !UeberpruefungStadt(StadtAuswahl))
    {
        printf("Fehlerhafte Eingabe, bitte eine Zahl eingeben!\n");
        while (getchar() != '\n') {}
    }
    StadtAuswahl = StadtAuswahl - 1;

    UserEingabe(staedte[StadtAuswahl], Monate);


    printFunktion(staedte[StadtAuswahl], pAusgabe);
    
    fclose(pAusgabe);

    return 0;
}