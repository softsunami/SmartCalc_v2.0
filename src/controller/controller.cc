#include "controller.h"

namespace s21 {
std::string Controller::Concat(const std::string& expression,
                               const std::string& input) {
  std::string result;
  if (expression == "0" && input != ".") {
    result = input;
  } else {
    result = expression + input;
  }

  return result;
}

std::pair<std::string, bool> Controller::ArithmeticProcess(
    const std::string& expression, double x) {
  s21::ArithmeticCalc calc;
  double value = calc.Calculate(expression, x);
  std::string result = std::to_string(value);
  result = result.erase(result.find_last_not_of('0') + 1, std::string::npos);
  if (result.back() == '.') result.pop_back();

  std::pair<std::string, bool> expr_flag = {result, calc.GetStatus()};

  return expr_flag;
}
std::string Controller::Erase(const std::string& expression) {
  std::string result(expression);

  if (expression.length() <= 1 || expression == "Incorrect expression") {
    result = "0";
  } else {
    result.pop_back();
  }

  return result;
}

CreditInfo Controller::CreditProcess(
    const struct CreditInputData& credit_input_data) {
  bool flag = ValidateData({credit_input_data.amount, credit_input_data.term,
                            credit_input_data.rate});

  CreditInfo credit_info = {};

  if (flag) {
    s21::FinanceCalc finance_calc;
    finance_calc.SetCreditInfo(credit_input_data);
    if (credit_input_data.is_differentiated) {
      credit_info = finance_calc.CalculateCreditDiff();
    } else {
      credit_info = finance_calc.CalculateCreditAnnuity();
    }
  }

  return credit_info;
}

DepositInfo Controller::DepositProcess(
    const struct DepositInputData& deposit_input_data) {
  bool flag =
      ValidateData({deposit_input_data.amount, deposit_input_data.term,
                    deposit_input_data.rate, deposit_input_data.tax_rate});

  DepositInfo deposit_info = {};

  if (flag) {
    s21::FinanceCalc finance_calc;

    finance_calc.SetDepositInfo(deposit_input_data);

    if (deposit_input_data.capitalization) {
      deposit_info = finance_calc.CalculateDepositCapitalization();
    } else {
      deposit_info = finance_calc.CalculateDepositSimple();
    }
  }

  return deposit_info;
}

bool Controller::ValidateData(const std::vector<std::string>& values) {
  bool flag = true;
  for (const std::string& s : values) {
    if (!s21::Validator::IsNumber(s)) flag = false;
  }
  return flag;
}

// Graph

void Controller::FillVectors(struct GraphData& graph_data) {
  s21::Graph graph(graph_data);
  if (graph.IsCorrectData()) {
    graph.FillVectors();
  }
  graph_data = graph.GetData();
}
}  // namespace s21
