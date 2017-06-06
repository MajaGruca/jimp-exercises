//
// Created by mwypych on 01.06.17.
//

#include <string>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include "ArabicRoman.h"



TEST(arabic_to_roman_test, arabic_to_roman_of_10_is_X) {
    EXPECT_EQ("X", ArabicToRoman(10));
}


TEST(arabic_to_roman_test, arabic_to_roman_of_12_is_XII) {
    EXPECT_EQ("XII", ArabicToRoman(12));
}
TEST(arabic_to_roman_test, arabic_to_roman_of_1000_is_M) {
    EXPECT_EQ("M", ArabicToRoman(1000));
}


TEST(arabic_to_roman_test, arabic_to_roman_of_99_is_XCIX) {
    EXPECT_EQ("XCIX", ArabicToRoman(99));
}