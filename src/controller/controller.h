#ifndef SMARTCALC_SRC_CONTROLLER_CONTROLLER_H
#define SMARTCALC_SRC_CONTROLLER_CONTROLLER_H

#include <string>
#include <vector>

#include "../model/arithmetic_calc.h"
#include "../model/finance_calc.h"
#include "../model/graph.h"

namespace s21 {
class Controller {
 public:
  static std::string Concat(const std::string& expression,
                            const std::string& input);
  static std::pair<std::string, bool> ArithmeticProcess(
      const std::string& expression, double x);
  static std::string Erase(const std::string& expression);

  static bool ValidateData(const std::vector<std::string>& values);

  static CreditInfo CreditProcess(
      const struct CreditInputData& credit_input_data);

  static DepositInfo DepositProcess(
      const struct DepositInputData& deposit_input_data);

  static void FillVectors(struct GraphData& graph_data);
};
}  // namespace s21

#endif  // SMARTCALC_SRC_CONTROLLER_CONTROLLER_H
