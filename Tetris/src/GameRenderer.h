#pragma once
#include <QOpenGLWidget>
#include <QPainter>

class GameRenderer : public QOpenGLWidget
{
public:
    GameRenderer();
    void paintGL() override;
    void resizeGL(int w, int h) override;
};
