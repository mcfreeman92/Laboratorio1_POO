QT -= gui

#TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG += qt

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        ccarro.cpp \
        cempleado.cpp \
        ctaller.cpp \
        main.cpp

HEADERS += \
    ccarro.h \
    cempleado.h \
    constantes.h \
    ctaller.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
