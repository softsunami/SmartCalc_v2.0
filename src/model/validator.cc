#include "validator.h"

#include <utility>

namespace s21 {
Validator::Validator(std::string text)
    : expression_(std::move(text)),
      exp_len_((int)expression_.size()),
      is_correct_(true) {
  is_correct_ &= ValidateLen_();
  is_correct_ &= ValidateAlphabet_();
  is_correct_ &= ValidateParentheses_();
  is_correct_ &= ValidateSigns_();
  is_correct_ &= ValidateFunctions_();
  is_correct_ &= ValidateNumbers_();
}

bool Validator::IsCorrect() const { return is_correct_; }

bool Validator::ValidateLen_() {
  if (exp_len_ >= 255) is_correct_ = false;
  return is_correct_;
}

bool Validator::ValidateAlphabet_() {
  std::string alphabet = ".0123456789()+~-*/^%acgilnoqrstx";
  if (is_correct_) {
    for (char c : expression_) {
      if (alphabet.find(c) == std::string::npos) is_correct_ = false;
    }
  }
  return is_correct_;
}

bool Validator::ValidateParentheses_() {
  std::stack<char> br_st;

  std::string deny_array[4] = {".)0123456789x", ".)+-*/^%", ".(+-*/^%",
                               ".(0123456789xcstal"};

  if (expression_[0] == '(') br_st.push(')');

  for (int i = 1; i < exp_len_ && is_correct_; i++) {
    if (expression_[i] == '(') {
      if (deny_array[0].find(expression_[i - 1]) != std::string::npos)
        is_correct_ = false;
      if (deny_array[1].find(expression_[i + 1]) != std::string::npos)
        is_correct_ = false;
      br_st.push(')');
    } else if (expression_[i] == ')') {
      if (deny_array[2].find(expression_[i - 1]) != std::string::npos)
        is_correct_ = false;
      if (deny_array[3].find(expression_[i + 1]) != std::string::npos)
        is_correct_ = false;
      if (br_st.empty() || br_st.top() != expression_[i]) {
        is_correct_ = false;
        break;
      }
      br_st.pop();
    }
  }

  if (!br_st.empty()) is_correct_ = false;
  return is_correct_;
}

bool Validator::ValidateSigns_() {
  std::string signs = "+-*/^%";

  for (int i = 0; i < exp_len_ - 1 && is_correct_; i++) {
    if (signs.find(expression_[i]) != std::string::npos &&
        signs.find(expression_[i + 1]) != std::string::npos) {
      is_correct_ = false;
    }
  }

  return is_correct_;
}

bool Validator::ValidateFunctions_() {
  std::string funcs[9] = {"cos(",  "sin(",  "tan(", "acos(", "asin(",
                          "atan(", "sqrt(", "ln(",  "log("};

  std::string func_name;
  int func_idx = 0;

  for (int i = 0; i < exp_len_ && is_correct_; i++) {
    while (strchr("acgilnoqrst(", expression_[i])) {
      if (func_idx >= 6) {
        is_correct_ = false;
        break;
      }
      func_name += expression_[i];
      if (func_name[func_idx] == '(') break;
      func_idx++;
      i++;
    }

    if (func_name[0] != '\0' && func_name[0] != '(') {
      for (int f = 0; f < 9 && func_name[0] != '\0'; f++) {
        is_correct_ = false;
        if (func_name == funcs[f]) {
          is_correct_ = true;
          break;
        }
      }
    }

    func_name.clear();
    func_idx = 0;
  }
  return is_correct_;
}

bool Validator::ValidateNumbers_() {
  for (int i = 0; i < exp_len_; i++) {
    if (IsDigit_(expression_[i])) {
      if (i != 0 && strchr(")x", expression_[i - 1])) is_correct_ = false;
      if (expression_[i + 1] != '\0' && strchr("(xcstal", expression_[i + 1]))
        is_correct_ = false;
    } else if (expression_[i] == 'x') {
      if (i != 0 && strchr("x)0123456789", expression_[i - 1]))
        is_correct_ = false;
      if (expression_[i + 1] != '\0' &&
          strchr("(0123456789cstal", expression_[i + 1]))
        is_correct_ = false;
    }
  }

  for (int i = 0, dot_counter = 0; i < exp_len_; i++) {
    if (expression_[i] == '.') dot_counter++;
    if (dot_counter > 1) is_correct_ = false;
    if (!IsDigit_(expression_[i]) && expression_[i] != '.') dot_counter = 0;
  }

  return is_correct_;
}

bool Validator::IsDigit_(char ch) { return ch >= '0' && ch <= '9'; }

bool Validator::IsNumber(const std::string& text) {
  bool status = true;
  std::string alphabet = ".0123456789";
  for (char c : text) {
    if (alphabet.find(c) == std::string::npos) status = false;
  }
  return status;
}
}  // namespace s21
