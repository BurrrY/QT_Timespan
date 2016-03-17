#include <QString>
#include <QtTest>

#include "fb_timespan.h"

class FB_TimespanTest : public QObject
{
    Q_OBJECT

public:
    FB_TimespanTest();

private Q_SLOTS:
    void construct();
};

FB_TimespanTest::FB_TimespanTest()
{
}

void FB_TimespanTest::construct()
{
    //============================
    // Constructor from 2 QDateTime
    QDateTime t = QDateTime::currentDateTime();
    QDateTime t2 = t.addDays(2);

    FB_Timespan ts(&t, &t2);
    QCOMPARE(ts.getDays(), 2);

    //============================
    // Constructor from 2 QTime
    QTime time1 = QTime::fromString("12:45");
    QTime time2 = time1.addSecs(20);
    time2 = time2.addSecs(60*60*5);

    FB_Timespan ts2(&time1, &time2);
    QCOMPARE(ts2.getSecs(), 20);
    QCOMPARE(ts2.getHours(), 5);

    //============================
    // Constructor from 2 QDate

    QDate d1 = QDate::currentDate();
    QDate d2 = d1.addDays(25);


    FB_Timespan ts3(&d1, &d2);
    QCOMPARE(ts3.getDays(), 25);
    QCOMPARE(ts3.getHours(),0);
}

QTEST_APPLESS_MAIN(FB_TimespanTest)

#include "tst_fb_timespantest.moc"
