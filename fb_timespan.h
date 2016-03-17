#ifndef FB_TIMESPAN_H
#define FB_TIMESPAN_H

#include <QDateTime>

#define MSECS_MSEC 1
#define MSECS_SEC (MSECS_MSEC * 1000)
#define MSECS_MIN (MSECS_SEC * 60)
#define MSECS_HOUR (MSECS_MIN * 60)
#define MSECS_DAY (MSECS_HOUR * 24)
#define MSECS_WEEK (MSECS_DAY * 7)

class FB_Timespan
{
public:
    FB_Timespan();
    FB_Timespan(QDateTime *a, QDateTime *b);
    FB_Timespan(QDate *a, QDate *b);
    FB_Timespan(QTime *a, QTime *b);
    void fromMSecs(qint64 msecs);
    void add(int days, int hours, int minutes, int seconds, int mSeconds);
    QString toString(QString format);
    int getMsecs() const;
    void setMsecs(int value);

    int getSecs() const;
    void setSecs(int value);

    int getMins() const;
    void setMins(int value);

    int getHours() const;
    void setHours(int value);

    int getDays() const;
    void setDays(int value);

private:
    int msecs;
    int secs;
    int mins;
    int hours;
    int days;
    qint64 diff;
};

#endif // FB_TIMESPAN_H
