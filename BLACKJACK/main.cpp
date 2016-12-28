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
int main ()
{
    return 0;
}
