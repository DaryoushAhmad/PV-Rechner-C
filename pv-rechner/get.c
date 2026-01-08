
#include "get.h"


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// Usereingabe + (Winkelbestrahlung)
void UserEingabe(Ort Stadt[12], winkel Monate[12])
{
    int UserWinkel = 0;
    double kWp = 0;

    printf("Bitte geben sie den Winkel ein. \n");
    printf("(0)    (30)    (45)    (60) \n");


while (scanf("%d", &UserWinkel) != 1 || !Ueberpruefung(UserWinkel))
    {
        printf("Bitte einen Winkel eingeben.\n");
        while (getchar() != '\n') {}
    }

#ifndef AUFGABE_1
printf("Bitte geben sie die Leistung ihrer PV-Anlage in kWp an (1-30)\n");
    //while (getchar() != '\n') {}
    while (scanf("%lf", &kWp) != 1 || !UeberpruefungkWp(kWp))
    {
        printf("Bitte eine Zahl von 1 - 30 eingeben.\n");
        while (getchar() != '\n') {}
    }
#endif 
    //system("cls");
    printf("Hier sind die Bestrahlungsstaerken in deiner Stadt!\n");
    printf("\n");
    WinkelBestrahlung(Stadt, Monate, UserWinkel, kWp);

}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


int Ueberpruefung(int Userwinkel)
{
    return (Userwinkel == 30 || Userwinkel == 45 || Userwinkel == 60 || Userwinkel == 0);
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


int UeberpruefungkWp(double kWp)
{
    return (kWp > 0 && kWp < 31);

}



//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int UeberpruefungStadt(int Stadt)
{
    if (Stadt > 0 && Stadt < 6)
        return 1;

    return 0;
}



//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//Berechnung der Winkel Korrektur 
void WinkelBestrahlung(Ort Stadt[12], winkel Monate[12], int UserWinkel, double kWp)
{
   
    


    for (int i = 0; i < 12; i++)
    {

        Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * strahlungNachWinkel(Monate, i, UserWinkel);

#ifdef AUFGABE_1

        printf("Bestrahlung fuer %s mit winkel %d Grad: %.2f\n", Stadt[i].Monat, UserWinkel, Stadt[i].Winkel);
        Summe = Summe + Stadt[i].Winkel;
#else

        Stadt[i].Leistung = Stadt[i].Winkel * kWp;  
#endif
    }


    return 0;
}

double strahlungNachWinkel(winkel* w, int i, int userwinkel) {
    switch (userwinkel) {
        case 0: return 1;
        case 30: return w[i].winkel30; 
        case 45: return w[i].winkel45; 
        case 60: return w[i].winkel60; 
    }
}


// Berechnung der Monatlichen Bestrahlungsstärke 
void BerrechnungBestrahlungHamburg(BestrahlungRohDaten KorrekturMonate[12], Ort Stadt[12])
{
    for (int i = 0; i < 12; i++)
    {
        Stadt[i].MonatsBestrahlung = KorrekturMonate[i].Bestrahlung * KorrekturMonate[i].Tage;
    }

}

#ifndef AUFGABE_1


void printFunktion(Ort Stadt[12], FILE* f)
{
    double Summe = 0;

for (int i = 0; i < 12; i++)
{
    fprintf(f ,"%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
    printf("%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
    Summe = Summe + Stadt[i].Leistung;
}
    printf("\n");
    printf("Die Jahresleistung deiner Anlage beträgt: %.2f", Summe);
    fprintf(f, "Die Jahresleistung deiner Anlage beträgt: %.2f", Summe);
    printf("\n");
#endif // !1

}