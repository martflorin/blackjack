#include<iostream>
#include<stdlib.h>
#define MAX_CARTE 53
using namespace std;
unsigned int Pachet[MAX_CARTE];
struct Carte
{
     unsigned int numar ;
     char simbol;
};
Carte CARTI[100];
bool VerificareCarte(unsigned int Carte);
unsigned int CarteAleatorie();
unsigned int VerificareSimbol(unsigned int Carte);
void CreareCarte();
