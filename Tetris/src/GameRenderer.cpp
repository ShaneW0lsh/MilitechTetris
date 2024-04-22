#include "GameRenderer.h"

GameRenderer::GameRenderer() {}

void GameRenderer::paintGL()
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.fillRect(0, 0, this->width(), this->height(), QBrush(Qt::black));
}

void GameRenderer::resizeGL(int w, int h) { glViewport(0, 0, w, h); }
