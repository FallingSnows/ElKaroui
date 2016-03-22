#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
	std::string						m_playerName;
	unsigned int					m_NumberOfCardsOwed;
public:
	Player(std::string str);
	std::string GetPlayerName() const;
	void SetPlayerName(std::string str);

	//getter
	unsigned int GetNumberOfCardsOwed() const;
	//win the cards
	void Player::AddToAccumulatedCards(unsigned int n);
};


#endif // !PLAYER_H

