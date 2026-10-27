#include "FramelessResizableWidget.h"

#include <QApplication>
#include <QKeySequence>
#include <QPushButton>
#include <QShortcut>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FramelessResizableWidget widget;

    // The layout and its contents belong to the application, not to the widget.
    auto *layout = new QVBoxLayout;
    auto *button = new QPushButton(QStringLiteral("Click Here or Press Esc to Quit"));
    layout->addWidget(button);
    widget.setLayout(layout);

    QObject::connect(button, &QPushButton::clicked, &app, &QApplication::quit);

    // Quitting is the application's business, not the widget's.
    QShortcut quitShortcut(QKeySequence(Qt::Key_Escape), &widget);
    QObject::connect(&quitShortcut, &QShortcut::activated, &app, &QApplication::quit);

    widget.resize(400, 300);
    widget.show();

    return app.exec();
}
