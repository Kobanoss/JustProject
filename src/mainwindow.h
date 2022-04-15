#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStringList>
#include <QStringListModel>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Конструктор/Деструктор класса окна
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Объект окна
    Ui::MainWindow *ui;

    // Объект, хранящий наши данные, является дочерним классом к QAbstractItemModel, согласно ТЗ
    QStringListModel* objectModel;

    // Функция по добавлению значения
    void addValue();

// Блок `слотов`, берут на себя работу по получению и обработке определенных event'ов
private slots:

    // Данный слот обрабатывает двойное нажатие на элемент нашего списка
    void on_listView_doubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
