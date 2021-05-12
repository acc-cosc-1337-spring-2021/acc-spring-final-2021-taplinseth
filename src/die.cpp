//
#include<die.h>

//randomly assigns a value to roll_value in the range of 1 to 6
void Die::roll()
{
    Die::roll_value = rand() % Die::sides + 1;
}

//returns roll_value
int Die::rolled_value() const
{
    return Die::roll_value;   
}