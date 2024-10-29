#include "datecalendarwidget.h"
#include <QFont>
#include <QDate>

DateCalendarWidget::DateCalendarWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    updateDateLabel();
}

void DateCalendarWidget::setupUI()
{
    dateLabel = new QLabel(this);
    dateLabel->setAlignment(Qt::AlignCenter);
    dateLabel->setFont(QFont("Arial", 16, QFont::Bold));

    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setGridVisible(true);

    calendarWidget->setStyleSheet("QCalendarWidget { color: #333; }");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);
    layout->addWidget(calendarWidget);
    setLayout(layout);

    connect(calendarWidget, &QCalendarWidget::currentPageChanged,
            this, &DateCalendarWidget::updateDateLabel);
}


void DateCalendarWidget::updateDateLabel()
{
    QDate currentDate = calendarWidget->selectedDate();
    dateLabel->setText(currentDate.toString("dddd, d MMMM, yyyy"));
}

