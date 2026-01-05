#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#define AUFGABE_1

#pragma once

typedef struct {

    double winkel30; //KorrekturFaktor für Winkel 30 Grad
    double winkel45; //KorrekturFaktor für Winkel 45 Grad
    double winkel60; //KorrekturFaktor für Winkel 60 Grad

}winkel;


typedef struct
{
    char Monat[4];  //Name des Monats
    double MonatsBestrahlung;   //Monatliche Bestrahlung
    double Winkel;  //Korrigierte Bestrahlung mit WinkelFaktor
    double Leistung;    //Die Leistung der Anlage

} Ort;

typedef struct
{
    char Monat[10];
    double Bestrahlung;
    int Tage;
    
} BestrahlungRohDaten;
void BerrechnungBestrahlungHamburg(BestrahlungRohDaten KorrekturMonate[12], Ort Stadt[12]);
double WinkelBestrahlung(Ort Hamburg[12], winkel Monate[12], int UserWinkel);
int Überprüfung(int Userwinkel);
double ErtragsRechner(Ort Stadt[12], winkel Monate[12], int UserWinkel, double kWp, FILE* f);
void UserEingabe(Ort Stadt[12], winkel Monate[12]);
void Leistungsrechner(Ort Stadt[12], winkel Monate[12], FILE* f);
int ÜberprüfungkWp(double kWp);
int ÜberprüfungStadt(int Stadt);
