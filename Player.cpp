#include "ExternLib.h"

using namespace std;

void pause(int);

void pause(int dur)  {
	int temp = time(NULL) + dur;
	while (temp > time(NULL));
}

int cashBalance;
Player::Player(const string& name) : GenericPlayer(name){}
Player::~Player(){}

void Player::Queue(){}

int Player::GetAvailableBalance() {
	return 0;
}

void Player::Bet(int Stake) {}

void Player::JoinTable(bool join,int tableNum) {}

void Player::LeaveTable() {}

bool Player::IsHitting() const {	
	cout << m_Name << "  is deciding whether to hit or stay...\n";
	char response;
	/*/////////////////////////////
	*/
	random_device rd;     // only used once to initialise (seed) engine
	mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> uni(1, 2); // guaranteed unbiased
	pause(3);
	auto random_integer = uni(rng);
	if (random_integer == 1) {
	cout<<"-> "<<m_Name << " Hit\n";
	return true;
}
	else {
	cout << "-> " << m_Name << " Stays\n";
	return false;
		}
	///////////////////////////////
}

void Player::Win(int prize)  {
	cout << m_Name << " wins with $"<<prize<<".00"<<endl;
}

void Player::Lose(int lose)  {
	cout << m_Name << " loses with $"<<lose<<".00"<<endl;
}

void Player::Push() const {
	cout << m_Name << " pushes.\n";
}
//Strategy