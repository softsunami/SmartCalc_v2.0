#ifndef SMARTCALC_SRC_MODEL_ARITHMETIC_CALC_H
#define SMARTCALC_SRC_MODEL_ARITHMETIC_CALC_H

#include <cmath>
#include <stack>
#include <string>
#include <vector>

#include "validator.h"

namespace s21 {
class ArithmeticCalc {
 public:
  ArithmeticCalc() noexcept;
  double Calculate(const std::string& expression, double x) noexcept;
  [[nodiscard]] int GetStatus() const noexcept;

 private:
  std::string infix_;
  std::string postfix_;
  bool flag_;

  void ToPostfix_() noexcept;
  void DelExcessOperators_() noexcept;
  [[nodiscard]] static int GetPriority_(char ch) noexcept;
  [[nodiscard]] static bool IsDigit_(char ch) noexcept;
  [[nodiscard]] static bool IsOperator_(char ch) noexcept;
  [[nodiscard]] static bool IsFunc_(char ch) noexcept;

  double Computation_(double x) noexcept;
  double ArithmeticFunc_(char func, double num) noexcept;
  double ArithmeticOperator_(char sign, double num1, double num2) noexcept;

  [[nodiscard]] static char GetFuncName_(char ch1, char ch2) noexcept;
  [[nodiscard]] static int GetFuncLen_(char ch) noexcept;

  void ProcessDigit_(int& i);
  void ProcessX_(int& i);
  void ProcessOperator_(int& i, std::stack<char>& stack1);
  void ProcessRBrace_(int& i, std::stack<char>& stack1);
  void ProcessLBrace_(int& i, std::stack<char>& stack1);
  void ProcessFunc_(int& i, std::stack<char>& stack1);

  void DigitsToStack_(int& i, std::stack<double>& stack1);
  double FuncToStack_(int& i, std::stack<double>& stack1);
  std::vector<double> GetNumbersFromStack_(int i, std::stack<double>& stack1);

  enum functions_ {
    s21_cos = 'c',
    s21_sin = 's',
    s21_sqrt = 'q',
    s21_tan = 't',
    s21_acos = 'C',
    s21_asin = 'S',
    s21_atan = 'T',
    s21_ln = 'l',
    s21_log = 'L'
  };
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_ARITHMETIC_CALC_H
