TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        chidrenclass2.cpp \
        childrenclass.cpp \
        loop.cpp \
        main.cpp \
        parentclass.cpp \
        pollingconfiguration.cpp \
        pollingevent.cpp \
        pollinglogichandler.cpp \
        pollingworker.cpp \
        task.cpp

HEADERS += \
    chidrenclass2.h \
    childrenclass.h \
    loop.h \
    parentclass.h \
    pollingconfiguration.h \
    pollingevent.h \
    pollinglogichandler.h \
    pollingworker.h \
    task.h
