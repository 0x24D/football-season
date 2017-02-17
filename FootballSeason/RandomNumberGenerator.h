#if !defined(RandomNumberGeneratorH)
#define RandomNumberGeneratorH

#include <stdlib.h>	//for srand and rand routines
#include <ctime> //for time in seed()

using namespace std;

class RandomNumberGenerator{
public:
	RandomNumberGenerator();
	int getRandomValue(const int& max) const; //get random value between 0 and max value
private:
	void seed();
};
#endif