#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Card.h"
#include "Player.h"
class Game
{
	unsigned int						m_numberOfPacks;
	unsigned int						m_matchMode;
	std::vector<Player>					m_players;
	std::vector<Card>					m_cards;
public:
	//set game
	void SetNumberOfPacks();
	void SetMatchMode();
	void ShufflingCards();
	//define two player
	void InitializePlayers();

	//like the main function here, detail in the code
	void GameSimulation();

	//check every round
	bool CheckCardMatch(Card& A, Card& B) const;
	
	//choose a play randomly
	std::string ChoosePlayerWithSnap() const;
	
	//display the result
	void CheckWinner() const;
};


#endif // !GAME_H

