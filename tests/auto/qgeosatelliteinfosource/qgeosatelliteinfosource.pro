TEMPLATE = app
CONFIG+=testcase
TARGET=tst_qgeosatelliteinfosource

SOURCES += tst_qgeosatelliteinfosource.cpp \
            testqgeosatelliteinfosource.cpp \
            ../qgeocoordinate/qlocationtestutils.cpp

HEADERS += testqgeosatelliteinfosource_p.h \
            ../qgeocoordinate/qlocationtestutils_p.h

QT += location testlib

contains(config_test_jsondb, yes): contains(config_test_mtcore, yes) {
    DEFINES += NPE_BACKEND
}
