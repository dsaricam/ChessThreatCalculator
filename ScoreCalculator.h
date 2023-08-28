// ScoreCalculator.h
#pragma once
#include "ChessBoard.h"

class ScoreCalculator {
public:
    ScoreCalculator(ChessBoard& board);

    double getScore(std::string color); // 'b' or 'w'

private:
    ChessBoard& chessboard;
};
