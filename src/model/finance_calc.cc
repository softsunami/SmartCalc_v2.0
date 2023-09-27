#include "finance_calc.h"

namespace s21 {

struct CreditInfo FinanceCalc::CalculateCreditAnnuity() {
  if (incorrect_value_) {
    credit_info_ = {0, 0, 0};
    return credit_info_;
  }

  double month_payment = 0, ratio = 0, i = 0;

  i = rate_ / 12.0 / 100.0;
  ratio = i * pow(1 + i, term_) / ((pow(1 + i, term_) - 1));
  month_payment = ratio * amount_;

  credit_info_.monthly_payment = RoundTwoDigits_(month_payment);
  credit_info_.overpayment = RoundTwoDigits_(month_payment * term_ - amount_);
  credit_info_.total_payment = RoundTwoDigits_(month_payment * term_);

  return credit_info_;
}

struct CreditInfo FinanceCalc::CalculateCreditDiff() {
  if (incorrect_value_) {
    credit_info_ = {0, 0, 0};
    return credit_info_;
  }

  double all_payments = 0;
  double term_remains = amount_;
  double average_payment = 0;

  for (int i = 0; i < term_; i++) {
    all_payments = amount_ / term_ + term_remains * rate_ / 100 / 12;
    average_payment += all_payments;
    term_remains = term_remains - amount_ / term_;
  }

  credit_info_.monthly_payment = RoundTwoDigits_(average_payment / term_);
  credit_info_.overpayment = RoundTwoDigits_(average_payment - amount_);
  credit_info_.total_payment = RoundTwoDigits_(average_payment);

  return credit_info_;
}

struct DepositInfo FinanceCalc::CalculateDepositSimple() {
  if (incorrect_value_) {
    deposit_info_ = {0, 0, 0};
    return deposit_info_;
  }

  double rate_per_month = rate_ / 12.0 / 100.0;
  double accrued_interest = amount_ * rate_per_month * term_;
  double tax = 75000;
  if (accrued_interest > tax) {
    tax = (accrued_interest - tax) * (tax_rate_ / 100.0);
  } else {
    tax = 0;
  }

  deposit_info_.accrued_interest = RoundTwoDigits_(accrued_interest - tax);
  deposit_info_.tax_amount = RoundTwoDigits_(tax);
  deposit_info_.deposit_amount = RoundTwoDigits_(amount_);

  return deposit_info_;
}

struct DepositInfo FinanceCalc::CalculateDepositCapitalization() {
  if (incorrect_value_) {
    deposit_info_ = {0, 0, 0};
    return deposit_info_;
  }

  double rate_per_year = rate_ / 100.0;
  double result_amount = 0;
  double accrued_interest;
  double tax = 75000;

  result_amount = amount_ * pow(1 + (rate_per_year / periodic_),
                                (int)floor(periodic_ * term_ / 12.0));
  accrued_interest = result_amount - amount_;

  if (accrued_interest > tax) {
    tax = (accrued_interest - tax) * (tax_rate_ / 100.0);
  } else {
    tax = 0;
  }
  deposit_info_.accrued_interest = RoundTwoDigits_(accrued_interest - tax);
  deposit_info_.tax_amount = RoundTwoDigits_(tax);
  deposit_info_.deposit_amount = RoundTwoDigits_(result_amount);

  return deposit_info_;
}

void FinanceCalc::SetCreditInfo(
    const struct CreditInputData& credit_input_data) {
  double amount = std::stod(credit_input_data.amount);
  int term = std::stoi(credit_input_data.term);
  double rate = std::stod(credit_input_data.rate);

  if (credit_input_data.is_years) term = term * 12;

  if (amount <= 0 || term <= 0 || rate <= 0)
    incorrect_value_ = true;
  else {
    amount_ = amount;
    term_ = term;
    rate_ = rate;
  }
}

void FinanceCalc::SetDepositInfo(
    const struct DepositInputData& deposit_input_data) {
  double amount = std::stod(deposit_input_data.amount);
  int term = std::stoi(deposit_input_data.term);
  double rate = std::stod(deposit_input_data.rate);
  double tax_rate = std::stod(deposit_input_data.tax_rate);

  if (deposit_input_data.is_years) term = term * 12;

  if (amount <= 0 || term <= 0 || rate <= 0 || tax_rate <= 0)
    incorrect_value_ = true;
  else {
    amount_ = amount;
    term_ = term;
    rate_ = rate;
    tax_rate_ = tax_rate;
  }

  if (deposit_input_data.periodicity == 0)
    periodic_ = day;
  else if (deposit_input_data.periodicity == 1)
    periodic_ = week;
  else if (deposit_input_data.periodicity == 2)
    periodic_ = month;
  else if (deposit_input_data.periodicity == 3)
    periodic_ = quarter;
  else if (deposit_input_data.periodicity == 4)
    periodic_ = half_year;
  else if (deposit_input_data.periodicity == 5)
    periodic_ = year;
}

double FinanceCalc::RoundTwoDigits_(double value) {
  return std::round(value * 100) / 100;
}
}  // namespace s21
