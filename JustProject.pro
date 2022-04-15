# Файл проекта QT, тут сидят основные настройки проекта.

# Используемые модули QT
QT       += core gui widgets

# Версия плюсов
CONFIG += c++20

# Исполняемые файлы проекта
SOURCES += \
    main.cpp \
    src/mainwindow.cpp

# Заголовочные файлы проекта
HEADERS += \
    src/mainwindow.h

# Формы, используемые в проекте
FORMS += \
    src/mainwindow.ui

# Стандартные правила сборки (автоматическая генерация)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Файлы ресурсов (там, например хранится лого проекта и тд)
RESOURCES += \
    src/resouces/qrc.qrc
