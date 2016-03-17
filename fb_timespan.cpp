#include "fb_timespan.h"

#include <QDebug>

FB_Timespan::FB_Timespan()
{

}

FB_Timespan::FB_Timespan(QDateTime *a, QDateTime *b)
{
    diff = b->toMSecsSinceEpoch() - a->toMSecsSinceEpoch();
    fromMSecs(diff);
}

FB_Timespan::FB_Timespan(QDate *a, QDate *b)
{
    diff = (b->toJulianDay() - a->toJulianDay()) * MSECS_DAY;
    fromMSecs(diff);
}

FB_Timespan::FB_Timespan(QTime *a, QTime *b)
{
    diff = b->msecsSinceStartOfDay() - a->msecsSinceStartOfDay();
    fromMSecs(diff);
}

void FB_Timespan::fromMSecs(qint64 value) {
    days = hours = mins = secs = msecs = 0;

    if(value >= MSECS_DAY)
    {
        days = value/MSECS_DAY;
        value -= days * MSECS_DAY;
    }

    if(value > MSECS_HOUR)
    {
        hours = value/MSECS_HOUR;
        value -= hours * MSECS_HOUR;
    }

    if(value > MSECS_MIN)
    {
        mins = value/MSECS_MIN;
        value -= mins * MSECS_MIN;
    }

    if(value > MSECS_SEC)
    {
        secs = value/MSECS_SEC;
        value -= secs * MSECS_SEC;
    }

    msecs = value;

}

void FB_Timespan::add(int days, int hours, int minutes, int seconds, int mSeconds) {
    this->days += days;
    this->hours += hours;
    this->mins += minutes;
    this->secs += seconds;
    this->msecs += mSeconds;
}

QString FB_Timespan::toString(QString format) {


}

int FB_Timespan::getMsecs() const
{
    return msecs;
}

void FB_Timespan::setMsecs(int value)
{
    msecs = value;
}

int FB_Timespan::getSecs() const
{
    return secs;
}

void FB_Timespan::setSecs(int value)
{
    secs = value;
}

int FB_Timespan::getMins() const
{
    return mins;
}

void FB_Timespan::setMins(int value)
{
    mins = value;
}

int FB_Timespan::getHours() const
{
    return hours;
}

void FB_Timespan::setHours(int value)
{
    hours = value;
}

int FB_Timespan::getDays() const
{
    return days;
}

void FB_Timespan::setDays(int value)
{
    days = value;
}
