#include "FramelessResizableWidget.h"

#include <QApplication>
#include <QKeySequence>
#include <QShortcut>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FramelessResizableWidget widget;
    widget.resize(400, 300);
    widget.show();

    // Quitting is the application's business, not the widget's.
    QShortcut quitShortcut(QKeySequence(Qt::Key_Escape), &widget);
    QObject::connect(&quitShortcut, &QShortcut::activated, &app, &QApplication::quit);

    return app.exec();
}
