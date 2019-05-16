#pragma once

#include <ctime>
#include <string>
#include "GenericPlayer.h"

using namespace std;

class Player : public GenericPlayer {

public:
	int tableNum;
	//Player(const string& id = "", const int strategy, const int cash);
	Player(const string& id = "");
	virtual ~Player();
	//players cash balance
	int GetAvailableBalance();
	//player places a bet
	void Bet(int stake);
	//Join a table
	void JoinTable(bool join, int tableNum);
	//Join a queue
	void Queue();
	//Leave a table
	void LeaveTable();
	//returns whether or not the player wants another hit
	virtual bool IsHitting() const;
	//announces that the player wins
	void Win(int);
	//announces that the player loses
	void Lose(int);
	//announces that the player pushes
	void Push() const;
};