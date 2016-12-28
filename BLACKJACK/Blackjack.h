#include<iostream>
#include<stdlib.h>
#define MAX_CARD 53
using namespace std;
unsigned int Deck[MAX_CARD];
struct Card
{
     unsigned int number ;
     char symbol[10];
};
bool CheckCard(unsigned int Card);
unsigned int RandomCard();
