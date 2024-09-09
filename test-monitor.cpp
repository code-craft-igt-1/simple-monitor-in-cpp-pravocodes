#include "./monitor.h"
#include "./PrintMessage.h"
#include "gtest/gtest.h"


void test_cases() {
    ASSERT_FALSE(vitalsOk(99, 102, 98));
    ASSERT_FALSE(vitalsOk(103, 70, 98));
    ASSERT_FALSE(vitalsOk(98, 99, 89));
    ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    setLanguage(ENGLISH);
    test_cases();

    setLanguage(GERMAN);
    test_cases();
}
