TEMPLATE = app
QT = core
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

SOURCES += \
    algorithm/algorithmabs.cpp \
    algorithm/bublesortalgorithm.cpp \
    algorithm/selectionsortalgorithm.cpp \
    configuration.cpp \
    engine/carengine.cpp \
    engine/engine.cpp \
        main.cpp \
    model/carinformation.cpp \
    model/channel.cpp \
    model/channelmanager.cpp \
    model/controlspeedscreenuserchoice.cpp \
    model/gearscreenuserchoice.cpp \
    model/message.cpp \
    model/user.cpp \
    model/userchoice.cpp \
    model/usercommand.cpp \
    model/warningmessage.cpp \
    screen/carscreenmanager.cpp \
    screen/configlimitspeedscreen.cpp \
    screen/gearscreen.cpp \
    screen/screen.cpp \
    screen/screenmanager.cpp \
    screen/signinscreen.cpp \
    screen/speedcontrolscreen.cpp \
    vehicle/car.cpp \
    vehicle/vehicle.cpp


HEADERS += \
    algorithm/algorithmabs.h \
    algorithm/bublesortalgorithm.h \
    algorithm/selectionsortalgorithm.h \
    common.h \
    configuration.h \
    engine/carengine.h \
    engine/engine.h \
    model/carinformation.h \
    model/channel.h \
    model/channelmanager.h \
    model/controlspeedscreenuserchoice.h \
    model/gearscreenuserchoice.h \
    model/message.h \
    model/user.h \
    model/userchoice.h \
    model/usercommand.h \
    model/warningmessage.h \
    screen/carscreenmanager.h \
    screen/configlimitspeedscreen.h \
    screen/gearscreen.h \
    screen/screen.h \
    screen/screenmanager.h \
    screen/signinscreen.h \
    screen/speedcontrolscreen.h \
    vehicle/car.h \
    vehicle/vehicle.h
