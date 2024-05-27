/**
 * @file GameRenderer.hpp
 * @brief Заголовочный файл для класса GameRenderer
 */

#pragma once

#include <QPainter>
#include <QPainterPath>
#include <QColor>
#include <QFont>
#include <QWidget>
#include <vector>
#include "Board.hpp"
#include "RendererFacilities.hpp"

namespace Tetris::gui {

/**
     * @class GameRenderer
     * @brief Класс для отрисовки игрового поля и элементов игры
     */
class GameRenderer : public QWidget {
    Q_OBJECT

public:
    /**
         * @brief Конструктор класса GameRenderer
         */
    GameRenderer();

    /**
         * @brief Инициализация OpenGL
         */
    void initializeGL();

    /**
         * @brief Отрисовка содержимого OpenGL
         */
    void paintGL();

    /**
         * @brief Отрисовка экрана завершения игры
         */
    void drawGameOverScreen();

    /**
         * @brief Изменение размеров OpenGL
         * @param w Ширина
         * @param h Высота
         */
    void resizeGL(int w, int h);

    /**
         * @brief Установить игровое поле
         * @param board Указатель на игровое поле
         */
    void setBoard(Tetris::core::Board *board);

    /**
         * @brief Установить статус завершения игры
         * @param b Статус завершения игры
         */
    void setGameOver(bool b);

    /**
         * @brief Установить дополнительный цвет
         * @param c Цвет
         */
    void setExtraColor(const QColor &c);

    /**
         * @brief Установить дополнительные формы
         * @param extraShapes Вектор дополнительных форм
         */
    void setExtraShapes(const std::vector<QPainterPath> &extraShapes);

    /**
         * @brief Получить размер ячейки
         * @return Размер ячейки
         */
    unsigned getCellSize() const;

    /**
         * @brief Получить отступ сверху
         * @return Отступ сверху
         */
    unsigned getMarginTop() const;

    /**
         * @brief Получить отступ слева
         * @return Отступ слева
         */
    unsigned getMarginLeft() const;

private:
    Tetris::core::Board *m_board; ///< Указатель на игровое поле
    bool m_gameOver; ///< Флаг завершения игры
    unsigned m_cellSize; ///< Размер ячейки
    unsigned m_marginLeft; ///< Отступ слева
    unsigned m_marginTop; ///< Отступ сверху
    QColor m_extraColor; ///< Дополнительный цвет
    std::vector<QPainterPath> m_extraShapes; ///< Вектор дополнительных форм

    /**
         * @brief Конструктор копирования класса GameRenderer
         */
    GameRenderer(const GameRenderer&) = delete;

    /**
         * @brief Оператор присваивания класса GameRenderer
         */
    GameRenderer& operator=(const GameRenderer&) = delete;
};

} // namespace Tetris::gui
