#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Tests die class") {
	Die game;

	for(int i = 0; i < 10; i++)
	{
		game.roll();
		REQUIRE(game.rolled_value() >= 1);
		REQUIRE(game.rolled_value() <= 6);
	}

}