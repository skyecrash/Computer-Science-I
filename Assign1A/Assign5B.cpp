/*
  Pgm: Assign5-B
  Name: Lilith Freed (laf65)
  Purpose: Determines the dodgeball master based on a specified
           turn order and strategy.

*/

#include<iostream>
#include<limits>
#include<cstdlib>
#include<ctime>

using std::cout;
using std::endl;

const float AARONACCURACY = 1.0/3;
const float BOBACCURACY = 0.5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS = 1000;

const int AARON = 1;
const int BOB = 2;
const int CHARLIE = 3;

void shoot(bool&, float);
void shootDriver();
int startDuel();

int main()
{
    // Keeps track of wins.
    int aaronWins = 0;
    int bobWins = 0;
    int charlieWins = 0;

    // Seeding rand.
    srand(time(0));

    for(int i = 0; i < NUMDUELS; i++)
    {
        int winner = startDuel();
        switch(winner)
        {
            case 1: aaronWins++;
                    break;
            case 2: bobWins++;
                    break;
            case 3: charlieWins++;
                    break;
        }
    }

    cout << "Using the strategy of shooting at the best shooter alive,\n"
         << "but Aaron intentionally misses on the first shot:\n"
         << "Aaron wins: " << (static_cast<double>(aaronWins) / NUMDUELS) * 100 << "% of his games.\n"
         << "Bob wins: " << (static_cast<double>(bobWins) / NUMDUELS) * 100 << "% of his games.\n"
         << "Charlie wins: " << (static_cast<double>(charlieWins) / NUMDUELS) * 100 << "% of his games.\n";

    return 0;
}

/* Fires a ball at another player.
   pre-cond: a duel is taking place and vars have been initialized for
             each player that keep track of who is alive
   postcond: if the shot hits, change the players alive status to false */
void shoot(bool &isAlive, float accuracy)
{
    if( (double)(rand() % 1000) / 1000.0 < accuracy)
    {
        isAlive = false;
    }

    return;
}

/* Starts a duel. Players take turns until there is one left standing.
   pre-cond: shoot() is a defined function, vars are initialized for
             each player that keep track of who is alive
   postcond: returns the winner as an integer value */
int startDuel()
{
    // Initializes alive bools for the match.
    bool aaronAlive = true;
    bool bobAlive = true;
    bool charlieAlive = true;

    /* This loop logic is based on the strategy that Aaron misses
       his first shot. If Bob does not kill Charlie, Charlie will
       inevitably kill Bob. Thus, by the second turn, if Bob is alive,
       then Charlie must be dead, and a shot that kills Bob leaves
       Aaron as the winner. If Charlie is alive, Bob must be dead,
       and a shot that kills Charlie leaves Aaron as the winner.
       If Bob is alive on his second turn, Charlie is dead and a shot
       that kills Aaron leaves Bob as the winner. If Charlie is alive
       on his second turn, Bob is dead, and he will kill Aaron and win the
       match. Aaron and Bob may go back and forth several turns if they
       are battling it out, so this loop needs to iterate endlessly
       until one of them wins and returns. */
    while(true)
    {
        // Aaron's turn.
        if(bobAlive && charlieAlive)
        {
        }
        else if(bobAlive)
        {
            shoot(bobAlive, AARONACCURACY);
            if(!bobAlive)
            {
                return AARON;
            }
        }
        else
        {
            shoot(charlieAlive, AARONACCURACY);
            if(!charlieAlive)
            {
                return AARON;
            }
        }

        // Bob's turn.
        if(bobAlive)
        {
            if(charlieAlive)
            {
                shoot(charlieAlive, BOBACCURACY);
            }
            else
            {
                shoot(aaronAlive, BOBACCURACY);
                if(!aaronAlive)
                {
                    return BOB;
                }
            }
        }

        // Charlie's turn.
        if(charlieAlive)
        {
            if(bobAlive)
            {
                shoot(bobAlive, CHARLIEACCURACY);
            }
            else
            {
                return CHARLIE;
            }
        }
    }
}

/* Driver function for shoot().
   pre-cond: shoot has been defined
   post-cond: outputs how many hits a player made out of 1000 */
void shootDriver()
{
    int aaronHits = 0;
    for(int i = 0; i < 1000; i++)
    {
        bool isAlive = true;
        shoot(isAlive, AARONACCURACY);
        if(!isAlive)
        {
            aaronHits++;
        }
    }

    int bobHits = 0;
    for(int i = 0; i < 1000; i++)
    {
        bool isAlive = true;
        shoot(isAlive, BOBACCURACY);
        if(!isAlive)
        {
            bobHits++;
        }
    }

    int charlieHits = 0;
    for(int i = 0; i < 1000; i++)
    {
        bool isAlive = true;
        shoot(isAlive, CHARLIEACCURACY);
        if(!isAlive)
        {
            charlieHits++;
        }
    }

    cout << "Aaron hits: " << aaronHits << endl;
    cout << "Bob hits: " << bobHits << endl;
    cout << "Charlie hits: " << charlieHits << endl;

    return;
}
