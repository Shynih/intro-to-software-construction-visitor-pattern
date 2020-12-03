#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"

TEST(SubTEST, TwoMinusFive) {
	Base* two = new Op(2);
	Base* five = new Op(5);
	Base* test = new Sub(two, five);
	EXPECT_EQ(test->evaluate(), -3);
}

TEST(SubTEST, ZeroMinusZero) {
	Base* zero1 = new Op(0);
	Base* zero2 = new Op(0);
	Base* test = new Sub(zero1, zero2);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTEST, MinusNegative) {
	Base* three = new Op(3);
	Base* negTen = new Op(-10);
	Base* test = new Sub(three, negTen);
	EXPECT_EQ(test->evaluate(), 13);
}

TEST(SubTEST, SubStringify) {
	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* test = new Sub(one, two);
	EXPECT_EQ(test -> stringify(), "1.0 - 2.0");
}

#endif
