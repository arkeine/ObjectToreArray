#include <QString>
#include <QtTest>
#include "../../objecttorearray.cpp"

/*============================================*/
//  DECLARATION
/*============================================*/

struct Data{
    int value;
};

class ObjectToreArrayTest : public QObject
{
    Q_OBJECT

public:
    ObjectToreArrayTest();

private Q_SLOTS:
    void testPrivateMethods();
    void accessCorner();
    void accessNegativeCorner();
    void accessMultipleCoord();

private:
    bool isEquals(ObjectToreArray<Data> o1, ObjectToreArray<Data> o2);
    ObjectToreArray<Data> getArrayData();
};

ObjectToreArrayTest::ObjectToreArrayTest()
{
}

/*============================================*/
//  TESTS CASES
/*============================================*/

void ObjectToreArrayTest::testPrivateMethods()
{
    ObjectToreArray<Data> o1 = getArrayData();
    ObjectToreArray<Data> o2 = getArrayData();

    QVERIFY(isEquals(o1,o2));
}

void ObjectToreArrayTest::accessCorner()
{
    ObjectToreArray<Data> o = getArrayData();

    QCOMPARE(o.get(0,0).value, 2);
    QCOMPARE(o.get(9,0).value, 11);
    QCOMPARE(o.get(0,9).value, 20);
    QCOMPARE(o.get(9,9).value, 110);
}

void ObjectToreArrayTest::accessNegativeCorner()
{
    ObjectToreArray<Data> o = getArrayData();

    QCOMPARE(o.get(10,10).value, 2);
    QCOMPARE(o.get(-1,10).value, 11);
    QCOMPARE(o.get(10,-1).value, 20);
    QCOMPARE(o.get(-1,-1).value, 110);
}

void ObjectToreArrayTest::accessMultipleCoord()
{
    ObjectToreArray<Data> o = getArrayData();

    QCOMPARE(o.get(100,100).value, 2);
    QCOMPARE(o.get(-11,100).value, 11);
    QCOMPARE(o.get(100,-11).value, 20);
    QCOMPARE(o.get(-11,-11).value, 110);
}

/*============================================*/
//  PRIVATE
/*============================================*/

bool ObjectToreArrayTest::isEquals(ObjectToreArray<Data> o1, ObjectToreArray<Data> o2)
{
    if(o1.height() != o1.height() || o1.width() != o2.width()) return false;

    for (int x = 0; x < o1.height(); ++x)
    {
        for (int y = 0; y < o1.width(); ++y)
        {
            if(o1.get(x,y).value != o2.get(x,y).value) return false;
        }
    }
    return true;
}

ObjectToreArray<Data> ObjectToreArrayTest::getArrayData()
{
    ObjectToreArray<Data> ota(10,10);

    for (int x = 1; x <= 10; ++x)
    {
        for (int y = 1; y <= 10; ++y)
        {
            Data d;
            d.value = x*y + y;
            ota.set(d, x-1, y-1);
        }
    }
    return ota;
}

QTEST_APPLESS_MAIN(ObjectToreArrayTest)

#include "tst_objecttorearraytest.moc"
