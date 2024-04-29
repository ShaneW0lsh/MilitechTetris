#pragma once

#include "Tetromino.hpp"

#define S_CHAR 'S'

namespace Tetris::core{

    class Tetromino_S : public Tetris::core::Tetromino{
    public:


        Tetromino_S();

        char getChar() const override;

        std::array<std::array<char,4>,4> getPiece(int orientation) const override;
    };
}

