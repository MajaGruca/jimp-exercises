//
// Created by mwypych on 01.06.17.
//
#include <string>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "ArabicRoman.h"



TEST(roman_to_arabic_test, roman_to_arabic_of_X_is_10) {
    EXPECT_EQ(10, RomanToArabic("X"));
}


TEST(roman_to_arabic_test, roman_to_arabic_of_XII_is_12) {
    EXPECT_EQ(12, RomanToArabic("XII"));
}
TEST(roman_to_arabic_test, roman_to_arabic_of_M_is_1000) {
    EXPECT_EQ(1000, RomanToArabic("M"));
}


TEST(roman_to_arabic_test, roman_to_arabic_of_XCIX_is_99) {
    EXPECT_EQ(99, RomanToArabic("XCIX"));
}
