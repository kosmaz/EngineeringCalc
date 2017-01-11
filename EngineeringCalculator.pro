TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
TARGET = EngineeringCalculator
CONFIG += c++11

HEADERS += \
    src/Basic_Calculations.h \
    src/Engineer.h \
    src/Integration.h \
    src/Math.h \
    src/Parser.h

SOURCES += \
    src/Basic_Calculations.cpp \
    src/Engineer.cpp \
    src/Integration.cpp \
    src/main.cpp \
    src/Parser.cpp


