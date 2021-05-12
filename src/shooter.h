//
#ifndef SHOOTER_H
#define SHOOTER_H
#include "roll.h"
#include<vector>

class Shooter
{
public:
    Roll* throw_die(Die &die1, Die &die2);
    friend std::ostream& operator<<(std::ostream& out, const Shooter& dicethrow);

private:
    std::vector<Roll*>rolls;
};

#endif