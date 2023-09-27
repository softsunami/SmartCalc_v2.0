#include "graph.h"

namespace s21 {
Graph::Graph(GraphData& load_data) { graph_data = load_data; }

bool Graph::IsCorrectData() const {
  ArithmeticCalc calc;
  calc.Calculate(graph_data.expression, 1);
  bool result = calc.GetStatus();

  if (graph_data.x1 >= graph_data.x2 || graph_data.x1 < -1000000 ||
      graph_data.x2 > 1000000)
    result = false;
  if (graph_data.y1 >= graph_data.y2 || graph_data.y1 < -1000000 ||
      graph_data.y2 > 1000000)
    result = false;

  return result;
}

void Graph::FillVectors() {
  HandleIsPi();
  double y_val = 0;
  double x_val = graph_data.x1;
  double step = (graph_data.x2 - graph_data.x1) / 500.0;

  s21::ArithmeticCalc calc;

  while (x_val < graph_data.x2) {
    y_val = calc.Calculate(graph_data.expression, x_val);
    if (calc.GetStatus()) {
      graph_data.xAxis.push_back(x_val);
      graph_data.yAxis.push_back(y_val);
    }
    x_val += step;
  }
}

void Graph::HandleIsPi() {
  if (graph_data.x_pi) {
    graph_data.x1 *= M_PI;
    graph_data.x2 *= M_PI;
  }

  if (graph_data.y_pi) {
    graph_data.y1 *= M_PI;
    graph_data.y2 *= M_PI;
  }
}
struct GraphData Graph::GetData() {
  return graph_data;
}
}  // namespace s21
