#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

TEST(AddTEST, TwoPlusFive) {
	Base* two = new Op(2);
	Base* five = new Op(5);
	Base* test = new Add(two, five);
	EXPECT_EQ(test->evaluate(), 7);
}

TEST(AddTEST, ZeroPlusZero) {
	Base* zero1 = new Op(0);
	Base* zero2 = new Op(0);
	Base* test = new Add(zero1, zero2);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTEST, PlusNegative) {
	Base* three = new Op(3);
	Base* negTen = new Op(-10);
	Base* test = new Add(three, negTen);
	EXPECT_EQ(test->evaluate(), -7);
}

TEST(AddTEST, AddStringify) {
	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* test = new Add(one, two);
	EXPECT_EQ(test->stringify(), "1.0 + 2.0");
}
#endif
