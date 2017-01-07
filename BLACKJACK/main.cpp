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
    cout<<" Alegere: ";
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
bool hitstay()
{
    cout<<"hit(h) sau stay(s): ";
    char hitorstay[30];
    bool ok=1;
    cin>>hitorstay;
    while(ok)
    {
        while (strlen(hitorstay)>1)
            cin>>hitorstay;
        if(hitorstay[0]=='h'||hitorstay[0]=='s')
            ok=0;
        else
            cin>>hitorstay;
    }
    if(hitorstay[0]=='h')
        return 1;
    else
        return 0;

}
unsigned int afisarerezultat( unsigned int miza, unsigned int parcurgere, unsigned int retparcurgere, unsigned int bj, unsigned int sumacartilor, unsigned int sumajuc2)
{
    unsigned int castigator,i;
    if (bj==1)
        castigator=1;//1
    else
        if (bj==2) castigator=3;//remiza
        else
            if(bj==3) castigator=2; //2
            else
            {
                if(sumacartilor==sumajuc2) castigator=3;
                else
                    if(sumacartilor>21&&sumajuc2<22) castigator=2;
                    else
                    if  (sumacartilor<22&&sumajuc2>21) castigator=1;
                    else
                        if (sumacartilor<22&&sumajuc2<22&&sumacartilor>sumajuc2) castigator=1;
                        else
                            if (sumacartilor<22&&sumajuc2<22&&sumacartilor<sumajuc2) castigator=2;
                            else
                                if (sumacartilor>21&&sumajuc2>21) castigator=3;

            }
    cout<<"Player "<<jucator1.username<<endl;
    for(i=0;i<=parcurgere;i++)
    {
        cout<<CARTI[i].numar<<CARTI[i].simbol<<"   ";
    }
    cout<<"("<<sumacartilor<<")";
    cout<<endl<<endl<<"Player "<<jucator2.username<<endl;
    for(i;i<=retparcurgere;i++)
    {
        cout<<CARTI[i].numar<<CARTI[i].simbol<<"   ";
    }
    cout<<"("<<sumajuc2<<")"<<endl<<endl;
    if(castigator==1&&bj==1)
    {
        cout<<"Castigatorul este "<<jucator1.username<<"!"<<" BLACKJACK";
        jucator1.gold+=miza;
        jucator2.gold-=miza;
    }
    else
        if(castigator==1)
        {
            cout<<"Castigatorul este "<<jucator1.username<<"!";
            jucator1.gold+=miza;
            jucator2.gold-=miza;
        }
        else
            if (castigator==2&&bj==3)
            {
                cout<<"Castigatorul este "<<jucator2.username<<"!"<<" BLACKJACK";
                jucator1.gold-=miza;
                jucator2.gold+=miza;
            }
            else
                if(castigator==2)
                 {
                    cout<<"Castigatorul este "<<jucator2.username<<"!";
                    jucator1.gold-=miza;
                    jucator2.gold+=miza;
                }
                else
                    cout<<"REMIZA!";
    cout<<endl<<endl;
    cout<<"Player "<<jucator1.username<<" "<<jucator1.gold<<"$"<<endl;
    cout<<"Player "<<jucator2.username<<" "<<jucator2.gold<<"$";
    cout<<endl;
}
void partida(unsigned int miza)
{
    CreareCarte();
    unsigned int sumacartilor=0,nrdeasi=0,bj=0,parcurgere=0,ok,i,retparcurgere,sumajuc2=0,j,retinere;
    cout<<"####"<<jucator1.username<<"####"<<endl<<endl<<endl;
    cout<<CARTI[parcurgere].numar<<CARTI[parcurgere].simbol<<"   ";
    cout<<CARTI[parcurgere+1].numar<<CARTI[parcurgere+1].simbol<<"   (";
    if(CARTI[parcurgere].numar>10)
        sumacartilor=10;
    else
        if(CARTI[parcurgere].numar==1)
        {
            sumacartilor=11;
            nrdeasi++;
        }
        else
            sumacartilor=CARTI[parcurgere].numar;
    if(CARTI[parcurgere+1].numar>10)
        sumacartilor=sumacartilor+10;
    else
        if(CARTI[parcurgere+1].numar==1)
        {
            sumacartilor=sumacartilor+11;
            nrdeasi++;
        }
        else
            sumacartilor=sumacartilor+CARTI[parcurgere+1].numar;
        if(sumacartilor==21) bj++;
        parcurgere++;
        cout<<sumacartilor<<")"<<endl;;
        if(bj==0)
        {
            ok=hitstay();
            while(ok)
            {
                nrdeasi=0;
                sumacartilor=0;
                parcurgere++;
                for(i=0;i<=parcurgere;i++)
                {
                    cout<<CARTI[i].numar<<CARTI[i].simbol<<"   ";
                    if(CARTI[i].numar>10)
                        sumacartilor=sumacartilor+10;
                    else
                        if(CARTI[i].numar==1)
                        {
                            sumacartilor=sumacartilor+11;
                            nrdeasi++;
                        }
                            else
                                sumacartilor=sumacartilor+CARTI[i].numar;
                }
                while(sumacartilor>21&&nrdeasi>0)
                {
                   sumacartilor=sumacartilor-10;
                   nrdeasi--;
                }
                cout<<"("<<sumacartilor<<")"<<endl;
                if(sumacartilor>21)
                    ok=0;
                else
                    ok=hitstay();
            }
        }
    system("PAUSE");
    system("CLS");
    cout<<"####"<<jucator2.username<<"####"<<endl<<endl<<endl;
    nrdeasi=0;
    retparcurgere=parcurgere+2;
    retinere=parcurgere+1;
    for(j=retinere;j<=retinere+1;j++)
    {
        cout<<CARTI[j].numar<<CARTI[j].simbol<<"   ";
        if(CARTI[j].numar>10)
            sumajuc2=sumajuc2+10;
        else
            if(CARTI[j].numar==1)
            {
                sumajuc2=sumajuc2+11;
                nrdeasi++;
            }
            else
                sumajuc2=sumajuc2+CARTI[j].numar;
    }
    cout<<"("<<sumajuc2<<")"<<endl;
    if(sumajuc2==21&&bj==1) bj++;
    else
        if(sumajuc2==21) bj=3;
    if(bj==0||bj==1)
    {
        ok=hitstay();
        while(ok)
        {
            sumajuc2=0;
            retparcurgere++;
            nrdeasi=0;
            for(j=retinere;j<=retparcurgere;j++)
            {
                cout<<CARTI[j].numar<<CARTI[j].simbol<<"   ";
                if(CARTI[j].numar>10)
                    sumajuc2=sumajuc2+10;
                else
                    if(CARTI[j].numar==1)
                    {
                        sumajuc2=sumajuc2+11;
                        nrdeasi++;
                    }
                    else
                        sumajuc2=sumajuc2+CARTI[j].numar;
            }
            while(sumajuc2>21&&nrdeasi>0)
            {
                sumajuc2=sumajuc2-10;
                nrdeasi--;
            }
            cout<<"("<<sumajuc2<<")"<<endl;
            if(sumajuc2>21)
                ok=0;
            else
                ok=hitstay();
        }
    }
    cout<<endl;
    system("PAUSE");
    system("CLS");

    afisarerezultat(miza,parcurgere,retparcurgere,bj,sumacartilor,sumajuc2);
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
    cout<<"Miza("<<jucator1.gold<<") "<<jucator1.username<<": ";
    jucator1.bet=Miza();
    if(jucator1.bet>jucator1.gold)
        jucator1.bet=jucator1.gold;
    cout<<"Miza("<<jucator2.gold<<") "<<jucator2.username<<": ";
    jucator2.bet=Miza();
    if(jucator2.bet>jucator2.gold)
        jucator2.bet=jucator2.gold;
    if(jucator1.bet<jucator2.bet)
        miza=jucator1.bet;
    else
         miza=jucator2.bet;
    cout<<"Miza jocului este->"<<miza<<endl;
    system("PAUSE");
    system("CLS");
   partida(miza);

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
