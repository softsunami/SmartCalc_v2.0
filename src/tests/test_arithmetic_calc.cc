#include "tests.h"

TEST(Arithmetic, Simple1) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 + 2 + 3 + 4 + 5", 0);
  EXPECT_DOUBLE_EQ(result, 1 + 2 + 3 + 4 + 5);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple2) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 - 2 - 3 - 4 - 5", 0);
  EXPECT_DOUBLE_EQ(result, 1 - 2 - 3 - 4 - 5);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple3) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 * 2 * 3 * 4 * 5", 0);
  EXPECT_DOUBLE_EQ(result, 1 * 2 * 3 * 4 * 5);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple4) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 / 2 / 3 / 4 / 5", 0);
  EXPECT_DOUBLE_EQ(result, 1.0 / 2.0 / 3.0 / 4.0 / 5.0);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple5) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 % 2 % 3 % 4 % 5", 0);
  EXPECT_DOUBLE_EQ(result, 1 % 2 % 3 % 4 % 5);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple6) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("2^3^4", 0);
  EXPECT_DOUBLE_EQ(result, 4096);
  EXPECT_TRUE(calc.GetStatus());
}
TEST(Arithmetic, Simple7) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("+5 - 6", 0);
  EXPECT_EQ(result, +5 - 6);
  EXPECT_TRUE(calc.GetStatus());
}
TEST(Arithmetic, Simple8) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sin(5)+cos(5)+tan(5)", 0);
  EXPECT_DOUBLE_EQ(result, sin(5) + cos(5) + tan(5));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple9) {
  s21::ArithmeticCalc calc;
  double result =
      calc.Calculate("2 + (7-x) * 5 - 3.5*(x % 5) + 54.45/41.4", 18);
  EXPECT_DOUBLE_EQ(result, 2 + (7 - 18) * 5 - 3.5 * (18 % 5) + 54.45 / 41.4);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple10) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("acos(0.5)", 0);
  EXPECT_DOUBLE_EQ(result, acos(0.5));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple11) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sqrt(5)", 0);
  EXPECT_DOUBLE_EQ(result, sqrt(5));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple12) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sin(cos(x))", 0);
  EXPECT_DOUBLE_EQ(result, sin(cos(0)));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple13) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("4+9*x-x^3/3", 11);
  EXPECT_DOUBLE_EQ(result, 4.0 + 9.0 * 11.0 - pow(11, 3) / 3.0);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple14) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("(x^4 - 13*x^2 + 36)/((x - 3)*(x+2))", 15.36);
  EXPECT_DOUBLE_EQ(result, (pow(15.36, 4) - 13 * pow(15.36, 2) + 36) /
                               ((15.36 - 3) * (15.36 + 2)));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple15) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("2*x+722/x + 10", 764311);
  EXPECT_DOUBLE_EQ(result, 2 * 764311 + 722.0 / 764311.0 + 10);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple16) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("(x + 5)^2", -45.14);
  EXPECT_DOUBLE_EQ(result, pow(-45.14 + 5, 2));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Simple17) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("x^2 + 4", -45.14);
  EXPECT_DOUBLE_EQ(result, pow(-45.14, 2) + 4);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func1) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("(2*x - 1)*cos(x) - 2*sin(x) + 3", -541.15);
  EXPECT_DOUBLE_EQ(result,
                   (2 * -541.15 - 1) * cos(-541.15) - 2 * sin(-541.15) + 3);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func2) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("2*sqrt(3)*sin(3.14/2 - x)", 1);
  EXPECT_DOUBLE_EQ(result, 2 * sqrt(3) * sin(3.14 / 2.0 - 1));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func3) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("7*sin(2*x - 3.14/2) + 9*cos(x) + 1", 65.886);
  EXPECT_DOUBLE_EQ(result,
                   7 * sin(2 * 65.886 - 3.14 / 2) + 9 * cos(65.886) + 1);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func4) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sqrt(x^2+2*x+82)", 45.14);
  EXPECT_DOUBLE_EQ(result, sqrt(pow(45.14, 2) + 2 * 45.14 + 82));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func5) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("log(64*x) / log(x)", 155.14);
  EXPECT_DOUBLE_EQ(result, log10(64 * 155.14) / log10(155.14));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func6) {
  s21::ArithmeticCalc calc;
  double result =
      calc.Calculate("2 * sin(2*x) - sin(x) * sqrt(2 * tan(x))", 45.14);
  EXPECT_DOUBLE_EQ(result,
                   2 * sin(2 * (45.14)) - sin(45.14) * sqrt(2 * tan(45.14)));
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func7) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("log(x^2+14*x+305)+9", 79);
  EXPECT_DOUBLE_EQ(result, log10(pow(79, 2) + 14 * 79 + 305) + 9);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, Func8) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("ln(x+5)-2*x + 9", 6543);
  EXPECT_DOUBLE_EQ(result, log(6543 + 5) - 2 * 6543 + 9);
  EXPECT_TRUE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat1) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("xsin(x)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat2) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("5 + (4+1)()", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat3) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("5 + sqrt)x(", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat4) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("x5 + 15", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat5) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("(16x - 25)/(4*sqrt(x) - 5 * sqrt(25))", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat6) {
  s21::ArithmeticCalc calc;
  double result =
      calc.Calculate("(16x - 25ln(5))/(4*sqrt(x) - 5 * sqrt(25))", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat7) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("og(64*x) / (lfg(x))", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat8) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("((2 +) 1)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat9) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("(x ++ 5)^2", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat10) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1/(1/30 + 1/42(5))", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat11) {
  s21::ArithmeticCalc calc;
  double result =
      calc.Calculate("2 * sin(2*x) - sin(x)) * sqrt(2 * tan(x))", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat12) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("ln+cos+sin*tan", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat13) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("2+(*5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat14) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("1 + 13(3+5)sin(x)cos(x)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat15) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sln(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat16) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("asqrt(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat17) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("olog(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat18) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("lsg(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectFormat19) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("softsunami", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression1) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("7/(5-5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression2) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("7%(5-5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression3) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("acos(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression4) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("acos(5-7)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression5) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("asin(5)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression6) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("asin(5-7)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression7) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("ln(5-7)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression8) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("log(5-7)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}

TEST(Arithmetic, IncorrectExpression9) {
  s21::ArithmeticCalc calc;
  double result = calc.Calculate("sqrt(5-7)", 0);
  EXPECT_DOUBLE_EQ(result, 0);
  EXPECT_FALSE(calc.GetStatus());
}