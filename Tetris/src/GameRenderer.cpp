#include "GameRenderer.hpp"
#include <iostream>

Tetris::gui::GameRenderer::GameRenderer()
    : m_board(nullptr), m_gameOver(false), m_cellSize(0), m_marginLeft(0), m_marginTop(0)
{

}

void Tetris::gui::GameRenderer::initializeGL(){
    //
}

void Tetris::gui::GameRenderer::paintGL(){
    if(m_gameOver){
        drawGameOverScreen();
        return;
    }
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.fillRect(0,0,this->width(), this->height(),QBrush(Qt::black));

    if(m_board){
        m_cellSize = this->height() / Tetris::core::Board::m_height;
        m_marginLeft = (this->width() - Tetris::core::Board::m_width * m_cellSize) / 2;
        m_marginTop = this->height() - Tetris::core::Board::m_height * m_cellSize;
        for(int i = 0; i < Tetris::core::Board::m_height; ++i){
            for(int j = 0; j < Tetris::core::Board::m_width; ++j){
                if(m_board->getCell(j,i) != EMPTY_CELL){
                    Tetris::gui::RendererFacilities::drawBlock(painter, m_marginLeft + j * m_cellSize, m_marginTop + i * m_cellSize, m_cellSize, m_board->getCharColor(m_board->getCell(j,i)));
                }else{
                    painter.setPen(Qt::blue);
                    painter.drawRect(m_marginLeft + j * m_cellSize, m_marginTop + i * m_cellSize, m_cellSize, m_cellSize);
                }
            }
        }
        for(const auto& shape : m_extraShapes){
            painter.fillPath(shape, m_extraColor);
        }
    }
}

void Tetris::gui::GameRenderer::drawGameOverScreen(){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(), this->height(), QBrush(Qt::red));
    painter.setFont(QFont("Courier", 36, QFont::DemiBold));
    painter.drawText(0, 0, width(), height(), Qt::AlignCenter, "GAME OVER!");
    painter.end();
}

void Tetris::gui::GameRenderer::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void Tetris::gui::GameRenderer::setBoard(Tetris::core::Board *board){
    m_board = board;
}

void Tetris::gui::GameRenderer::setGameOver(bool b){
    m_gameOver = b;
}

void Tetris::gui::GameRenderer::setExtraColor(const QColor &c){
    m_extraColor = c;
}

void Tetris::gui::GameRenderer::setExtraShapes(const std::vector<QPainterPath> &extraShapes){
    m_extraShapes = extraShapes;
}

unsigned Tetris::gui::GameRenderer::getCellSize() const {
    return m_cellSize;
}

unsigned Tetris::gui::GameRenderer::getMarginTop() const{
    return m_marginTop;
}

unsigned Tetris::gui::GameRenderer::getMarginLeft() const{
    return m_marginLeft;
}

