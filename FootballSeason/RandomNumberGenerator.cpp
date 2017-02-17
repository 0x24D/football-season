#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(){ //constructor
	seed(); //run function when instance created
}

int RandomNumberGenerator::getRandomValue(const int& max) const {
	//produce a random number in range [1..max]
	return (rand() % max) + 1;
}

void RandomNumberGenerator::seed(){
	srand(static_cast<unsigned>(time(0))); //seed generator using current system time
}