TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    tree_work.h \
    queue_work.h \
    p_error.h

SOURCES += main.c \
    tree_work.c \
    queue_work.c \
    p_error.c
