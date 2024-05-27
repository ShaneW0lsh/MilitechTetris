#pragma once

#include "Tetromino.hpp"
#include "TetrominoFactory.hpp"

#include <cassert>
#include <QColor>

namespace Tetris::core{
/**
 * @class Board
 * @brief Представляет игровое поле для игры Тетрис.
 */
class Board{
public:

    /**
     * @brief Создает новый объект Board.
     */
    Board();

    /**
     * @brief Очищает игровое поле.
     */
    void clear();

    /**
     * @brief Стирает линии в указанном диапазоне.
     * @param range Пара целых чисел, представляющих начало и конец диапазона.
     */
    void eraseLines(const std::pair<int, int>& range);

    /**
     * @brief Получает константную ссылку на игровое поле.
     * @return const auto& Константная ссылка на игровое поле.
     */
    const auto& getBoard() const;

    /**
     * @brief Опускает текущую фигуру вниз до самого низа игрового поля.
     */
    void dropCurrentPiece();

    /**
     * @brief Проверяет, закончена ли игра.
     * @return true Если игра закончена, false в противном случае.
     */
    bool isGameOver() const;

    /**
     * @brief Проверяет, может ли текущая фигура двигаться вниз.
     * @return true Если фигура может двигаться вниз, false в противном случае.
     */
    bool canMoveCurrentPieceDown() const;

    /**
     * @brief Проверяет, может ли текущая фигура двигаться влево.
     * @return true Если фигура может двигаться влево, false в противном случае.
     */
    bool canMoveCurrentPieceLeft() const;

    /**
     * @brief Проверяет, может ли текущая фигура двигаться вправо.
     * @return true Если фигура может двигаться вправо, false в противном случае.
     */
    bool canMoveCurrentPieceRight() const;

    /**
     * @brief Проверяет, может ли текущая фигура быть повернута.
     * @return true Если фигура может быть повернута, false в противном случае.
     */
    bool canRotateCurrentPiece() const;

    /**
     * @brief Проверяет, находится ли указанная координата x в пределах ширины игрового поля.
     * @param x Координата x для проверки.
     * @return true Если координата находится в пределах ширины игрового поля, false в противном случае.
     */
    constexpr static bool isWithinBoardWidth(const int x);

    /**
     * @brief Проверяет наличие заполненных линий на игровом поле.
     * @return std::pair<int, int> Пара целых чисел, представляющих начало и конец диапазона заполненных линий.
     */
    std::pair<int, int> hasCompletedLines() const;

    /**
     * @brief Устанавливает текущую фигуру.
     * @param t Уникальный указатель на объект Tetromino.
     */
    void setCurrentPiece(std::unique_ptr<Tetris::core::Tetromino> t);

    /**
     * @brief Устанавливает следующую фигуру.
     * @param t Уникальный указатель на объект Tetromino.
     */
    void setNextPiece(std::unique_ptr<Tetris::core::Tetromino> t);

    /**
     * @brief Меняет местами текущую и следующую фигуры.
     * @param next Уникальный указатель на объект Tetromino.
     */
    void swapPieces(std::unique_ptr<Tetris::core::Tetromino> next);

    /**
     * @brief Получает текущую фигуру.
     * @return Tetromino* Указатель на текущий объект Tetromino.
     */
    Tetromino* getCurrentPiece();

    /**
     * @brief Получает следующую фигуру.
     * @return Tetromino* Указатель на следующий объект Tetromino.
     */
    Tetromino* getNextPiece();

    /**
     * @brief Получает ячейку в указанном месте на игровом поле.
     * @param x Координата x ячейки.
     * @param y Координата y ячейки.
     * @return char Символ, представляющий ячейку.
     */
    char getCell(const int x, const int y) const;

    /**
     * @brief Получает цвет, ассоциированный с указанным символом.
     * @param c Символ, для которого нужно получить цвет.
     * @return QColor Цвет, ассоциированный с символом.
     */
    static QColor getCharColor(const char c);

    /**
     * @brief Высота игрового поля.
     */
    constexpr static int m_height = 22;

    /**
     * @brief Ширина игрового поля.
     */
    constexpr static int m_width = 10;

private:

    std::array<std::array<char, m_width>, m_height> m_board; /**< Игровое поле. */

    std::unique_ptr<Tetris::core::Tetromino> m_currentPiece; /**< Текущая фигура. */

    std::unique_ptr<Tetris::core::Tetromino> m_nextPiece; /**< Следующая фигура. */
};
}
