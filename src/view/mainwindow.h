#ifndef SMARTCALC_SRC_VIEW_MAINWINDOW_H
#define SMARTCALC_SRC_VIEW_MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void AddToString();
  void on_pushButtonC_clicked();
  void on_pushButton_del_clicked();
  void on_pushButton_equal_clicked();

  void on_pushButton_calculate_clicked();
  void on_pushButton_graph_clicked();
  void GraphProcess(s21::GraphData &graph_data);

  void on_pushButton_Calculate_clicked();

  void SwapStyle(QPushButton *button1, QPushButton *button2);
  void on_pushButton_annuity_clicked();
  void on_pushButton_diff_clicked();
  void on_pushButton_years_clicked();
  void on_pushButton_months_clicked();
  void on_pushButton_dep_years_clicked();
  void on_pushButton_dep_months_clicked();

 private:
  Ui::MainWindow *ui;
  bool is_years_credit{};
  bool is_differentiated{};
  bool is_years_deposit{};
};
#endif  // SMARTCALC_SRC_VIEW_MAINWINDOW_H
