#include <iostream>		//for output and input
#include "Season.h"
using namespace std;
int main(){
	Season s; //create instance of Season class
	s.run(); //simulate season
	s.outputScores(); //output scores and league table
	system("pause"); //wait for input
	return 0;
}