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

    for (int i=0;i<=5;i++)
    {
        cout<<"#";
        Sleep(500);
    }
    system("CLS");
    return alegere;
}
void ReguliJoc()
{
    cout<<"blaaaaaablalbaalbalbalbalbalalbblal"<<endl;
    cout<<"Regulile jocului sunt blalabalbalbalbasflasflssl"<<endl;
    cout<<"dfgdfgdfbdfbdfgdbdfhdhddhdhfhtftft";cout<<endl<<endl;
    system("PAUSE");
    system("CLS");
}
/*char VerificareUsername(char nume[])
{
     unsigned int parcurgere,i;
    for(parcurgere=0;parcurgere<strlen(nume);parcurgere++)
        if(nume[parcurgere]==' ')
        {
            i=parcurgere;
            while(i<strlen(nume)-1)
            {
                nume[i]=nume[i+1];
                i++;
            }
            parcurgere--;
        }
}
*/
unsigned int Miza()
{
    int i=0;
    bool ok=1;
    char miza[100];
    unsigned int bet=0;
    cin>>miza;
    while (ok)
    {
        if(i==strlen(miza)-1&&miza[i]>47&&miza[i]<58)
            ok=0;
        if (i<strlen(miza))
            if(miza[i]<48||miza[i]>57)
        {
            cin>>miza;
            i=0;
        }
        else i++;
    }
    for(i=0;i<strlen(miza);i++)
        bet=bet*10+miza[i]-'0';
    return bet;

}
unsigned int playerVSplayer()
{
    unsigned int miza;
    cout<<"Username jucator 1(fara spatii): ";
    cin>>jucator1.username;
    //jucator1.username=VerificareUsername(jucator1.username);
    cout<<endl;
    cout<<"Username jucator 2(fara spatii): ";
    cin>>jucator2.username;
    cout<<endl;
    cout<<"Miza "<<jucator1.username<<": ";
    jucator1.bet=Miza();
    if(jucator1.bet>jucator1.gold)
        jucator1.bet=jucator1.gold;
    cout<<"Miza "<<jucator2.username<<": ";
    jucator2.bet=Miza();
    if(jucator2.bet>jucator2.gold)
        jucator2.bet=jucator2.gold;
    if(jucator1.bet<jucator2.bet)
        miza=jucator1.bet;
    else
         miza=jucator2.bet;
    system("PAUSE");
    system("CLS");
    return 0;

}
int main ()
{
  unsigned int alegere;
  alegere=menu();
  while(alegere!=4)
  {
    switch(alegere)
    {
        case 1 : {playerVSplayer(); alegere=menu();}
        break;
        case 2: {cout<<2; return 0;}
        break;
        case 3: { ReguliJoc(); alegere=menu();}
        break;
    }
  }
return 0;
}
