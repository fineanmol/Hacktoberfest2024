#include <stdio.h>

int main(int argc, char* argv[])
{
	int distance = 100;
	float power = 3.345f;
	double super_power = 56789.4532;
	char initial = 'S';
	char first_name[] = "Gabriel";
	char last_name[] = "Alves";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super power.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

	int bugs = 10;
	double bug_rate = 1.2;

	printf("You have %d bugs at the %f.\n", bugs, bug_rate);

	long universe_of_defects = 109999900L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);
	
	double expected_bugs = bugs * bug_rate;
	printf("you are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs * universe_of_defects;
	printf("that is only a %e portoin of the universe.\n", part_of_universe);
	
	// This makes no sense, just a demo of something weird
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);

	return 0;
}
