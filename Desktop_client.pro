QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountarea.cpp \
    community.cpp \
    editprofile.cpp \
    functions.cpp \
    library.cpp \
    loginwindow.cpp \
    main.cpp \
    mainapplication.cpp \
    mainwindow.cpp \
    registrationwindow.cpp \
    registrationwindowfinal.cpp \
    settings.cpp \
    store.cpp \
    storeitem.cpp \
    support.cpp \
    test.cpp \
    useraccount.cpp \
    wallet.cpp

HEADERS += \
    accountarea.h \
    community.h \
    editprofile.h \
    functions.h \
    library.h \
    loginwindow.h \
    mainapplication.h \
    mainwindow.h \
    registrationwindow.h \
    registrationwindowfinal.h \
    settings.h \
    store.h \
    storeitem.h \
    support.h \
    test.h \
    useraccount.h \
    wallet.h

FORMS += \
    accountarea.ui \
    community.ui \
    editprofile.ui \
    library.ui \
    loginwindow.ui \
    mainwindow.ui \
    registrationwindow.ui \
    registrationwindowfinal.ui \
    settings.ui \
    store.ui \
    storeitem.ui \
    support.ui \
    wallet.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc

DISTFILES +=
