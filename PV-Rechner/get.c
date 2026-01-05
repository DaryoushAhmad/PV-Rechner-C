
#include "get.h"





void Leistungsrechner(Ort Stadt[12], winkel Monate[12], FILE *f)
{
    int UserWinkel = 0;
    double kWp = 0;
    
    printf("Bitte geben sie den Winkel ein. \n");
    printf("(0)    (30)    (45)    (60) \n");


    while (scanf("%d", &UserWinkel) != 1 || !Überprüfung(UserWinkel))
    {
        printf("Bitte einen Winkel eingeben.\n");
        while (getchar() != '\n') {}
    }


    printf("Bitte geben sie die Leistung ihrer PV-Anlage in kWp an (1-30)\n");

    while (getchar() != '\n') {}
    while (scanf("%lf", &kWp) != 1 || !ÜberprüfungkWp(kWp))
    {
        printf("Bitte eine Zahl von 1 - 30 eingeben.\n");
        while (getchar() != '\n') {}
    }

    
        printf("\n");
        fprintf(f, "Der Jaehrliche Ertrag ihrer Anlage betraegt: %.2f\n", ErtragsRechner(Stadt, Monate, UserWinkel, kWp, f));
    
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

double ErtragsRechner(Ort Stadt[12], winkel Monate[12], int UserWinkel, double kWp, FILE *f)
{
    double GesamtErtrag = 0;

    system("cls");
    fprintf(f, "Diese ist der Ertrag ihrer PV-Anlage [kWh]\n");


    if (UserWinkel == 0)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung ;
            Stadt[i].Leistung = kWp * Stadt[i].Winkel ;
            fprintf(f, "%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
            GesamtErtrag = GesamtErtrag + Stadt[i].Leistung;

        }
    }
    else if (UserWinkel == 30)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel30;
            Stadt[i].Leistung = kWp * Stadt[i].Winkel ;
            fprintf(f, "%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
            GesamtErtrag = GesamtErtrag + Stadt[i].Leistung;

        }
    }
    else if (UserWinkel == 45)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel45;
            Stadt[i].Leistung = kWp * Stadt[i].Winkel ;
            fprintf(f, "%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
            GesamtErtrag = GesamtErtrag + Stadt[i].Leistung;

        }
    }
    else {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel60;
            Stadt[i].Leistung = kWp * Stadt[i].Winkel ;
            fprintf(f, "%s: %.2f\n", Stadt[i].Monat, Stadt[i].Leistung);
            GesamtErtrag = GesamtErtrag + Stadt[i].Leistung;
        }
    }

    return GesamtErtrag;

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


void UserEingabe(Ort Stadt[12], winkel Monate[12])
{
    int UserWinkel = 0;


    printf("Bitte geben sie den Winkel ein. \n");
    printf("(0)    (30)    (45)    (60) \n");


        while (scanf("%d", &UserWinkel) != 1 || !Überprüfung(UserWinkel))
        {
            printf("Bitte einen Winkel eingeben.\n");
            while (getchar() != '\n') {}
        }


    system("cls");


    printf("Hier sind die Bestrahlungsstärken in deiner Stadt!\n");
    printf("\n");

       
    printf("%.2f", WinkelBestrahlung(Stadt, Monate, UserWinkel));
       
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


int Überprüfung(int Userwinkel)
{
    if (Userwinkel == 30 || Userwinkel == 45 || Userwinkel == 60 || Userwinkel == 0)
        return 1;

    return 0;

}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


int ÜberprüfungkWp(double kWp)
{
    if (kWp > 0 && kWp < 31)
        return 1;

    return 0;

}



//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int ÜberprüfungStadt(int Stadt)
{
    if(Stadt>0 && Stadt < 6)
        return 1;

    return 0;
}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



double WinkelBestrahlung(Ort Stadt[12], winkel Monate[12], int UserWinkel)
{
    double Summe = 0;

    if (UserWinkel == 0)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung ;
            printf("Bestrahlung fuer %s mit winkel 0 Grad: %.2f\n", Stadt[i].Monat, Stadt[i].Winkel);
            Summe = Summe + Stadt[i].Winkel;
        }
    }
    else if (UserWinkel == 30)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel30;
            printf("Bestrahlung fuer %s mit winkel 30 Grad: %.2f\n", Stadt[i].Monat, Stadt[i].Winkel);
            Summe = Summe + Stadt[i].Winkel;
        }
    }
    else if (UserWinkel == 45)
    {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel45;
            printf("Bestrahlung fuer %s mit winkel 45 Grad: %.2f\n", Stadt[i].Monat, Stadt[i].Winkel);
            Summe = Summe + Stadt[i].Winkel;
        }
    }
    else {
        for (int i = 0; i < 12; i++)
        {
            Stadt[i].Winkel = Stadt[i].MonatsBestrahlung * Monate[i].winkel60;
            printf("Bestrahlung fuer %s mit winkel 60 Grad: %.2f\n", Stadt[i].Monat, Stadt[i].Winkel);
            Summe = Summe + Stadt[i].Winkel;
        }
    }
    return Summe;
}


void BerrechnungBestrahlungHamburg(BestrahlungRohDaten KorrekturMonate[12], Ort Stadt[12])
{
    for (int i = 0; i < 12; i++)
    {
        Stadt[i].MonatsBestrahlung = KorrekturMonate[i].Bestrahlung * KorrekturMonate[i].Tage;
    }


    /*
    for (int i = 0; i < 12; i++)
    {
        printf("%s: %.2f %d %.3f \n", KorrekturMonate[i].Monat, KorrekturMonate[i].Bestrahlung, KorrekturMonate[i].Tage, KorrekturMonate[i].MonatsBestrahlung);
    }
    */
    


}