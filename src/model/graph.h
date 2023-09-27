#ifndef SMARTCALC_SRC_MODEL_GRAPH_H
#define SMARTCALC_SRC_MODEL_GRAPH_H

#include <iostream>
#include <vector>

#include "arithmetic_calc.h"
#include "validator.h"

namespace s21 {
struct GraphData {
  std::string expression;
  double x1, x2, y1, y2;
  bool x_pi, y_pi;
  std::vector<double> xAxis = {};
  std::vector<double> yAxis = {};
};
}  // namespace s21

namespace s21 {
class Graph {
 public:
  explicit Graph(struct GraphData& load_data);
  [[nodiscard]] bool IsCorrectData() const;
  void FillVectors();
  struct GraphData GetData();

 private:
  struct GraphData graph_data;
  void HandleIsPi();
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_GRAPH_H
