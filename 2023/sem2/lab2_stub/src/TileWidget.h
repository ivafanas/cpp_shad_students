#pragma once

#include <QPoint>
#include <QWidget>

class TileWidget : public QWidget
{
public:
    TileWidget();

    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QPixmap pixmap;
    QPoint initial_movement_pos{0, 0};
    QPoint camera_pos{0, 0};
};

