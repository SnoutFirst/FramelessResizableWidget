#include "FramelessResizableWidget.h"

#include <QMouseEvent>
#include <QWindow>

FramelessResizableWidget::FramelessResizableWidget(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setMouseTracking(true);
}

Qt::Edges FramelessResizableWidget::edgesNearPoint(const QPoint &pos) const
{
    Qt::Edges edges;

    if (pos.x() < kResizeBorderWidth)
    {
        edges |= Qt::LeftEdge;
    }
    else if (pos.x() >= width() - kResizeBorderWidth)
    {
        edges |= Qt::RightEdge;
    }

    if (pos.y() < kResizeBorderWidth)
    {
        edges |= Qt::TopEdge;
    }
    else if (pos.y() >= height() - kResizeBorderWidth)
    {
        edges |= Qt::BottomEdge;
    }

    return edges;
}

void FramelessResizableWidget::mousePressEvent(QMouseEvent *event)
{
    const Qt::Edges edges = edgesNearPoint(event->pos());

    if (event->button() == Qt::LeftButton && edges)
    {
        if (QWindow *handle = windowHandle())
        {
            handle->startSystemResize(edges);
        }

        event->accept();
        return;
    }

    QWidget::mousePressEvent(event);
}

void FramelessResizableWidget::mouseMoveEvent(QMouseEvent *event)
{
    const Qt::Edges edges = edgesNearPoint(event->pos());

    const bool left = edges & Qt::LeftEdge;
    const bool right = edges & Qt::RightEdge;
    const bool top = edges & Qt::TopEdge;
    const bool bottom = edges & Qt::BottomEdge;

    if ((left && top) || (right && bottom))
    {
        setCursor(Qt::SizeFDiagCursor);
    }
    else if ((right && top) || (left && bottom))
    {
        setCursor(Qt::SizeBDiagCursor);
    }
    else if (left || right)
    {
        setCursor(Qt::SizeHorCursor);
    }
    else if (top || bottom)
    {
        setCursor(Qt::SizeVerCursor);
    }
    else
    {
        unsetCursor();
    }

    QWidget::mouseMoveEvent(event);
}
