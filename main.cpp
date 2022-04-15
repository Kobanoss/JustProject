#include "./src/mainwindow.h"
#include <QApplication>

// Основная точка входа программы
int main(int argc, char *argv[]) {

    // Инициализируем объект приложения
    QApplication app(argc, argv);
    // Инициализируем класс основного окна
    MainWindow window;
    // Выводим данное окно
    window.show();
    // Возвращаем после выполнения код возврата приложения
    return app.exec();
}
