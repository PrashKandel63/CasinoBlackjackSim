#pragma once
#include "GenericPlayer.h"

class Dealer : public GenericPlayer {

public:
	int cash;
	Dealer(const string& name = "Dealer");
	virtual ~Dealer();
	//return the amount that Dealer has
	int GetAvailableAmount();
	//Join a queue
	void Queue();
	//pass parameter to join table
	void JoinTable(bool join);
	//Dealer to place a bet
	void Bet(int* stake);
	//Leave Table and join queue
	void Tapout();
	//indicates whether Dealer is hitting - will always hit on 16 or less
	virtual bool IsHitting() const;
	//flips over first card
	void FlipFirstCard();
};