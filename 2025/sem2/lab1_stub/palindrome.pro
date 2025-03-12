TEMPLATE = app

QT += widgets

HEADERS = \
          src/PalindromeWidget.h

SOURCES = \
           src/main.cpp \
           src/PalindromeWidget.cpp

#
# Qt internals
#

CONFIG += c++14

# .o files path
OBJECTS_DIR = tmp/obj

# moc files path
MOC_DIR = tmp/moc

# binary path
DESTDIR = .

