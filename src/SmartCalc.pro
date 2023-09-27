QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/arithmetic_calc.cc \
    model/finance_calc.cc \
    model/validator.cc \
    model/graph.cc \
    view/mainwindow.cc \
    controller/controller.cc \
    model/qcustomplot.cc

HEADERS += \
    model/arithmetic_calc.h \
    model/finance_calc.h \
    model/validator.h \
    model/graph.h \
    view/mainwindow.h \
    controller/controller.h \
    model/qcustomplot.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
