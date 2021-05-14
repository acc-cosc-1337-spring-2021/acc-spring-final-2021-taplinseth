//
#include "shooter.h"

/*Create a dynamic
instance(heap) of Roll, call
Roll roll_die function, add
roll to vector, and return the
roll instance*/
Roll* Shooter::throw_die(Die &die1, Die &die2)
{
    Roll* rolling_dice = 0;
    rolling_dice = new Roll(die1, die2);

    rolling_dice->roll_die();

    rolls.push_back(rolling_dice);

    return rolling_dice;

}

std::ostream& operator<<(std::ostream& out, const Shooter& dicethrow)
{
    for(auto &roll: dicethrow.rolls) //iterates through rolls and clears memory
    {
        out<<roll<<"\n";
    }

    return out;

}
