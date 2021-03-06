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

INCLUDEPATH += src/widgets


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

!defined(BRAND, var)
{
    BRAND = DiveVPN
}
DEFINES += DAP_BRAND=\\\"$$BRAND\\\"
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/DapChainPointClient.cpp \
    src/screens/DapUiScreenDashboard.cpp \
    src/widgets/DapUiWidgetChainBallance.cpp \
    src/widgets/DapUiWidgetChainTransctions.cpp \
    src/widgets/DapUiWidgetChainBlockExplorer.cpp \
    src/widgets/DapUiWidgetChainOperations.cpp \
    src/widgets/DapUiWidgetChainNodeLogs.cpp \
    src/dialogs/DapUiScreenDialogAbstract.cpp \
    src/widgets/DapUiWidgetAbstract.cpp \
    src/dialogs/DapUiScreenDialogTemplate.cpp \
    src/TreeItem.cpp \
    src/TreeModel.cpp

HEADERS += \
        src/MainWindow.h \
    src/DapChainPointClient.h \
    src/screens/DapUiScreenDashboard.h \
    src/widgets/DapUiWidgetChainBallance.h \
    src/widgets/DapUiWidgetChainTransctions.h \
    src/widgets/DapUiWidgetChainBlockExplorer.h \
    src/widgets/DapUiWidgetChainOperations.h \
    src/widgets/DapUiWidgetChainNodeLogs.h \
    src/dialogs/DapUiScreenDialogAbstract.h \
    src/widgets/DapUiWidgetAbstract.h \
    src/dialogs/DapUiScreenDialogTemplate.h \
    src/TreeItem.h \
    src/TreeModel.h

FORMS += \
    ui/DapUiScreenDashboard.ui \
    ui/DapUiWidgetChainOperations.ui \
    ui/DapUiWidgetChainBalance.ui \
    ui/DapUiWidgetChainTransctions.ui \
    ui/DapUiChainNodeLogs.ui \
    ui/DapUiWidgetChainBlockExplorer.ui \
    ui/DapUiScreenDialog.ui

RESOURCES += resources/main.qrc
