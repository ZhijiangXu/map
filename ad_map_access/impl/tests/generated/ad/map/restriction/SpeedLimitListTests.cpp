/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/restriction/SpeedLimitList.hpp"

TEST(SpeedLimitListTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::restriction::SpeedLimitList value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}
