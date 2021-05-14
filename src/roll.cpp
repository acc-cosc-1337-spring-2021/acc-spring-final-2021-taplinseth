//
#include "roll.h"

void Roll::roll_die()
{
    //rolls dice
    Roll::die1.roll();
    Roll::die2.roll();

    //saves total dice value
    value = die1.rolled_value() + die2.rolled_value();

    Roll::rolled = true;
}

int Roll::roll_value() const
{
    return value;
}