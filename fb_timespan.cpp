#include "fb_timespan.h"

#include <QDebug>

FB_Timespan::FB_Timespan()
{
    days = hours = mins = secs = msecs = 0;
}

FB_Timespan::FB_Timespan(qint64 msec)
{
    days = hours = mins = secs = msecs = 0;
    fromMSecs(msec);
}

FB_Timespan::FB_Timespan(int h, int m, int s)
{
    days = hours = mins = secs = msecs = 0;
    addHours(h);
    addMinutes(m);
    addSeconds(s);
}

FB_Timespan::FB_Timespan(int d, int h, int m, int s)
{
    days = hours = mins = secs = msecs = 0;
    addDays(d);
    addHours(h);
    addMinutes(m);
    addSeconds(s);
}

FB_Timespan::FB_Timespan(int d, int h, int m, int s, int ms)
{
    days = hours = mins = secs = msecs = 0;
    addDays(d);
    addHours(h);
    addMinutes(m);
    addSeconds(s);
    addMilliseconds(ms);
}

FB_Timespan::FB_Timespan(QDateTime *a, QDateTime *b)
{
    diff = b->toMSecsSinceEpoch() - a->toMSecsSinceEpoch();
    fromMSecs(diff);
}

FB_Timespan::FB_Timespan(QDate *a, QDate *b)
{
    hours = mins = secs = msecs = 0;
    days = (b->toJulianDay() - a->toJulianDay());
}

FB_Timespan::FB_Timespan(QTime *a, QTime *b)
{
    diff = b->msecsSinceStartOfDay() - a->msecsSinceStartOfDay();
    fromMSecs(diff);
}

void FB_Timespan::fromMSecs(qint64 value) {
    days = hours = mins = secs = msecs = 0;

    if(value >= MSECS_DAY || value <= -MSECS_DAY)
    {
        days = value/MSECS_DAY;
        value -= days * MSECS_DAY;
    }

    if(value > MSECS_HOUR || value <= -MSECS_HOUR)
    {
        hours = value/MSECS_HOUR;
        value -= hours * MSECS_HOUR;
    }

    if(value > MSECS_MIN || value <= -MSECS_MIN)
    {
        mins = value/MSECS_MIN;
        value -= mins * MSECS_MIN;
    }

    if(value > MSECS_SEC || value <= -MSECS_SEC)
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
    QString result = format;

    result.replace("hh", QString("%1").arg(days, 2, 10, QChar('0')));
    result.replace("h", QString::number(days));

    result.replace("hh", QString("%1").arg(hours, 2, 10, QChar('0')));
    result.replace("h", QString::number(hours));

    result.replace("mm", QString("%1").arg(mins, 2, 10, QChar('0')));
    result.replace("m", QString::number(mins));

    result.replace("ss", QString("%1").arg(secs, 2, 10, QChar('0')));
    result.replace("s", QString::number(secs));

    result.replace("zz", QString("%1").arg(msecs, 2, 10, QChar('0')));
    result.replace("z", QString::number(msecs));

    return result;
}

int FB_Timespan::getMilliseconds() const
{
    return msecs;
}

int FB_Timespan::getSeconds() const
{
    return secs;
}

int FB_Timespan::getMinutes() const
{
    return mins;
}

int FB_Timespan::getHours() const
{
    return hours;
}

int FB_Timespan::getDays() const
{
    return days;
}

void FB_Timespan::addMilliseconds(int value)
{
    while(value>=1000) {
        addSeconds(1);
        value -= 1000;
    }

    while(value<=-1000) {
        addSeconds(-1);
        value += 1000;
    }

    msecs += value;
}

void FB_Timespan::addSeconds(int value)
{
    while(value>=60) {
        addMinutes(1);
        value -= 60;
    }

    while(value<=-60) {
        addMinutes(-1);
        value += 60;
    }

    secs += value;
}

void FB_Timespan::addMinutes(int value)
{
    while(value>=60) {
        addHours(1);
        value -= 60;
    }
    while(value<=-60) {
        addHours(-1);
        value += 60;
    }

    mins += value;
}

void FB_Timespan::addHours(int value)
{
    while(value>=24) {
        addDays(1);
        value -= 24;
    }
    while(value<=-24) {
        addDays(-1);
        value += 24;
    }

    hours += value;
}


void FB_Timespan::addDays(int value)
{
    days += value;
}
