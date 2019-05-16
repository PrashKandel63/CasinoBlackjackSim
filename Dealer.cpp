#include "Dealer.h"

Dealer::Dealer(const string& name) : GenericPlayer(name){}

Dealer::~Dealer() {}

int Dealer::GetAvailableAmount() {
	return Dealer::cash;
}
void Dealer::Queue() {}

void Dealer::JoinTable(bool join) {}

void Dealer::Bet(int* stake) {}

void Dealer::Tapout() {}

bool Dealer::IsHitting() const {
	return (GetTotal() <= 16);
}

void Dealer::FlipFirstCard() {
	if (!(m_Cards.empty()))
		m_Cards[0]->Flip();
	else cout << "\n\n------ No card to flip! ------\n\n";
}