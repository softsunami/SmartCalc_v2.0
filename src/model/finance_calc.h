#ifndef SMARTCALC_SRC_MODEL_FINANCE_CALC_H
#define SMARTCALC_SRC_MODEL_FINANCE_CALC_H

#include <cmath>
#include <iostream>

namespace s21 {
enum periodicity {
  day = 365,
  week = 52,
  month = 12,
  quarter = 4,
  half_year = 2,
  year = 1
};

struct CreditInfo {
  double monthly_payment;
  double overpayment;
  double total_payment;
};

struct DepositInfo {
  double accrued_interest;
  double tax_amount;
  double deposit_amount;
};

struct CreditInputData {
  std::string amount;
  std::string term;
  bool is_years;
  std::string rate;
  bool is_differentiated;
};

struct DepositInputData {
  std::string amount;
  std::string term;
  bool is_years;
  std::string rate;
  std::string tax_rate;
  int periodicity;
  bool capitalization;
};
}  // namespace s21

namespace s21 {
class FinanceCalc {
 public:
  struct CreditInfo CalculateCreditAnnuity();
  struct CreditInfo CalculateCreditDiff();
  struct DepositInfo CalculateDepositSimple();
  struct DepositInfo CalculateDepositCapitalization();

  void SetCreditInfo(const struct CreditInputData& credit_input_data);
  void SetDepositInfo(const struct DepositInputData& deposit_input_data);

 private:
  double amount_{};
  int term_{};
  double rate_{}, tax_rate_{};
  int periodic_{};
  bool incorrect_value_{};

  CreditInfo credit_info_{};
  DepositInfo deposit_info_{};

  static double RoundTwoDigits_(double value);
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_FINANCE_CALC_H
