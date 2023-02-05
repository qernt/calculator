#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_Dot_clicked();
    void on_pushButton_PlusMinus_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_Percent_clicked();
    void check_math_operation_buttons();
    void on_pushButton_Equal_clicked();
};

#endif // MAINWINDOW_H
