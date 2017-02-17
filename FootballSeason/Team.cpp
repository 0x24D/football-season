#include "Team.h"

Team::Team(): wins_(0), draws_(0), losses_(0){ //constructor - set wins/draws/losses to 0
	for (int i = 0; i < NUMBEROFTEAMS - 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matches[i][j] = -1; //fill matches array with -1
		}
	}
}

const int Team::getWins() const{ //get win count
	return wins_;
}

const int Team::getDraws() const{ //get draw count
	return draws_;
}

const int Team::getLosses() const{ //get loss count
	return losses_;
}

const void Team::incrementWins(){ //increase wins by one
	wins_++;
}

const void Team::incrementDraws(){ //increase draws by one
	draws_++;
}

const void Team::incrementLosses(){ //increase losses by one
	losses_++;
}