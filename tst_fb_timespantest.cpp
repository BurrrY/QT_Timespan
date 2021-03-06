#include <QString>
#include <QtTest>

#include "fb_timespan.h"

class FB_TimespanTest : public QObject
{
    Q_OBJECT

public:
    FB_TimespanTest();

private Q_SLOTS:
    void constructors();
    void diffConstruct();
    void negDiffConstructors();
    void toString();
};

FB_TimespanTest::FB_TimespanTest()
{

}


void FB_TimespanTest::constructors()
{
    FB_Timespan ts(3, 34, 15);
    QCOMPARE(ts.getHours(), 3);
    QCOMPARE(ts.getMinutes(), 34);
    QCOMPARE(ts.getSeconds(), 15);

    FB_Timespan ts2(3, 90, 87);
    QCOMPARE(ts2.getHours(), 4);
    QCOMPARE(ts2.getMinutes(), 31);
    QCOMPARE(ts2.getSeconds(), 27);
    QCOMPARE(ts2.getMilliseconds(), 0);

    FB_Timespan ts3(-3, -90, -87);
    QCOMPARE(ts3.getHours(), -4);
    QCOMPARE(ts3.getMinutes(), -31);
    QCOMPARE(ts3.getSeconds(), -27);
    QCOMPARE(ts3.getMilliseconds(), 0);

    FB_Timespan ts4(0, 420, 0);
    QCOMPARE(ts4.getHours(), 7);
    QCOMPARE(ts4.getMinutes(), 0);
    QCOMPARE(ts4.getSeconds(), 0);
    QCOMPARE(ts4.getMilliseconds(), 0);

}

void FB_TimespanTest::diffConstruct()
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
    QCOMPARE(ts2.getSeconds(), 20);
    QCOMPARE(ts2.getHours(), 5);

    //============================
    // Constructor from 2 QDate

    QDate d1 = QDate::currentDate();
    QDate d2 = d1.addDays(25);


    FB_Timespan ts3(&d1, &d2);
    QCOMPARE(ts3.getDays(), 25);
    QCOMPARE(ts3.getHours(),0);


}


void FB_TimespanTest::negDiffConstructors()
{
    //============================
    // Constructor from 2 QDateTime
    QDateTime t = QDateTime::currentDateTime();
    QDateTime t2 = t.addDays(-2);

    FB_Timespan ts(&t, &t2);
    QCOMPARE(ts.getDays(), -2);

    //============================
    // Constructor from 2 QTime
    QTime time1 = QTime::fromString("12:45");
    QTime time2 = time1.addSecs(-20);
    time2 = time2.addSecs(-60*60*5);

    FB_Timespan ts2(&time1, &time2);
    QCOMPARE(ts2.getSeconds(), -20);
    QCOMPARE(ts2.getHours(), -5);

    //============================
    // Constructor from 2 QDate

    QDate d1 = QDate::currentDate();
    QDate d2 = d1.addDays(-25);


    FB_Timespan ts3(&d1, &d2);
    QCOMPARE(ts3.getDays(), -25);
    QCOMPARE(ts3.getHours(),-0);
}


void FB_TimespanTest::toString()
{
    FB_Timespan ts(3, 34, 15);
    FB_Timespan ts2(3, 90, 87);
    FB_Timespan ts3(-3, -90, -87);
    FB_Timespan ts4(0, 420, 0);

    QCOMPARE(ts.toString("hh:mm"), QString("03:34"));
    QCOMPARE(ts.toString("h:mm:ss"), QString("3:34:15"));



    /*
    QCOMPARE(ts.getHours(), 3);
    QCOMPARE(ts.getMinutes(), 34);
    QCOMPARE(ts.getSeconds(), 15);

    QCOMPARE(ts2.getHours(), 4);
    QCOMPARE(ts2.getMinutes(), 31);
    QCOMPARE(ts2.getSeconds(), 27);
    QCOMPARE(ts2.getMilliseconds(), 0);

    QCOMPARE(ts3.getHours(), -4);
    QCOMPARE(ts3.getMinutes(), -31);
    QCOMPARE(ts3.getSeconds(), -27);
    QCOMPARE(ts3.getMilliseconds(), 0);

    QCOMPARE(ts4.getHours(), 7);
    QCOMPARE(ts4.getMinutes(), 0);
    QCOMPARE(ts4.getSeconds(), 0);
    QCOMPARE(ts4.getMilliseconds(), 0);
    */
}

QTEST_APPLESS_MAIN(FB_TimespanTest)

#include "tst_fb_timespantest.moc"
