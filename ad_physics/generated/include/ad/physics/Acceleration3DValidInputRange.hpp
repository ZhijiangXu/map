/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-1917
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/physics/Acceleration3D.hpp"
#include "ad/physics/AccelerationValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given Acceleration3D is within valid input range
 *
 * \param[in] input the Acceleration3D as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if Acceleration3D is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::physics::Acceleration3D const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.x, logErrors) && withinValidInputRange(input.y, logErrors)
    && withinValidInputRange(input.z, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::physics::Acceleration3D)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
