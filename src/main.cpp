#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include<iostream>

using std::cout;

int main() 
{
	srand(time(0)); //creates true random numbers

	Die die1, die2;
	Shooter shooter;
	Roll *roll = shooter.throw_die(die1, die2);

	ComeOutPhase come_out_phase;

	while(come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps){
		cout<<"Rolled "<<roll->roll_value()<<" roll again"<<"\n";
		roll = shooter.throw_die(die1, die2);
	}

	cout<<"Rolled "<<roll->roll_value()<<" start of point phase"<<"\n";
	cout<<"Roll until rolled value or a 7 is rolled"<<"\n";

	int point = roll->roll_value();
	roll = shooter.throw_die(die1, die2);

	PointPhase point_phase(point);

	while(point_phase.get_outcome(roll) == RollOutcome::point || point_phase.get_outcome(roll) == RollOutcome::nopoint){
		cout<<roll->roll_value()<<" Roll again"<<"\n";
		roll = shooter.throw_die(die1, die2);
	}

	cout<<"Rolled "<<roll->roll_value()<<" end of point phase"<<"\n";

	cout<<shooter;


	return 0;
}