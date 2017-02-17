#if !defined(TeamH)
#define TeamH
#include "Constants.h"
#include <string>
using namespace std;
class Team{
public:
	Team();
	const int getWins() const;
	const int getDraws() const;
	const int getLosses() const;
	const void incrementWins();
	const void incrementDraws();
	const void incrementLosses();
	int matches[NUMBEROFTEAMS - 1][3]; //matches array
private:
	int wins_, draws_, losses_;
};
#endif