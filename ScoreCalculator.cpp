// ScoreCalculator.cpp
#include <iostream>
#include "ScoreCalculator.h"

ScoreCalculator::ScoreCalculator(ChessBoard& board) : chessboard(board) {}

double ScoreCalculator::getScore(std::string color) {
    double score = 0.f;

    // Loop over the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece& piece = chessboard.getPiece(i, j);
            if (piece.getColor() == color) {
                if (piece.isThreatened()) {
//                    std::cout<<piece.getType()<<" is threatened and value is "<<piece.getValue()<<std::endl;
                    score += double(piece.getValue()) / 2.0f;
                } else {
                    score += double(piece.getValue());
                }
            }
        }
    }
    std::cout<<"final score is "<<score<<std::endl;
    return score;
}
