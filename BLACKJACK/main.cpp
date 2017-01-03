#include "Blackjack.h"
bool VerificareCarte(unsigned int Carte)
{
    if (Pachet[Carte]==1)
        return 0;
    else
    {
        Pachet[Carte]++;
        return 1;
    }
}
unsigned int CarteAleatorie()
{
    unsigned int Carte ;
     Carte=rand()%52+1;
   while(VerificareCarte(Carte)==0)
    Carte=rand()%52+1;
    return Carte;
}
unsigned int VerificareSimbol(unsigned int Carte)
{
    if (Carte<14) return 1;
    else if (Carte>13&&Carte<27) return 2;
    else if (Carte>26&&Carte<40) return 3;
    else if (Carte>39&&Carte<53) return 4;
}
void CreareCarte()
{
    unsigned int i;
    unsigned int Numar;
    for (i=0;i<52;i++)
    {
        Numar=CarteAleatorie();
        if (VerificareSimbol(Numar)==1)
            CARTI[i].simbol='F';
        else
            if (VerificareSimbol(Numar)==2)
                CARTI[i].simbol='R';
            else
                if (VerificareSimbol(Numar)==3)
                    CARTI[i].simbol='I';
                else
                    CARTI[i].simbol='T';
        if (Numar%13==0)
            CARTI[i].numar=13;
        else
            CARTI[i].numar=Numar%13;
    }
}
int main ()
{
    return 0;
}
