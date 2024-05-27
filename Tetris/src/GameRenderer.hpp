#pragma once

#include <QOpenGLWidget>
#include <QPainter>
#include <QPainterPath>
#include <QColor>
#include <QKeyEvent>

#include "core/Board.hpp"
#include "RendererFacilities.hpp"

namespace Tetris::gui{
    /**
     * @brief RendererGame - это пользовательский виджет OpenGL для отображения игры.
     */
    class GameRenderer : public QOpenGLWidget{
      public:

        /**
         * @brief Конструктор RendererGame.
         */
        GameRenderer();

        /**
         * @brief initializeGL вызывается один раз перед paintGL() или resizeGL().
 * Он устанавливает все требуемые ресурсы OpenGL и состояние.
         */
        void initializeGL() override;

        /**
         * @brief paintGL рендерит сцену OpenGL. Она вызывается
 * всякий раз, когда требуется обновить виджет.
 */
        void paintGL() override;

        /**
 * @brief resizeGL вызывается всякий раз, когда изменяется размер виджета.
 * @param w - это размер окна.
 * @param h - высота окна.
         */
        void resizeGL(int w, int h) override;

        /**
 * @brief setBoard определяет доску для рисования.
 * @param board - это новая доска.
 */
        void setBoard(Tetris::core::Board* board);
        /**
 * @brief setGameOver определяет состояние завершения игры.
 * @параметр b - это новое состояние завершения игры.
 */
        void setGameOver(const bool b);

        /**
 * @brief drawGameOverScreen вызывается при достижении состояния окончания игры
 *.
 */
        void drawGameOverScreen();

        /**
         * @brief setExtraShapes определяет дополнительные фигуры для рисования после всего.
 * Его можно использовать для создания анимации (мигание, перевод...).
 * @param добавляет дополнительные фигуры для рисования.
         */
        void setExtraShapes(const std::vector<QPainterPath>& extraShapes);

        /**
* @brief setExtraColor определяет цвет, который будет использоваться для дополнительных фигур.
 * @param c - это цвет для дополнительных фигур.
         */
        void setExtraColor(const QColor& c);

        /**
         * @brief getCellSize определяет размер ячейки в соответствии с размерами окна.
         */
        unsigned getCellSize() const;

        /**
         * @brief getMarginLeft указывает поле слева, с которого рисуется доска.
         */
        unsigned getMarginLeft() const;

        /**
         * @brief getMarginTop указывает расстояние от вершины, с которой рисуется доска.
         */
        unsigned getMarginTop() const;

      private:

        /**
         * @brief m_board - это доска для рисования.
         */
        Tetris::core::Board* m_board;

        /**
         * @brief m_gameOver - это состояние окончания игры.
         */
        bool m_gameOver;

        /**
         * @brief m_extraShapes - это дополнительные фигуры для рисования.
         */
        std::vector<QPainterPath> m_extraShapes;

        /**
         * @brief m_extraColor - это цвет, используемый для дополнительных фигур.
         */
        QColor m_extraColor;

        /**
         * @brief m_cellSize - это размер ячеек, составляющих область тетриса.
         */
        unsigned m_cellSize;

        /**
         * @brief m_marginLeft - это левое поле, от которого отрисовывается доска.
         */
        unsigned m_marginLeft;

        /**
         * @brief m_marginTop - это верхнее поле, от которого отрисовывается доска.
         */
        unsigned m_marginTop;
    };
}
