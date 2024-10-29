#include <QApplication>
#include "datecalendarwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DateCalendarWidget widget;
    widget.setWindowTitle("Date and Calendar Widget");
    widget.resize(400, 300);
    widget.setWindowFlag(Qt::Dialog);
    widget.show();

    return app.exec();
}

