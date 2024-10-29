#pragma once

#include <QWidget>
#include <QLabel>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QDate>

class DateCalendarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DateCalendarWidget(QWidget *parent = nullptr);

private:
    QLabel *dateLabel;
    QCalendarWidget *calendarWidget;

    void setupUI();
    void updateDateLabel();
};
