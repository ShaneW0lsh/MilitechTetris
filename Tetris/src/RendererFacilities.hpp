#pragma once

#include <QColor>
#include <QPainter>
#include <QPainterPath>

namespace Tetris::gui{

class RendererFacilities{
  public:

    RendererFacilities() = delete;

    static void drawBlock(QPainter& painter, const int x, const int y, const int size, const QColor& colour);
};
}

