/**
 * @file RendererFacilities.h
 * @brief Заголовочный файл для класса RendererFacilities
 */

#pragma once

#include <QColor>
#include <QPainter>
#include <QPainterPath>

namespace Tetris::gui {

/**
 * @class RendererFacilities
 * @brief Класс, предоставляющий функционал для рендеринга элементов
 */
class RendererFacilities {
public:
    /**
     * @brief Конструктор по умолчанию (удален)
     */
    RendererFacilities() = delete;

    /**
     * @brief Метод для отрисовки блока на указанных координатах
     * @param painter QPainter для рисования
     * @param x Координата X блока
     * @param y Координата Y блока
     * @param size Размер блока
     * @param colour Цвет блока
     */
    static void drawBlock(QPainter& painter, const int x, const int y, const int size, const QColor& colour);
};

} // namespace Tetris::gui
