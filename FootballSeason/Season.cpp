#include "Season.h"

Season::Season(){ //constructor
	for (int i = 0; i < NUMBEROFTEAMS; i++)
	{
		team_.push_back(Team()); //create teams to be simulated
	}
	for (int i = 0; i < NUMBEROFTEAMS; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			table_[i][j] = -1; //fill league table array with -1 
		}
	}
}
const void Season::run(){
	int homeScore, awayScore;
	for (int h = 0; h < NUMBEROFTEAMS; h++)
	{
		for (int a = (h + 1); a < NUMBEROFTEAMS; a++)
		{
			homeScore = srng_.getRandomValue(MAXGOALS); //generate random score for home (max of 5)
			awayScore = srng_.getRandomValue(MAXGOALS); //generate random score for away (max of 5)
			if (homeScore > awayScore)
			{
				team_[h].incrementWins(); //increase win count
				team_[a].incrementLosses(); //increase loss count
			}
			else if (homeScore == awayScore)
			{
				team_[h].incrementDraws(); //increase draw count
				team_[a].incrementDraws();
			}
			else
			{
				team_[h].incrementLosses(); //increase loss count
				team_[a].incrementWins(); //increase win count
			}

			team_[h].matches[a-1][0] = homeScore; //set home team score, away team score and opposition team in corresponding matches array
			team_[h].matches[a-1][1] = awayScore;
			team_[h].matches[a-1][2] = a;
			team_[a].matches[h][0] = awayScore;
			team_[a].matches[h][1] = homeScore;
			team_[a].matches[h][2] = h;
			

		}
	}
	createLeagueTable(); //create league table after all matches have been simulated
}
const void Season::outputScores() const{
	for (int i = 0; i < NUMBEROFTEAMS; i++)
	{
		cout << "Team " << (i + 1) << "\n"; //output team name
		for  (int j = 0; j < NUMBEROFTEAMS - 1; j++)
		{
			cout << "Team " << (i + 1) << " " << team_[i].matches[j][0] << " - " << team_[i].matches[j][1] << " Team " << (team_[i].matches[j][2] + 1) << "\n"; //output data from matches array
		}
		cout << "\n";
	}
	for (int i = 0; i < NUMBEROFTEAMS; i++)
	{
		cout << "Team " << table_[i][0] << " - " << table_[i][1] << " / " << table_[i][2] << " / " << table_[i][3] << " - " << table_[i][4] << "\n"; //output data from league table array
	}
}

const void Season::createLeagueTable(){
	for (int i = 0; i < NUMBEROFTEAMS; i++) 
	{
		table_[i][0] = (i + 1);
		table_[i][1] = team_[i].getWins(); //get wins for each team
		table_[i][2] = team_[i].getDraws(); //get draws for each team
		table_[i][3] = team_[i].getLosses(); //get losses for each team
		table_[i][4] = ((table_[i][1] * 3) + table_[i][2]); //generate total score using win and draw counts
	}
}
const RandomNumberGenerator Season::srng_; //static instance of rng (only needed once)