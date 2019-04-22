#include <QmlNet/qml/NetTestHelper.h>
#include <QQmlComponent>
#include <QDebug>

TestQObject::TestQObject()
    : QObject(nullptr),
    _writeOnly(0),
    _readAndWrite(0),
    _propWithSignal(0)
{

}

TestQObject::~TestQObject()
{

}

int TestQObject::getReadOnly()
{
    return 3;
}

void TestQObject::setWriteOnly(int value)
{
    _writeOnly = value;
}

int TestQObject::getReadAndWrite()
{
    return _readAndWrite;
}

void TestQObject::setReadAndWrite(int value)
{
    _readAndWrite = value;
}

int TestQObject::getPropWithSignal()
{
    return _propWithSignal;
}

void TestQObject::setPropWithSignal(int value)
{
    if(value == _propWithSignal) {
        return;
    }
    _propWithSignal = value;
    emit propWithSignalChanged(value);
}

QVariant TestQObject::getVariantProperty()
{
    return _variantValue;
}

void TestQObject::setVariantProperty(QVariant value)
{
    _variantValue = value;
}

void TestQObject::testSlot()
{
    emit testSignal();
}

void TestQObject::testSlotWithArg(int arg)
{
    emit testSignalWithArg(arg);
}

QVariant TestQObject::testVariantReturn()
{
    return getVariantProperty();
}

bool TestQObject::testSlotBool(bool value)
{
    emit testSignalBool(value);
    return value;
}

QChar TestQObject::testSlotChar(QChar value)
{
    emit testSignalChar(value);
    return value;
}

int TestQObject::testSlotInt(int value)
{
    emit testSignalInt(value);
    return value;
}

uint TestQObject::testSlotUInt(uint value)
{
    emit testSignalUInt(value);
    return value;
}

long TestQObject::testSlotLong(long value)
{
    emit testSignalLong(value);
    return value;
}

ulong TestQObject::testSlotULong(ulong value)
{
    emit testSignalULong(value);
    return value;
}

float TestQObject::testSlotFloat(float value)
{
    emit testSignalFloat(value);
    return value;
}

double TestQObject::testSlotDouble(double value)
{
    emit testSignalDouble(value);
    return value;
}

QString TestQObject::testSlotString(QString value)
{
    emit testSignalString(value);
    return value;
}

QDateTime TestQObject::testSlotDateTime(QDateTime value)
{
    emit testSignalDateTime(value);
    return value;
}

QObject* TestQObject::testSlotQObject(QObject* value)
{
    emit testSignalQObject(value);
    return value;
}

qint32 TestQObject::testSlotQInt32(qint32 value)
{
    emit testSignalQInt32(value);
    return value;
}

quint32 TestQObject::testSlotQUInt32(quint32 value)
{
    emit testSignalQUInt32(value);
    return value;
}

qint64 TestQObject::testSlotQInt64(qint64 value)
{
    emit testSignalQInt64(value);
    return value;
}

quint64 TestQObject::testSlotQUInt64(quint64 value)
{
    emit testSignalQUInt64(value);
    return value;
}

extern "C" {

Q_DECL_EXPORT void net_test_helper_runQml(QQmlApplicationEngineContainer* qmlEngineContainer, LPWSTR qml) {
    QQmlComponent component(qmlEngineContainer->qmlEngine);
    QString qmlString = QString::fromUtf16(static_cast<const char16_t*>(qml));
    component.setData(qmlString.toUtf8(), QUrl());

    QObject *object = component.create();

    if(object == nullptr) {
        qWarning() << "Couldn't create qml object.";
        return;
    }

    QSharedPointer<TestQObject> testQObject = QSharedPointer<TestQObject>(new TestQObject());
    object->setProperty("testQObject", QVariant::fromValue(testQObject.data()));
    QMetaObject::invokeMethod(object, "runTest");

    delete object;
}

}
