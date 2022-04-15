#include "mainwindow.h"
#include "ui_mainwindow.h"

// Конструктор класса окна
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    // Вызываем само окно
    ui->setupUi(this);

    // Устанавливаем связь, где источником является lineEdit(Строка ввода), а получателем текущий класс.
    // Условием срабатывания является получение от источника сигнала `returnPressed` (Нажатия Enter)
    // После срабатывания вызывается функция-слот `addValue` (Функция для добавления списка)
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::addValue);

    // Инициализируем модель
    objectModel = new QStringListModel(this);

    // И привязываем её к ListView (список)
    ui->listView->setModel(objectModel);

}

// Деструктор класса окна
MainWindow::~MainWindow() {
    delete objectModel;
    delete ui;
}

// Функция добавления значения (вызывается по получению Enter в строке ввода)
void MainWindow::addValue() {
    // Получаем значение с строки ввода
    auto data = ui->lineEdit->text();

    // Если отсуствует, то завершаем выполнение досрочно
    if (data == "")
            return;

    // Создаем потоковый объект хранения вводимых строк и присваиваем ему текущие данные в модели
    QStringList stream = objectModel->stringList();

    // Добавляем к текущим данным новую строчку
    stream << data;

    // Перезаписываем модель текущими данными
    objectModel->setStringList(stream);

    // Очищаем поле ввода
    ui->lineEdit->clear();

    // Важное замечание -> обновления самого списка не требуется, так как модель уже привязана к нему
}

// Слот обработки двойного нажатия на объект в списке
void MainWindow::on_listView_doubleClicked(const QModelIndex &index) {

    // Инициализируем MessageBox (Объект диалогового окна с сообщением)
    auto messageBox = new QMessageBox;

    // Выставляем различные стилистические настройки
    messageBox->setWindowFlags(Qt::WindowMinimizeButtonHint);
    messageBox->setStyleSheet("color:#f8f8f8;\nbackground-color:#181818;");
    messageBox->setWindowTitle(this->windowTitle());

    // Добавляем сообщение в диалоговое окно с вопросом про удаление элемента с конкретным значением
    messageBox->setText(QString("You want to delete element \"%1\"\?").arg(objectModel->data(index).toString()));

    // Устанавлием кнопки для выбора пользователя
    messageBox->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);

    // Делаем основное окно недоступным
    this->setEnabled(false);

    // Показываем диалоговое окно
    messageBox->show();


    // Устанавливаем связь с кнопкой `Yes`, при ёё нажатии выполняется lambda-выражение
    connect(messageBox, &QMessageBox::accepted,[this, messageBox, index]() {
        // Сожержимое выражения:
        // Удаляем необходимую строку
        objectModel->removeRow(index.row());

        // Закрываем диалоговое окно
        messageBox->close();

        // Делаем основное окно вновь доступным
        this->setEnabled(true);
    });

    // Устанавливаем связь с кнопкой `Cancel`, при ёё нажатии выполняется lambda-выражение
    connect(messageBox, &QMessageBox::rejected, [this, messageBox]() {
        // Сожержимое выражения:
        // Закрываем диалоговое окно
        messageBox->close();

        // Делаем основное окно вновь доступным
        this->setEnabled(true);
    });

}

