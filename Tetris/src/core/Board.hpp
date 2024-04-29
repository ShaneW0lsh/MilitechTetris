#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

namespace Tetris::core{


    class Board{
    public:


        Board();

        void clear();

        void eraseLines(const std::pair<int, int>& range);

        const auto& getBoard() const;

        void dropCurrentPiece();

        bool isGameOver() const;

        bool canMoveCurrentPieceDown() const;

        bool canMoveCurrentPieceLeft() const;

        bool canMoveCurrentPieceRight() const;

        bool canRotateCurrentPiece() const;

        constexpr static bool isWithinBoardWidth(const int x);

        std::pair<int, int> hasCompletedLines() const;

        void setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t);

        void setNextPiece(std::unique_ptr<Tetris::core::Tetromino> t);

        void swapPieces(std::unique_ptr<Tetris::core::Tetromino> next);

        Tetromino* getCurrentPiece();

        Tetromino* getNextPiece();

        char getCell(const int x, const int y) const;

        static QColor getCharColor(const char c);

        constexpr static int m_height = 22;

        constexpr static int m_width = 10;

    private:

        std::array<std::array<char, m_width>, m_height> m_board;

        std::unique_ptr<Tetris::core::Tetromino> m_currentPiece;

        std::unique_ptr<Tetris::core::Tetromino> m_nextPiece;
    };
}
