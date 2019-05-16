#pragma once

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class params {

public:
	params();
	ifstream inData;
	//Number of blackjack tables in casino
	int n_tables;
	//<# of players on a table> < # of card decks used>
	int min_Players, max_Players, min_cards, max_cards;
	//<transition thresholds for the four kinds of tables>
	int transitionTable1, transitionTable2, transitionTable3, transitionTable4;
	//<# of dealers> <salary per round> <win percentage>
	int n_Dealers, salary, winPercentage;
	//<ratio of starting cash to Refill Cash Threshold>
	int startCash, refillCash;
	//-- - the cash value is calculated by multiplying the ratio with max betting amt of table
	//Number of Initial Players
	int n_Initiallayers;
	//<RPlayer %> <MDPlayer %> <SPlayer %> <CPlayer %>
	int rPlayer, mdPlayer, sPlayer, cPlayer;
	//<level1%> <level2%> <level3%> <level4%>
	int rLevel1, rLevel2, rLevel3, rLevel4;
	//<level1%> <level2%> <level3%> <level4%>
	int mdLevel1, mdLevel2, mdLevel3, mdLevel4;
	//<level1%> <level2%> <level3%> <level4%>
	int sLevel1, sLevel2, sLevel3, sLevel4;
	//<level1%> <level2%> <level3%> <level4%>
	int cLevel1, cLevel2, cLevel3, cLevel4;
	string buf;
	//Probability of player arrival after simulation starts
	float playerArrival;
	int parameters();
	int val(int v);
	float arrival(int v);
};