
#include <QOpenGLWidget>
#include <QPainter>

class GameRenderer : public QOpenGLWidget
{
  public:
    /**
     * @brief RendererGame's constructor.
     */
    GameRenderer();

    /**
     * @brief initializeGL is called once before paintGL() or resizeGL().
     * It sets up any requiredd OpenGL ressources and state.
     */
    void initializeGL() override;

    /**
     * @brief paintGL renders the OpenGL scene. It gets called
     * whenever the widget needs to be updated.
     */
    void paintGL() override;

    /**
     * @brief resizeGL is called whenever the widget has been resized.
     * @param w is window with.
     * @param h is window height.
     */
    void resizeGL(int w, int h) override;
};
