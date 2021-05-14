#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Tests die class") {
	Die die_roll;

	for(int i = 0; i < 10; i++)
	{
		die_roll.roll();
		REQUIRE(die_roll.rolled_value() >= 1);
		REQUIRE(die_roll.rolled_value() <= 6);
	}

}

TEST_CASE("Tests roll class") {
	Die first_die;
	Die second_die;
	Roll diceroll(first_die, second_die);

	for(int i = 0; i < 10; i++)
	{
		diceroll.roll_die();
		REQUIRE(diceroll.roll_value() >= 2);
		REQUIRE(diceroll.roll_value() <= 12);
	}

}

TEST_CASE("Tests shooter class, verifies roll result"){
	Die first_die;
	Die second_die;
	Shooter diceroll;

	for(int i = 0; i < 10; i++)
	{
		REQUIRE(diceroll.throw_die(first_die, second_die)->roll_value() >= 2);
		REQUIRE(diceroll.throw_die(first_die, second_die)->roll_value() <= 12);
	}
}

TEST_CASE("Tests ComeOutPhase class"){
	Die first_die;
	Die second_die;
	Shooter diceroll;
	ComeOutPhase come_out;

	for(int i = 0; i < 10; i++)
	{
		REQUIRE(come_out.get_outcome(diceroll.throw_die(first_die, second_die)) != RollOutcome::seven_out); //if seven_out then craps, natural, point okay
	}
}

TEST_CASE("Test PointPhase"){
	Die first_die;
	Die second_die;
	Shooter diceroll;
	

	for(int i = 0; i < 10; i++)
	{
		int points = rand() % 12 + 1;
		PointPhase point(points);

		REQUIRE(point.get_outcome(diceroll.throw_die(first_die, second_die)) != RollOutcome::natural); //if natural then seven_out, point, and nopoint okay
	}
}

