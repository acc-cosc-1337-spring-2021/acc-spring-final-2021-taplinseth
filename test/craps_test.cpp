#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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