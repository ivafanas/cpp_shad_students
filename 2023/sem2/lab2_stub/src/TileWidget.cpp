#include "TileWidget.h"

#include <QMouseEvent>
#include <QPainter>

// TODO: rework TileWidget in order to satisfy software requirements;
//       make sure there is no expensive ops on Ui thread

TileWidget::TileWidget()
    : pixmap("cppmap2012.jpg")
{
    setMinimumWidth(800);
    setMinimumHeight(800);

    setMouseTracking(true);
}

void TileWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.translate(-camera_pos);
    painter.drawPixmap(QPoint{0, 0}, pixmap);
}

void TileWidget::mousePressEvent(QMouseEvent* event)
{
    // remember mouse position on left button click
    if (event->button() == Qt::LeftButton)
        initial_movement_pos = event->pos();

    event->accept();
}

void TileWidget::mouseMoveEvent(QMouseEvent* event)
{
    // process mouse movement only if left button is clicked
    if (event->buttons() == Qt::LeftButton)
    {
        // update camera position based on mouse movement
        camera_pos += initial_movement_pos - event->pos();
        initial_movement_pos = event->pos();

        // clamp position to visible bounds
        camera_pos.rx() = qBound<float>(0, camera_pos.x(), qMax<float>(0, pixmap.width() - width()));
        camera_pos.ry() = qBound<float>(0, camera_pos.y(), qMax<float>(0, pixmap.height() - height()));

        // do not forget to call paint event on update!
        repaint();
    }

    event->accept();
}

void TileWidget::wheelEvent(QWheelEvent* event)
{
    // TODO: process wheel event

    // example how to get wheel delta:
    // const int num_steps = event->angleDelta().y() / 8 / 15;
    // std::cout << "wheel event, num_steps = " << num_steps << std::endl;

    event->accept();
}

