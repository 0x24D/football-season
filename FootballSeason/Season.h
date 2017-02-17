#if !defined(SeasonH)
#define SeasonH
#include "Team.h"
#include "RandomNumberGenerator.h"
#include "Constants.h"
#include <vector>
#include <iostream> //for input and output
using namespace std;
class Season{
public:
	Season();
	const void run();
	const void outputScores() const;
private:
	vector<Team> team_; //vector of teams
	int table_ [NUMBEROFTEAMS][5]; //league table array
	const static RandomNumberGenerator srng_;
	const void createLeagueTable();
};
#endif