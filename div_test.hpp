#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTEST, TwoDivFive) {
	Base* two = new Op(2);
	Base* five = new Op(5);
	Base* test = new Div(two, five);
	EXPECT_EQ(test->evaluate(), 0.4);
}

TEST(DivTEST, ZeroDivTwo) {
	Base* zero = new Op(0);
	Base* two = new Op(2);
	Base* test = new Div(zero, two);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTEST, DivNegative) {
	Base* two = new Op(2);
	Base* negTen = new Op(-10);
	Base* test = new Div(negTen, two);
	EXPECT_EQ(test->evaluate(), -5);
}

TEST(DivTEST, DivStringify) {
	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* test = new Div(one, two);
	EXPECT_EQ(test -> stringify(), "1.0 / 2.0");
}

#endif
