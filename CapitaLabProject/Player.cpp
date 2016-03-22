#include "Player.h"

Player::Player(std::string str) : m_playerName(str), m_NumberOfCardsOwed(0){};

std::string Player::GetPlayerName() const
{
	return m_playerName;
};
void Player::SetPlayerName(std::string str)
{
	m_playerName = str;
	return;
};

unsigned int Player::GetNumberOfCardsOwed() const
{
	return m_NumberOfCardsOwed;
};
void Player::AddToAccumulatedCards(unsigned int n)
{
	m_NumberOfCardsOwed += n;
	return;
};
