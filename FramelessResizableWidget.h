#ifndef FRAMELESSRESIZABLEWIDGET_H
#define FRAMELESSRESIZABLEWIDGET_H

#include <QWidget>

//A frameless top-level widget that can be resized by dragging near its edges
class FramelessResizableWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit FramelessResizableWidget(QWidget *parent = nullptr);

  protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

  private:
    //Thickness, in pixels, of the invisible border used for resizing
    static constexpr int kResizeBorderWidth = 8;

    [[nodiscard]] Qt::Edges edgesNearPoint(const QPoint &pos) const;
};

#endif // FRAMELESSRESIZABLEWIDGET_H
