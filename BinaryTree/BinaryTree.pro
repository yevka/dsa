TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    test_runner.cxx \
    test_binary_tree.cxx

HEADERS += \
    catch.hpp \
    binary_tree.h
