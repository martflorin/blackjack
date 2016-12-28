#include "Blackjack.h"
bool CheckCard(unsigned int Card)
{
    if (Deck[Card]==1)
        return 0;
    else
    {
        Deck[Card]++;
        return 1;
    }
}
unsigned int RandomCard()
{
    unsigned int Card ;
     Card=rand()%52+1;
   while(CheckCard(Card)==0)
    Card=rand()%52+1;
    return Card;
}
unsigned int VerificareSimbol(unsigned int Card)
{
    if (Card<14) return 1;
    else if (Card>13&&Card<27) return 2;
    else if (Card>26&&Card<40) return 3;
    else if (Card>39&&Card<53) return 4;
}
int main ()
{
    return 0;
}
