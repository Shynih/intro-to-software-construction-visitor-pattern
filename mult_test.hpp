#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTEST, TwoMultFive) {
	Base* two = new Op(2);
	Base* five = new Op(5);
	Base* test = new Mult(two, five);
	EXPECT_EQ(test->evaluate(), 10);
}

TEST(MultTEST, TwoMultZero) {
	Base* two = new Op(2);
	Base* zero = new Op(0);
	Base* test = new Mult(two, zero);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTEST, MultNegative) {
	Base* three = new Op(3);
	Base* negTen = new Op(-10);
	Base* test = new Mult(three, negTen);
	EXPECT_EQ(test->evaluate(), -30);
}

TEST(MultTEST, MultStringify) {
	Base * one = new Op(1);
	Base* two = new Op(2);
	Base* test = new Mult(one, two);
	EXPECT_EQ(test->stringify(), "1.0 * 2.0");
}
#endif
