#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPushButton *button_array[] = {
      ui->pushButton_num0, ui->pushButton_num1,   ui->pushButton_num2,
      ui->pushButton_num3, ui->pushButton_num4,   ui->pushButton_num5,
      ui->pushButton_num6, ui->pushButton_num7,   ui->pushButton_num8,
      ui->pushButton_num9, ui->pushButton_lbrace, ui->pushButton_rbrace,
      ui->pushButton_pow,  ui->pushButton_mod,    ui->pushButton_div,
      ui->pushButton_mul,  ui->pushButton_minus,  ui->pushButton_plus,
      ui->pushButton_sin,  ui->pushButton_asin,   ui->pushButton_cos,
      ui->pushButton_acos, ui->pushButton_tan,    ui->pushButton_atan,
      ui->pushButton_ln,   ui->pushButton_log,    ui->pushButton_sqrt,
      ui->pushButton_dot};

  for (auto button : button_array) {
    connect(button, SIGNAL(clicked()), SLOT(AddToString()));
  }

  ui->widget_graph->xAxis->setRange(-5, 5);
  ui->widget_graph->yAxis->setRange(-5, 5);
}

MainWindow::~MainWindow() { delete ui; }

// Arithmetic
void MainWindow::AddToString() {
  QPushButton *btn_current = (QPushButton *)sender();
  std::string expression(s21::Controller::Concat(
      ui->lineEdit_expression_arith->text().toStdString(),
      btn_current->text().toStdString()));
  ui->lineEdit_expression_arith->setText(QString::fromStdString(expression));
}

void MainWindow::on_pushButtonC_clicked() {
  ui->lineEdit_expression_arith->setText("0");
}

void MainWindow::on_pushButton_del_clicked() {
  std::string expression = s21::Controller::Erase(
      ui->lineEdit_expression_arith->text().toStdString());
  ui->lineEdit_expression_arith->setText(QString::fromStdString(expression));
}

void MainWindow::on_pushButton_equal_clicked() {
  std::pair<std::string, bool> expr_flag = s21::Controller::ArithmeticProcess(
      ui->lineEdit_expression_arith->text().toStdString(),
      ui->lineEdit_x_Arith->text().toDouble());
  if (expr_flag.second) {
    ui->lineEdit_expression_arith->setText(
        QString::fromStdString(expr_flag.first));
  } else {
    ui->lineEdit_expression_arith->setText("Incorrect expression");
  }
}

// Credit
void MainWindow::on_pushButton_Calculate_clicked() {
  std::string amount = ui->lineEdit_amount->text().toStdString();
  std::string term = ui->lineEdit_term->text().toStdString();
  std::string rate = ui->lineEdit_rate->text().toStdString();

  s21::CreditInputData credit_input_data = {amount, term, is_years_credit, rate,
                                            is_differentiated};

  s21::CreditInfo credit_info =
      s21::Controller::CreditProcess(credit_input_data);

  ui->label_monthly_payment->setText(
      QString::number(credit_info.monthly_payment));
  ui->label_overpayment->setText(QString::number(credit_info.overpayment));
  ui->label_total_payment->setText(QString::number(credit_info.total_payment));
}

// Deposit

void MainWindow::on_pushButton_calculate_clicked() {
  s21::DepositInputData deposit_input_data = {
      ui->lineEdit_dep_amount->text().toStdString(),
      ui->lineEdit_dep_term->text().toStdString(),
      is_years_deposit,
      ui->lineEdit_dep_rate->text().toStdString(),
      ui->lineEdit_dep_tax_rate->text().toStdString(),
      ui->comboBox_periodicity->currentIndex(),
      ui->checkBox_capitalization->isChecked()};

  s21::DepositInfo deposit_info =
      s21::Controller::DepositProcess(deposit_input_data);

  ui->label_acc_interest->setText(
      QString::number(deposit_info.accrued_interest));
  ui->label_tax_amount->setText(QString::number(deposit_info.tax_amount));
  ui->label_deposit_amount->setText(
      QString::number(deposit_info.deposit_amount));
}

// Graph
void MainWindow::on_pushButton_graph_clicked() {
  s21::GraphData graph_data = {
      ui->lineEdit_expressionGraph->text().toStdString(),
      ui->lineEdit_interval_x1->text().toDouble(),
      ui->lineEdit_interval_x2->text().toDouble(),
      ui->lineEdit_interval_y1->text().toDouble(),
      ui->lineEdit_interval_y2->text().toDouble(),
      ui->checkBox_x_pi->isChecked(),
      ui->checkBox_y_pi->isChecked()};

  s21::Controller::FillVectors(graph_data);
  QVector<double> x =
      QVector<double>(graph_data.xAxis.begin(), graph_data.xAxis.end());
  QVector<double> y =
      QVector<double>(graph_data.yAxis.begin(), graph_data.yAxis.end());
  GraphProcess(graph_data);
  ui->widget_graph->graph(0)->setData(x, y);
  ui->widget_graph->replot();
  x.clear();
  y.clear();
}

void MainWindow::GraphProcess(s21::GraphData &graph_data) {
  ui->widget_graph->clearGraphs();
  ui->widget_graph->xAxis->setRange(graph_data.x1, graph_data.x2);
  ui->widget_graph->yAxis->setRange(graph_data.y1, graph_data.y2);
  ui->widget_graph->addGraph();
  ui->widget_graph->graph(0)->data().clear();
  ui->widget_graph->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget_graph->graph(0)->setPen(QColor(40, 40, 230, 255));
  ui->widget_graph->graph(0)->setBrush(QColor(210, 210, 0, 255));
  ui->widget_graph->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCross, 1));
}

// Style
void MainWindow::SwapStyle(QPushButton *button1, QPushButton *button2) {
  QString temp = button1->styleSheet();
  button1->setStyleSheet(button2->styleSheet());
  button2->setStyleSheet(temp);
}

void MainWindow::on_pushButton_diff_clicked() {
  if (!is_differentiated) {
    is_differentiated = true;
    SwapStyle(ui->pushButton_diff, ui->pushButton_annuity);
  }
}

void MainWindow::on_pushButton_annuity_clicked() {
  if (is_differentiated) {
    is_differentiated = false;
    SwapStyle(ui->pushButton_annuity, ui->pushButton_diff);
  }
}

void MainWindow::on_pushButton_years_clicked() {
  if (!is_years_credit) {
    SwapStyle(ui->pushButton_years, ui->pushButton_months);
    is_years_credit = true;
  }
}

void MainWindow::on_pushButton_months_clicked() {
  if (is_years_credit) {
    SwapStyle(ui->pushButton_months, ui->pushButton_years);
    is_years_credit = false;
  }
}

void MainWindow::on_pushButton_dep_years_clicked() {
  if (!is_years_deposit) {
    is_years_deposit = true;
    SwapStyle(ui->pushButton_dep_years, ui->pushButton_dep_months);
  }
}

void MainWindow::on_pushButton_dep_months_clicked() {
  if (is_years_deposit) {
    is_years_deposit = false;
    SwapStyle(ui->pushButton_dep_months, ui->pushButton_dep_years);
  }
}

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("SmartCalc");
  w.show();
  return a.exec();
}