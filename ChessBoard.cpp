// ChessBoard.cpp
#include "ChessBoard.h"
#include <iostream>

ChessBoard::ChessBoard(const std::vector<std::vector<std::string>>& boardRepresentation) {
    for (const auto& row : boardRepresentation) {
        std::vector<Piece> boardRow;
        for (const auto& item : row) {
            boardRow.emplace_back(item);
        }
        board.push_back(boardRow);
    }
}

Piece& ChessBoard::getPiece(int x, int y){
    return board[x][y];
}

bool ChessBoard::isWithinBoard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void ChessBoard::determineThreats() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::string pieceType = board[i][j].getType();
            std::string color = board[i][j].getColor();

            if (pieceType == "k")
                checkThreatsFromRook(i, j, color);
            else if (pieceType == "f")
                checkThreatsFromBishop(i, j, color);
            else if (pieceType == "a")
                checkThreatsFromKnight(i, j, color);
            else if (pieceType == "p")
                checkThreatsFromPawn(i, j, color);
            else if (pieceType == "v")
                checkThreatsFromQueen(i, j, color);
            else if (pieceType == "s")
                checkThreatsFromKing(i, j, color);
            
        }
    }
}

void ChessBoard::checkThreatsFromRook(int x, int y, std::string color) {
    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[i];
            ny += dy[i];
            if (!isWithinBoard(nx, ny) || (board[nx][ny].getColor() == color && board[nx][ny].getType() != "--")) {
                break;
            }
            if (board[nx][ny].getType() != "--") {
                if (board[nx][ny].getColor() != color) {
                    board[nx][ny].setThreatened(true);
                }
                break;
            }
        }
    }
}

void ChessBoard::checkThreatsFromBishop(int x, int y, std::string color) {
    // Directions: diagonal up-left, up-right, down-left, down-right
    int dx[] = {-1, -1, 1, 1};
    int dy[] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[i];
            ny += dy[i];
            if (!isWithinBoard(nx, ny) || (board[nx][ny].getColor() == color && board[nx][ny].getType() != "--")) {
                break;
            }
            if (board[nx][ny].getType() != "--") {
                if (board[nx][ny].getColor() != color) {
                    board[nx][ny].setThreatened(true);
                }
                break;
            }
        }
    }
}

void ChessBoard::checkThreatsFromPawn(int x, int y, std::string color) {
    int direction = (color == "b") ? -1 : 1; // White pawns move up, black pawns move down

    // Diagonal left and right
    if (isWithinBoard(x + direction, y - 1) && board[x + direction][y - 1].getColor() != color && board[x + direction][y - 1].getType() != "--") {
        board[x + direction][y - 1].setThreatened(true);
    }

    if (isWithinBoard(x + direction, y + 1) && board[x + direction][y + 1].getColor() != color && board[x + direction][y + 1].getType() != "--") {
        board[x + direction][y + 1].setThreatened(true);
    }
}

void ChessBoard::checkThreatsFromKing(int x, int y, std::string color) {
    // Directions: all adjacent squares
    int dx[] = {-1, -1, -1,  0, 1, 1, 1,  0};
    int dy[] = {-1,  0,  1,  1, 1, 0, -1, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isWithinBoard(nx, ny) && board[nx][ny].getColor() != color && board[nx][ny].getType() != "--") {
            board[nx][ny].setThreatened(true);
        }
    }
}

void ChessBoard::checkThreatsFromQueen(int x, int y, std::string color) {
    // Queen combines the threats of both the rook and the bishop
    checkThreatsFromRook(x, y, color);
    checkThreatsFromBishop(x, y, color);
}

void ChessBoard::checkThreatsFromKnight(int x, int y, std::string color) {
    // Directions: all possible knight moves
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isWithinBoard(nx, ny) && board[nx][ny].getColor() != color && board[nx][ny].getType() != "--") {
            board[nx][ny].setThreatened(true);
        }
    }
}
