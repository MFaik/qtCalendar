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
    // Create a label to display the current date
    dateLabel = new QLabel(this);
    dateLabel->setAlignment(Qt::AlignCenter);
    dateLabel->setFont(QFont("Arial", 16, QFont::Bold));

    // Create the calendar widget
    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setGridVisible(true);

    // Customize calendar appearance
    calendarWidget->setStyleSheet("QCalendarWidget { color: #333; }");

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);
    layout->addWidget(calendarWidget);
    setLayout(layout);

    // Connect signal to update the date label when the date changes
    connect(calendarWidget, &QCalendarWidget::currentPageChanged,
            this, &DateCalendarWidget::updateDateLabel);
}


void DateCalendarWidget::updateDateLabel()
{
    QDate currentDate = calendarWidget->selectedDate();
    dateLabel->setText(currentDate.toString("dddd, d MMMM, yyyy"));
}

