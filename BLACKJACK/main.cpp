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
    if (Carte<14)
        return 1;
    else
        if (Carte>13&&Carte<27)
            return 2;
        else
            if (Carte>26&&Carte<40)
                return 3;
            else
                if (Carte>39&&Carte<53)
                    return 4;
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
    char depasire[1000];
    system("color 02");
    cout<<"#######################"<<endl;
    cout<<"#######Blackjack#######"<<endl;
    cout<<"#######################"<<endl<<endl;
    cout<<" 1. Player vs Player"<<endl;
    cout<<" 2. Player vs Computer"<<endl;
    cout<<" 3. Regulile jocului"<<endl;
    cout<<" 4. Iesire din joc "<<endl<<endl;
    cout<<" Alegere: ";
    gets(depasire);
    if(strlen(depasire)>1)
        alegere=0;
    else
        if(depasire[0]-'0'>=1&&depasire[0]-'0'<=4)
            alegere=depasire[0]-'0';
        else
            alegere=0;
    while (alegere!=1&&alegere!=2&&alegere!=3&&alegere!=4)
    {
        gets(depasire);
        if(strlen(depasire)>1)
            alegere=0;
        else
            if(depasire[0]-'0'>=1&&depasire[0]-'0'<=4)
                alegere=depasire[0]-'0';
            else
                alegere=0;
    }
    system("CLS");
    return alegere;
}
void ReguliJoc()
{
    cout<<"Blackjack este un joc de carti care se joaca cu un pachet standard de 52 de carti. "<<endl;
    cout<<"Culoarea cartilor nu este importanta in acest joc"<<endl;
    cout<<"Cartile intre 2 si 10 au valoarea scrise pe ele, figurile au valoarea 10, asul poate fi 1 sau 11 dupa preferinta jucatorului. "<<endl;
    cout<<"Castigatorul acesui joc este acel jucator care se apropie cat mai mult de 21 de puncte ,dar fara sa depaseasca 21 de puncte"<<endl;
    cout<<"Cel care depaseste 21 de puncte nu mai are sanse de castig"<<endl<<endl;
    cout<<"Player VS Player"<<endl;
    cout<<"Jucatorii primesc cate 2 carti , iar acestia hotarasc daca mai doresc carti"<<endl;
    cout<<"Hit-mai vreau o carte"<<endl;
    cout<<"Stay-oprire"<<endl;
    cout<<"Se poate folosi dupa ce jucatorul isi vede primele 2 carti si acesta are suma cartilor cel putin 11."<<endl;
    cout<<"Jucatorii pot paria o miza"<<endl;
    cout<<"Daca un jucator ramane fara $, jocul incepe iarasi cu 1000$ pentru ambii jucatori "<<endl<<endl;
    cout<<"Player VS Computer"<<endl;
    cout<<"In cazul in care obtine blackjack(cea mai puternica mana a acestui joc ),acesta primeste 1,5*miza"<<endl;
    cout<<"Soft 17-Calculatorul trage inca o carte atata timp cat suma cartilor este mai mica decat 17."<<endl;
    cout<<"Daca ajunge la suma 17 , acesta nu mai are voie sa primeasca carti"<<endl<<endl;
    cout<<"Distractie placuta si mult noroc !!"<<endl;
    system("PAUSE");
    system("CLS");
}
unsigned int Miza()
{
    unsigned int i=0;
    bool ok=1;
    char miza[100];
    unsigned int bet=0;
    gets(miza);
    while (ok)
    {
        if(strlen(miza)==0)
        {
            gets(miza);
            i=0;
        }
        else
            if(i==strlen(miza)-1&&miza[i]>47&&miza[i]<58)
                ok=0;
            else
                if (i<strlen(miza))
                    if(miza[i]<48||miza[i]>57)
                    {
                        gets(miza);
                        i=0;
                    }
                    else
                        i++;
    }
    for(i=0;i<strlen(miza);i++)
        bet=bet*10+miza[i]-'0';
    return bet;

}
bool hitstay()
{
    char hitorstay[30];
    bool ok=1;
    cout<<"hit(h)/stay(s): ";
    gets(hitorstay);
    while(ok)
    {
        while (strlen(hitorstay)>1)
            gets(hitorstay);
        if(hitorstay[0]=='h'||hitorstay[0]=='s')
            ok=0;
        else
           gets(hitorstay);
    }
    if(hitorstay[0]=='h')
        return 1;
    else
        return 0;

}
void afisarerezultat( unsigned int miza, unsigned int parcurgere, unsigned int retparcurgere, unsigned int bj, unsigned int sumacartilor, unsigned int sumajuc2)
{
    unsigned int castigator,i;
    if (bj==1)
        castigator=1;
    else
        if (bj==2)
            castigator=3;
        else
            if(bj==3)
                castigator=2;
            else
            {
                if(sumacartilor==sumajuc2)
                    castigator=3;
                else
                    if(sumacartilor>21&&sumajuc2<22)
                        castigator=2;
                    else
                        if(sumacartilor<22&&sumajuc2>21)
                            castigator=1;
                        else
                            if (sumacartilor<22&&sumajuc2<22&&sumacartilor>sumajuc2)
                                castigator=1;
                            else
                                if (sumacartilor<22&&sumajuc2<22&&sumacartilor<sumajuc2)
                                    castigator=2;
                                else
                                    if (sumacartilor>21&&sumajuc2>21)
                                        castigator=3;

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
        jucator1.score++;
    }
    else
        if(castigator==1)
        {
            cout<<"Castigatorul este "<<jucator1.username<<"!";
            jucator1.gold+=miza;
            jucator2.gold-=miza;
            jucator1.score++;
        }
        else
            if (castigator==2&&bj==3)
            {
                cout<<"Castigatorul este "<<jucator2.username<<"!"<<" BLACKJACK";
                jucator1.gold-=miza;
                jucator2.gold+=miza;
                jucator2.score++;
            }
            else
                if(castigator==2)
                 {
                    cout<<"Castigatorul este "<<jucator2.username<<"!";
                    jucator1.gold-=miza;
                    jucator2.gold+=miza;
                    jucator2.score++;
                }
                else
                    cout<<"REMIZA!";
    cout<<endl<<endl;
    cout<<"###"<<jucator1.username<<"###"<<endl<<jucator1.gold<<"$"<<endl<<"Score "<<jucator1.score<<endl<<endl;
    cout<<"###"<<jucator2.username<<"###"<<endl<<jucator2.gold<<"$"<<endl<<"Score "<<jucator2.score<<endl;
    cout<<endl;
    for(int i=0;i<=52;i++)
        Pachet[i]=0;
}
unsigned int menu2( bool ok)
{
    int alegere2;
    unsigned int miza;
    char depasire[1000];
    system("color 02");
    cout<<"1. Continuare"<<endl;
    cout<<"2. Meniul principal"<<endl;
    cout<<"3. Iesire"<<endl;
    gets(depasire);
    if(strlen(depasire)>1)
        alegere2=0;
    else
        if(depasire[0]-'0'>=1&&depasire[0]-'0'<=3)
            alegere2=depasire[0]-'0';
        else
            alegere2=0;
    while (alegere2!=1&&alegere2!=2&&alegere2!=3)
    {
        gets(depasire);
        if(strlen(depasire)>1)
            alegere2=0;
        else
            if(depasire[0]-'0'>=1&&depasire[0]-'0'<=4)
                alegere2=depasire[0]-'0';
            else
                alegere2=0;
    }
    system("CLS");
    if(alegere2==1)
    {
        if(ok)
       {
            if(jucator1.gold==0||jucator2.gold==0)
                jucator1.gold=jucator2.gold=1000;
       }
       else
            if(jucator1.gold==0)
            {
                jucator1.gold=1000;
                jucator2.gold=1000;
            }
        cout<<"Miza("<<jucator1.gold<<") "<<jucator1.username<<": ";
        jucator1.bet=Miza();
        if(jucator1.bet>jucator1.gold)
            jucator1.bet=jucator1.gold;
        if (ok)
        {
            cout<<"Miza("<<jucator2.gold<<") "<<jucator2.username<<": ";
            jucator2.bet=Miza();
            if(jucator2.bet>jucator2.gold)
                jucator2.bet=jucator2.gold;
            if(jucator1.bet<jucator2.bet)
                miza=jucator1.bet;
            else
                miza=jucator2.bet;
        }
        else
            miza=jucator1.bet;
        cout<<"Miza jocului este->"<<miza<<endl;
        system("PAUSE");
        system("CLS");
        if(ok)
            partida(miza);
        else
            partidavscomputer(miza);
    }
    else
        if(alegere2==2)
        {
            jucator1.gold=jucator2.gold=1000;
            jucator1.score=jucator2.score=0;
            alegere=menu();
        }
        else
            if (alegere2==3)
            {
                alegere=4;
                return alegere;
            }
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
    if(sumacartilor==21)
        bj++;
    parcurgere++;
    if(sumacartilor>21)
        sumacartilor=sumacartilor-10;
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
    if(sumajuc2>21)
        sumajuc2=sumajuc2-10;
    cout<<"("<<sumajuc2<<")"<<endl;
    if(sumajuc2==21&&bj==1)
        bj++;
    else
        if(sumajuc2==21)
            bj=3;
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
    menu2(1);
}
unsigned int playerVSplayer()
{
    unsigned int miza;
    cout<<"Username jucator 1: ";
    gets(jucator1.username);
    cout<<endl;
    cout<<"Username jucator 2: ";
    gets(jucator2.username);
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
    return alegere;

}
void rezultat(unsigned int miza, unsigned int parcurgere,unsigned int retparcurgere,unsigned int bj, unsigned int sumacartilor,unsigned int sumacomp)
{
    unsigned int castigator,i;
    if (bj==1)
        castigator=1;
    else
        if (bj==2)
            castigator=3;
        else
            if(bj==3)
                castigator=2;
            else
            {
                if(sumacartilor==sumacomp)
                    castigator=3;
                else
                    if(sumacartilor>21&&sumacomp<22)
                        castigator=2;
                    else
                        if(sumacartilor<22&&sumacomp>21)
                            castigator=1;
                        else
                            if (sumacartilor<22&&sumacomp<22&&sumacartilor>sumacomp)
                                castigator=1;
                            else
                                if (sumacartilor<22&&sumacomp<22&&sumacartilor<sumacomp)
                                    castigator=2;
                                else
                                    if (sumacartilor>21&&sumacomp>21)
                                        castigator=3;

            }
    cout<<"Player "<<jucator1.username<<endl;
    for(i=0;i<=parcurgere;i++)
    {
        cout<<CARTI[i].numar<<CARTI[i].simbol<<"   ";
    }
    cout<<"("<<sumacartilor<<")";
    cout<<endl<<endl<<"Computer "<<endl;
    for(i;i<=retparcurgere;i++)
    {
        cout<<CARTI[i].numar<<CARTI[i].simbol<<"   ";
    }
    cout<<"("<<sumacomp<<")"<<endl<<endl;
    if(castigator==1&&bj==1)
    {
        cout<<"Castigatorul este "<<jucator1.username<<"!"<<" BLACKJACK";
        jucator1.gold+=miza*1.5;
    }
    else
        if(castigator==1)
        {
            cout<<"Castigatorul este "<<jucator1.username<<"!";
            jucator1.gold+=miza;
            jucator1.score++;
        }
        else
            if (castigator==2&&bj==3)
            {
                cout<<"Castigatorul este Computer!"<<" BLACKJACK";
                jucator1.gold-=miza;
            }
            else
                if(castigator==2)
                 {
                    cout<<"Castigatorul este Computer !";
                    jucator1.gold-=miza;
                }
                else
                    cout<<"REMIZA!";
    cout<<endl<<endl;
    cout<<"###"<<jucator1.username<<"###"<<endl<<jucator1.gold<<"$"<<endl<<"Score "<<jucator1.score<<endl<<endl;
    for(int i=0;i<=52;i++)
        Pachet[i]=0;
}
 void partidavscomputer(unsigned int miza)
{
    CreareCarte();
    unsigned int sumacartilor=0,nrdeasi=0,bj=0,parcurgere=0,ok,i,retparcurgere,sumacomp=0,j,retinere,dublare=5,hit=1;
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
    if(sumacartilor==21)
        bj++;
    parcurgere++;
    if(sumacartilor>21)
        sumacartilor=sumacartilor-10;
    cout<<sumacartilor<<")"<<endl;
    if(sumacartilor>10&&sumacartilor<21)
    {
        char hitorstay[30];
        cout<<"hit(h)/stay(s)/double(d): ";
        gets(hitorstay);
        while(hit)
        {
            while (strlen(hitorstay)>1)
                gets(hitorstay);
            if(hitorstay[0]=='h'||hitorstay[0]=='s'||hitorstay[0]=='d')
                hit=0;
            else
                gets(hitorstay);
        }
        if(hitorstay[0]=='h')
            dublare=1;
        else
            if(hitorstay[0]=='d')
                dublare=2;
            else
                dublare=0;
        if(dublare==2)
        {
            if(2*miza<jucator1.gold)
                miza=miza*2;
                else
                    miza=jucator1.gold;
                cout<<"Miza jocului este "<<miza<<endl;
            nrdeasi=0;
            sumacartilor=0;
            parcurgere++;
            for(i=0;i<=2;i++)
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
        }
    }
    if(bj==0&&dublare!=2)
    {
        if(dublare==0) ok=0;
        else if (dublare==1) ok=1;
        else if (dublare==5)
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
    nrdeasi=0;
    retparcurgere=parcurgere+2;
    retinere=parcurgere+1;
    for(j=retinere;j<=retinere+1;j++)
    {
         if(CARTI[j].numar>10)
            sumacomp=sumacomp+10;
        else
            if(CARTI[j].numar==1)
            {
                sumacomp=sumacomp+11;
                nrdeasi++;
            }
            else
                sumacomp=sumacomp+CARTI[j].numar;
    }
    if(sumacomp==21&&bj==1)
        bj++;
    else
        if(sumacomp==21)
            bj=3;
         if(sumacomp>21)
            sumacomp=sumacomp-10;
    if(bj==0||bj==1)
    {
        ok=1;
        while(sumacomp<17&&ok==1)
        {
            sumacomp=0;
            retparcurgere++;
            nrdeasi=0;
            for(j=retinere;j<=retparcurgere;j++)
            {
                if(CARTI[j].numar>10)
                    sumacomp=sumacomp+10;
                else
                    if(CARTI[j].numar==1)
                    {
                        sumacomp=sumacomp+11;
                        nrdeasi++;
                    }
                    else
                        sumacomp=sumacomp+CARTI[j].numar;
            }
            while(sumacomp>21&&nrdeasi>0)
            {
                sumacomp=sumacomp-10;
                nrdeasi--;
            }
            if(sumacomp>16)
                ok=0;
        }
    }
    rezultat(miza,parcurgere,retparcurgere,bj,sumacartilor,sumacomp);
    menu2(0);
}
unsigned int playerVScomputer()
{

    unsigned int miza;
    jucator2.gold=1000;
    cout<<"Username jucator: ";
    gets(jucator1.username);
    cout<<endl;
    cout<<"Miza("<<jucator1.gold<<") "<<jucator1.username<<": ";
    jucator1.bet=Miza();
    if(jucator1.bet>jucator1.gold)
        jucator1.bet=jucator1.gold;
    miza=jucator1.bet;
    cout<<"Miza jocului este->"<<miza<<endl;
    system("PAUSE");
    system("CLS");
    partidavscomputer(miza);
    return alegere;
}
int main ()
{

    alegere=menu();
    while(alegere!=4)
    {
        switch(alegere)
        {
            case 1 : playerVSplayer();
            break;
            case 2: playerVScomputer();
            break;
            case 3: { ReguliJoc(); alegere=menu();}
            break;
        }
    }
    return 0;
}
