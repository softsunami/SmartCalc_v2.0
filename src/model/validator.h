#ifndef SMARTCALC_SRC_MODEL_VALIDATOR_H
#define SMARTCALC_SRC_MODEL_VALIDATOR_H

#include <cstring>
#include <stack>
#include <string>

namespace s21 {
class Validator {
 public:
  explicit Validator(std::string text);
  [[nodiscard]] bool IsCorrect() const;
  [[nodiscard]] static bool IsNumber(const std::string& text);

 private:
  std::string expression_;
  int exp_len_;
  bool is_correct_;

  bool ValidateLen_();
  bool ValidateAlphabet_();
  bool ValidateParentheses_();
  bool ValidateSigns_();
  bool ValidateFunctions_();
  bool ValidateNumbers_();

  static bool IsDigit_(char ch);
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_VALIDATOR_H