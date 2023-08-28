#pragma once
#include "Piece.h"
#include <vector>

class ChessBoard {
public:
    ChessBoard(const std::vector<std::vector<std::string>>& boardRepresentation);

    void determineThreats();
    Piece& getPiece(int x, int y);
    bool isWithinBoard(int x, int y);

private:
    std::vector<std::vector<Piece>> board;

    // Helper functions to check threats for each piece type
    bool isSquareThreatened(int x, int y, std::string color);
    void checkThreatsFromRook(int x, int y, std::string color);
    void checkThreatsFromBishop(int x, int y, std::string color);
    void checkThreatsFromPawn(int x, int y, std::string color);
    void checkThreatsFromKing(int x, int y, std::string color);
    void checkThreatsFromQueen(int x, int y, std::string color);
    void checkThreatsFromKnight(int x, int y, std::string color);
};
