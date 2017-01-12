#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<string>
#define MAX_CARTE 53
using namespace std;

unsigned int Pachet[MAX_CARTE];
unsigned int alegere;
struct Carte
{
     unsigned int numar ;
     char simbol;
};
Carte CARTI[100];
struct Player
{
    char username[100];
    int gold=1000;
    unsigned int bet;
};
Player jucator1;
Player jucator2;
bool VerificareCarte(unsigned int Carte);
unsigned int CarteAleatorie();
unsigned int VerificareSimbol(unsigned int Carte);
void CreareCarte();
unsigned int menu ();
void ReguliJoc();
unsigned int playerVSplayer();
unsigned int Miza();
void partida(unsigned int miza);
bool hitstay();
void afisarerezultat( unsigned int miza, unsigned int parcurgere, unsigned int retparcurgere, unsigned int bj, unsigned int sumacartilor, unsigned int sumajuc2);
unsigned int menu2(bool ok);
unsigned int playerVScomputer ();
void partidavscomputer (unsigned int miza);
void rezultat(unsigned int miza, unsigned int parcurgere,unsigned int retparcurgere,unsigned int bj, unsigned int sumacartilor,unsigned int sumacomp);

