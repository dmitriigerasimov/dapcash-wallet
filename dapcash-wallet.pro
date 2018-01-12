#-------------------------------------------------
#
# Project created by QtCreator 2018-01-12T09:45:53
#
#-------------------------------------------------
include(./libdap-qt-ui/libdap-qt-ui.pri)



QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




TARGET = dapcash-wallet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DapChainPointClient.cpp \
    screens/DapUiScreenDashboard.cpp \
    widgets/DapUiWidgetChainBallance.cpp \
    widgets/DapUiWidgetChainTransctions.cpp \
    widgets/DapUiWidgetChainBlockExplorer.cpp \
    widgets/DapUiWidgetChainOperations.cpp \
    widgets/DapUiWidgetChainNodeLogs.cpp \
    dialogs/DapUiScreenDialogAbstract.cpp \
    widgets/DapUiWidgetAbstract.cpp

HEADERS += \
        MainWindow.h \
    DapChainPointClient.h \
    screens/DapUiScreenDashboard.h \
    widgets/DapUiWidgetChainBallance.h \
    widgets/DapUiWidgetChainTransctions.h \
    widgets/DapUiWidgetChainBlockExplorer.h \
    widgets/DapUiWidgetChainOperations.h \
    widgets/DapUiWidgetChainNodeLogs.h \
    dialogs/DapUiScreenDialogAbstract.h \
    widgets/DapUiWidgetAbstract.h

FORMS += \
    ui/DapUiScreenDashboard.ui
