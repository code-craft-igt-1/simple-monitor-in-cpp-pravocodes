#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 98));
  ASSERT_FALSE(vitalsOk(103, 70, 98));
  ASSERT_FALSE(vitalsOk(98, 99, 89));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}
