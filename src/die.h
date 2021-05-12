//
#ifndef DIE_H
#define DIE_H
#include<iostream>

class Die
{
public:
    void roll();
    int rolled_value() const;

private:
    int roll_value;
    int sides{6};

};

#endif