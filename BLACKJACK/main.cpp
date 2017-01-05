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
     srand(time(NULL));
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
unsigned int menu ()
{
    int alegere;
    char depasire[100];
     system("color 02");
    cout<<"#######################"<<endl;
    cout<<"#######Blackjack#######"<<endl;
    cout<<"#######################"<<endl<<endl;
    cout<<" 1. Player vs Player"<<endl;
    cout<<" 2. Player vs Computer"<<endl;
    cout<<" 3. Regulile jocului"<<endl;
    cout<<" 4. Iesire din joc "<<endl<<endl;
    cout<<" Alegere "<<endl;
    cin>>depasire;
    if(strlen(depasire)>1)
        alegere=0;
    else
        if(depasire[0]-'0'>=1&&depasire[0]-'0'<=4)
            alegere=depasire[0]-'0';
        else alegere=0;
    while (alegere!=1&&alegere!=2&&alegere!=3&&alegere!=4)
    {
        cin>>depasire;
         if(strlen(depasire)>1)
        alegere=0;
    else
        if(depasire[0]-'0'>=1&&depasire[0]-'0'<=4)
            alegere=depasire[0]-'0';
        else alegere=0;
    }

    for (int i=0;i<=7;i++)
    {
        cout<<"*";
        Sleep(500);
    }
    system("CLS");
    return alegere;
}
int main ()
{
  unsigned int alegere;
  alegere=menu();
  while(alegere!=4)
  {
    switch(alegere)
    {
        case 1 :{ cout<<1; return 0;}
        break;
        case 2: {cout<<2; return 0;}
        break;
        case 3: {cout<<3; return 0;}
        break;
    }
  }
return 0;
}
