#include "tests.h"

TEST(Validator, test1) {
  s21::Validator expression("xsin(x)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test2) {
  s21::Validator expression("5 + (4+1)()");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test3) {
  s21::Validator expression("5 + sqrt)x(");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test4) {
  s21::Validator expression("5 + sqrt)x(");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test5) {
  s21::Validator expression("(16x - 25)/(4*sqrt(x) - 5 * sqrt(25))");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test6) {
  s21::Validator expression("log(64*x) / (lfg(x))");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test7) {
  s21::Validator expression("((2 +) 1)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test8) {
  s21::Validator expression("x^^2 + 4");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test9) {
  s21::Validator expression("(x ++ 5)^2");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test10) {
  s21::Validator expression("(x^4 - 13*x^2 + 36)/((x -+ 3)*(x+2))");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test11) {
  s21::Validator expression("1/(1/30 + 1/42(5))");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test12) {
  s21::Validator expression("2 * sin(2*x) - sin(x)) * sqrt(2 * tan(x))");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test13) {
  s21::Validator expression("ln+cos+sin*tan");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test14) {
  s21::Validator expression("2+(*5)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test15) {
  s21::Validator expression("1 + 13(3+5)sin(x)cos(x)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test16) {
  s21::Validator expression("sln(5)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test17) {
  s21::Validator expression("asqrt(5)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test18) {
  s21::Validator expression("olog(5)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test19) {
  s21::Validator expression("lsg(5)");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test20) {
  s21::Validator expression("softsunami");
  EXPECT_FALSE(expression.IsCorrect());
}

TEST(Validator, test21) {
  s21::Validator expression("1+2-3*4/5^6%7");
  EXPECT_TRUE(expression.IsCorrect());
}

TEST(Validator, test22) {
  s21::Validator expression("5*sin(cos(log(ln(x))))");
  EXPECT_TRUE(expression.IsCorrect());
}

TEST(Validator, test23) {
  s21::Validator expression("sqrt(4/2)");
  EXPECT_TRUE(expression.IsCorrect());
}
