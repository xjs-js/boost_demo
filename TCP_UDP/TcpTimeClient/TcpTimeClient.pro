QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tcpclient.cpp

HEADERS += \
    mainwindow.h \
    tcpclient.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += /usr/local/Cellar/boost/1.69.0_2/include

LIBS += -L/usr/local/Cellar/boost/1.69.0_2/lib \
        -lboost_chrono    \
        -lboost_container \
        -lboost_contract \
        -lboost_coroutine \
        -lboost_date_time \
        -lboost_exception \
        -lboost_filesystem \
        -lboost_graph \
        -lboost_iostreams \
        -lboost_log \
        -lboost_math_c99 \
        -lboost_math_c99f \
        -lboost_math_tr1 \
        -lboost_math_tr1f \
        -lboost_math_tr1l \
        -lboost_prg_exec_monitor \
        -lboost_program_options \
        -lboost_random \
        -lboost_regex \
        -lboost_serialization \
        -lboost_stacktrace_addr2line \
        -lboost_stacktrace_basic \
        -lboost_stacktrace_noop \
        -lboost_system \
        -lboost_test_exec_monitor \
        -lboost_test_exec_monitor \
        -lboost_thread-mt \
        -lboost_timer \
        -lboost_type_erasure \
        -lboost_unit_test_framework \
        -lboost_wave-mt \
        -lboost_wserialization

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
