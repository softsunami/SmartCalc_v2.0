#include "tests.h"

TEST(Finance, Credit1) {
  s21::FinanceCalc finance_calc;
  s21::CreditInputData credit_input_data = {"100000", "21", false, "6", false};
  finance_calc.SetCreditInfo(credit_input_data);
  s21::CreditInfo result = finance_calc.CalculateCreditAnnuity();
  EXPECT_NEAR(result.monthly_payment, 5028, 5);
  EXPECT_NEAR(result.overpayment, 5591, 5);
  EXPECT_NEAR(result.total_payment, 105591, 5);
}

TEST(Finance, Credit2) {
  s21::FinanceCalc finance_calc;
  s21::CreditInputData credit_input_data = {"100000", "24", false, "7.5",
                                            false};
  finance_calc.SetCreditInfo(credit_input_data);
  s21::CreditInfo result = finance_calc.CalculateCreditAnnuity();
  EXPECT_NEAR(result.monthly_payment, 4499, 5);
  EXPECT_NEAR(result.overpayment, 7999, 5);
  EXPECT_NEAR(result.total_payment, 107999, 5);
}

TEST(Finance, Credit3) {
  s21::FinanceCalc finance_calc;
  s21::CreditInputData credit_input_data = {"100000", "21", false, "6", false};
  finance_calc.SetCreditInfo(credit_input_data);
  s21::CreditInfo result = finance_calc.CalculateCreditDiff();
  EXPECT_NEAR(result.monthly_payment, 5028, 5);
  EXPECT_NEAR(result.overpayment, 5500, 5);
  EXPECT_NEAR(result.total_payment, 105500, 5);
}

TEST(Finance, Deposit1) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "15", false, "5.5",
                                              "13",     0,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositSimple();
  EXPECT_NEAR(result.accrued_interest, 6892, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 100000, 50);
}

TEST(Finance, Deposit2) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "9", false, "65",
                                              "13",     0,   false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositSimple();
  EXPECT_NEAR(result.accrued_interest, 48716, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 100000, 50);
}

TEST(Finance, Deposit3) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     0,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 17349, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 117349, 50);
}

TEST(Finance, Deposit4) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     1,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 17336, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 117336, 50);
}

TEST(Finance, Deposit5) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     2,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 17288, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 117288, 50);
}

TEST(Finance, Deposit6) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     3,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 17165, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 117165, 50);
}

TEST(Finance, Deposit7) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     4,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 16985, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 116985, 50);
}

TEST(Finance, Deposit8) {
  s21::FinanceCalc finance_calc;
  s21::DepositInputData deposit_input_data = {"100000", "24", false, "8",
                                              "13",     5,    false};
  finance_calc.SetDepositInfo(deposit_input_data);
  s21::DepositInfo result = finance_calc.CalculateDepositCapitalization();
  EXPECT_NEAR(result.accrued_interest, 16640, 50);
  EXPECT_NEAR(result.tax_amount, 0, 50);
  EXPECT_NEAR(result.deposit_amount, 116640, 50);
}