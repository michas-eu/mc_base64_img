#-------------------------------------------------
#
# Project created by QtCreator 2013-12-23T16:51:42
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Base64Img
TEMPLATE = app


SOURCES += main.cxx\
        mainwindow.cxx\
	b64_encoder.cxx \
	b64_decoder.cxx

HEADERS  += mainwindow.hxx\
	b64_encoder.hxx \
	b64_decoder.hxx

FORMS    += mainwindow.ui
