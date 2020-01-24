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
#include "ad/physics/Acceleration.hpp"

TEST(AccelerationTests, defaultConstructionIsInvalid)
{
  ::ad::physics::Acceleration value;
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, minIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(-1e3, ::ad::physics::Acceleration::cMinValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Acceleration::cMinValue, static_cast<double>(::ad::physics::Acceleration::getMin()));
}

TEST(AccelerationTests, maxIsDefinedAsExpected)
{
  EXPECT_DOUBLE_EQ(1e3, ::ad::physics::Acceleration::cMaxValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Acceleration::cMaxValue, static_cast<double>(::ad::physics::Acceleration::getMax()));
}

TEST(AccelerationTests, precisionIsDefinedAsExpected)
{
  EXPECT_LT(0., ::ad::physics::Acceleration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(1e-4, ::ad::physics::Acceleration::cPrecisionValue);
  EXPECT_DOUBLE_EQ(::ad::physics::Acceleration::cPrecisionValue,
                   static_cast<double>(::ad::physics::Acceleration::getPrecision()));
}

TEST(AccelerationTests, minIsValid)
{
  EXPECT_TRUE(::ad::physics::Acceleration::getMin().isValid());
}

TEST(AccelerationTests, aboveMinIsValid)
{
  ::ad::physics::Acceleration value(::ad::physics::Acceleration::cMinValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

TEST(AccelerationTests, belowMinIsInvalid)
{
  ::ad::physics::Acceleration value(::ad::physics::Acceleration::cMinValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, maxIsValid)
{
  EXPECT_TRUE(::ad::physics::Acceleration::getMax().isValid());
}

TEST(AccelerationTests, aboveMaxIsInvalid)
{
  ::ad::physics::Acceleration value(::ad::physics::Acceleration::cMaxValue * 1.1);
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, belowMaxIsValid)
{
  ::ad::physics::Acceleration value(::ad::physics::Acceleration::cMaxValue * 0.9);
  EXPECT_TRUE(value.isValid());
}

#if (AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION == 1)
TEST(AccelerationTests, ensureValidThrowsOnInvalid)
{
  ::ad::physics::Acceleration value;
  EXPECT_THROW(value.ensureValid(), std::out_of_range);
}

TEST(AccelerationTests, ensureValidNonZeroThrowsOnInvalid)
{
  ::ad::physics::Acceleration value;
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}

TEST(AccelerationTests, ensureValidNonZeroThrowsOnZero)
{
  ::ad::physics::Acceleration value(0.);
  EXPECT_THROW(value.ensureValidNonZero(), std::out_of_range);
}
#endif

TEST(AccelerationTestsStd, numericLimitsLowestIsMin)
{
  EXPECT_DOUBLE_EQ(static_cast<double>(::ad::physics::Acceleration::getMin()),
                   static_cast<double>(std::numeric_limits<::ad::physics::Acceleration>::lowest()));
}

TEST(AccelerationTestsStd, numericLimitsMaxIsMax)
{
  EXPECT_DOUBLE_EQ(static_cast<double>(::ad::physics::Acceleration::getMax()),
                   static_cast<double>(std::numeric_limits<::ad::physics::Acceleration>::max()));
}

TEST(AccelerationTestsStd, numericLimitsEpsilonIsPrecision)
{
  EXPECT_DOUBLE_EQ(static_cast<double>(::ad::physics::Acceleration::getPrecision()),
                   static_cast<double>(std::numeric_limits<::ad::physics::Acceleration>::epsilon()));
}

TEST(AccelerationTestsStd, fabsIsWorkingCorrectly)
{
  EXPECT_DOUBLE_EQ(0., static_cast<double>(std::fabs(::ad::physics::Acceleration(-0.))));
  EXPECT_DOUBLE_EQ(1., static_cast<double>(std::fabs(::ad::physics::Acceleration(-1.))));
  EXPECT_DOUBLE_EQ(
    ::ad::physics::Acceleration::cPrecisionValue,
    static_cast<double>(std::fabs(::ad::physics::Acceleration(::ad::physics::Acceleration::cPrecisionValue))));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Acceleration::cMinValue),
                   static_cast<double>(std::fabs(::ad::physics::Acceleration(::ad::physics::Acceleration::cMinValue))));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::Acceleration::cMinValue),
    static_cast<double>(std::fabs(::ad::physics::Acceleration(-::ad::physics::Acceleration::cMinValue))));
  EXPECT_DOUBLE_EQ(std::fabs(::ad::physics::Acceleration::cMaxValue),
                   static_cast<double>(std::fabs(::ad::physics::Acceleration(::ad::physics::Acceleration::cMaxValue))));
  EXPECT_DOUBLE_EQ(
    std::fabs(::ad::physics::Acceleration::cMaxValue),
    static_cast<double>(std::fabs(::ad::physics::Acceleration(-::ad::physics::Acceleration::cMaxValue))));
}

TEST(AccelerationTests, constructionFromValidFPValue)
{
  double const validValue = ::ad::physics::Acceleration::cMinValue;
  ::ad::physics::Acceleration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(validValue, static_cast<double>(value));
}

TEST(AccelerationTests, copyConstructionFromValidValue)
{
  ::ad::physics::Acceleration const validValue(::ad::physics::Acceleration::cMinValue);
  ::ad::physics::Acceleration value(validValue);
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(static_cast<double>(validValue), static_cast<double>(value));
}

TEST(AccelerationTests, moveConstructionFromValidValue)
{
  ::ad::physics::Acceleration value(std::move(::ad::physics::Acceleration(::ad::physics::Acceleration::cMinValue)));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Acceleration::cMinValue, static_cast<double>(value));
}

TEST(AccelerationTests, assignmentFromValidValue)
{
  ::ad::physics::Acceleration const validValue(::ad::physics::Acceleration::cMinValue);
  ::ad::physics::Acceleration value;
  value = validValue;
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(static_cast<double>(validValue), static_cast<double>(value));
}

TEST(AccelerationTests, moveAssignmentFromValidValue)
{
  ::ad::physics::Acceleration value;
  value = std::move(::ad::physics::Acceleration(::ad::physics::Acceleration::cMinValue));
  EXPECT_TRUE(value.isValid());
  EXPECT_DOUBLE_EQ(::ad::physics::Acceleration::cMinValue, static_cast<double>(value));
}

TEST(AccelerationTests, constructionFromInvalidFPValue)
{
  double const invalidValue = std::numeric_limits<double>::quiet_NaN();
  ::ad::physics::Acceleration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, copyConstructionFromInvalidValue)
{
  ::ad::physics::Acceleration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Acceleration value(invalidValue);
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, assignmentFromInvalidValue)
{
  ::ad::physics::Acceleration const invalidValue(std::numeric_limits<double>::quiet_NaN());
  ::ad::physics::Acceleration value;
  value = invalidValue;
  EXPECT_FALSE(value.isValid());
}

TEST(AccelerationTests, selfAssignment)
{
  ::ad::physics::Acceleration value(::ad::physics::Acceleration::cMinValue);
  EXPECT_TRUE(value.isValid());
  value = value;
  EXPECT_TRUE(value.isValid());
}

TEST(AccelerationTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::physics::Acceleration value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if (AD_PHYSICS_ACCELERATION_THROWS_EXCEPTION == 1)
TEST(AccelerationTests, comparisonOperatorsThrowOnInvalid)
{
  ::ad::physics::Acceleration const value(::ad::physics::Acceleration::cMinValue);
  ::ad::physics::Acceleration const invalidValue;

  EXPECT_THROW(invalidValue == value, std::out_of_range);
  EXPECT_THROW(value == invalidValue, std::out_of_range);

  EXPECT_THROW(invalidValue != value, std::out_of_range);
  EXPECT_THROW(value != invalidValue, std::out_of_range);

  EXPECT_THROW(invalidValue > value, std::out_of_range);
  EXPECT_THROW(value > invalidValue, std::out_of_range);

  EXPECT_THROW(invalidValue < value, std::out_of_range);
  EXPECT_THROW(value < invalidValue, std::out_of_range);

  EXPECT_THROW(invalidValue >= value, std::out_of_range);
  EXPECT_THROW(value >= invalidValue, std::out_of_range);

  EXPECT_THROW(invalidValue <= value, std::out_of_range);
  EXPECT_THROW(value <= invalidValue, std::out_of_range);
}

TEST(AccelerationTests, arithmeticOperatorsThrowOnInvalid)
{
  ::ad::physics::Acceleration const minimalValue(::ad::physics::Acceleration::cMinValue);
  ::ad::physics::Acceleration const maximalValue(::ad::physics::Acceleration::cMaxValue);
  ::ad::physics::Acceleration const invalidValue;
  ::ad::physics::Acceleration calculationValue;

  //  operator+(::ad::physics::Acceleration)
  EXPECT_THROW(invalidValue + maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue + invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue + maximalValue, std::out_of_range);

  //  operator+=(::ad::physics::Acceleration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += invalidValue, std::out_of_range);
  calculationValue = maximalValue;
  EXPECT_THROW(calculationValue += maximalValue, std::out_of_range);

  //  operator-(::ad::physics::Acceleration)
  EXPECT_THROW(invalidValue - minimalValue, std::out_of_range);
  EXPECT_THROW(minimalValue - invalidValue, std::out_of_range);
  EXPECT_THROW(minimalValue - maximalValue, std::out_of_range);

  //  operator-=(::ad::physics::Acceleration)
  calculationValue = invalidValue;
  EXPECT_THROW(calculationValue -= minimalValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= invalidValue, std::out_of_range);
  calculationValue = minimalValue;
  EXPECT_THROW(calculationValue -= maximalValue, std::out_of_range);

  //  operator*(double)
  EXPECT_THROW(invalidValue * static_cast<double>(maximalValue), std::out_of_range);
  EXPECT_THROW(maximalValue * static_cast<double>(maximalValue), std::out_of_range);

  //  operator/(double)
  EXPECT_THROW(invalidValue / static_cast<double>(maximalValue), std::out_of_range);
  EXPECT_THROW(maximalValue / static_cast<double>(invalidValue), std::out_of_range);
  EXPECT_THROW(maximalValue / 0.0, std::out_of_range);
  EXPECT_THROW(maximalValue / 0.5, std::out_of_range);

  //  operator/(::ad::physics::Acceleration)
  EXPECT_THROW(invalidValue / maximalValue, std::out_of_range);
  EXPECT_THROW(maximalValue / invalidValue, std::out_of_range);
  EXPECT_THROW(maximalValue / ::ad::physics::Acceleration(0.0), std::out_of_range);

  //  operator-()
  EXPECT_THROW(-invalidValue, std::out_of_range);
  if (std::fabs(static_cast<double>(maximalValue)) > std::fabs(static_cast<double>(minimalValue)))
  {
    EXPECT_THROW(-maximalValue, std::out_of_range);
  }
  else if (std::fabs(static_cast<double>(maximalValue)) < std::fabs(static_cast<double>(minimalValue)))
  {
    EXPECT_THROW(-minimalValue, std::out_of_range);
  }
  else
  {
    // impossible to trigger invalid result while operand is valid
  }
}
#endif

TEST(AccelerationTests, comparisonOperatorsRespectPrecision)
{
  double const precisionValueTimesTen = ::ad::physics::Acceleration::cPrecisionValue * 10.;
  ::ad::physics::Acceleration value;
  if (::ad::physics::Acceleration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Acceleration(::ad::physics::Acceleration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Acceleration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Acceleration(::ad::physics::Acceleration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Acceleration(precisionValueTimesTen);
  }
  ::ad::physics::Acceleration const sameValue = value;
  ::ad::physics::Acceleration const slightlyBiggerValue(static_cast<double>(value)
                                                        + ::ad::physics::Acceleration::cPrecisionValue * 0.9);
  ::ad::physics::Acceleration const slightlySmallerValue(static_cast<double>(value)
                                                         - ::ad::physics::Acceleration::cPrecisionValue * 0.9);
  ::ad::physics::Acceleration const actuallyBiggerValue(static_cast<double>(value)
                                                        + ::ad::physics::Acceleration::cPrecisionValue * 1.1);
  ::ad::physics::Acceleration const actuallySmallerValue(static_cast<double>(value)
                                                         - ::ad::physics::Acceleration::cPrecisionValue * 1.1);

  // operator ==
  EXPECT_TRUE(value == sameValue);
  EXPECT_TRUE(value == slightlyBiggerValue);
  EXPECT_TRUE(value == slightlySmallerValue);
  EXPECT_FALSE(value == actuallyBiggerValue);
  EXPECT_FALSE(value == actuallySmallerValue);

  // operator !=
  EXPECT_FALSE(value != sameValue);
  EXPECT_FALSE(value != slightlyBiggerValue);
  EXPECT_FALSE(value != slightlySmallerValue);
  EXPECT_TRUE(value != actuallyBiggerValue);
  EXPECT_TRUE(value != actuallySmallerValue);

  // operator >
  EXPECT_FALSE(value > value);
  EXPECT_FALSE(slightlyBiggerValue > value);
  EXPECT_TRUE(actuallyBiggerValue > value);

  // operator >=
  EXPECT_FALSE(actuallySmallerValue >= value);
  EXPECT_TRUE(slightlySmallerValue >= value);
  EXPECT_TRUE(value >= value);
  EXPECT_TRUE(slightlyBiggerValue >= value);
  EXPECT_TRUE(actuallyBiggerValue >= value);

  // operator <
  EXPECT_FALSE(value < value);
  EXPECT_FALSE(slightlySmallerValue < value);
  EXPECT_TRUE(actuallySmallerValue < value);

  // operator <=
  EXPECT_FALSE(actuallyBiggerValue <= value);
  EXPECT_TRUE(slightlyBiggerValue <= value);
  EXPECT_TRUE(value <= value);
  EXPECT_TRUE(slightlySmallerValue <= value);
  EXPECT_TRUE(actuallySmallerValue <= value);
}

TEST(AccelerationTests, arithmeticOperatorsComputeCorrectly)
{
  double const cDoubleNear = ::ad::physics::Acceleration::cPrecisionValue;
  double const precisionValueTimesTen = ::ad::physics::Acceleration::cPrecisionValue * 10.;
  ::ad::physics::Acceleration value;
  if (::ad::physics::Acceleration::cMinValue > precisionValueTimesTen)
  {
    value = ::ad::physics::Acceleration(::ad::physics::Acceleration::cMinValue + precisionValueTimesTen);
  }
  else if (::ad::physics::Acceleration::cMaxValue < precisionValueTimesTen)
  {
    value = ::ad::physics::Acceleration(::ad::physics::Acceleration::cMaxValue - precisionValueTimesTen);
  }
  else
  {
    value = ::ad::physics::Acceleration(precisionValueTimesTen);
  }

  ::ad::physics::Acceleration result;

  //  operator+(::ad::physics::Acceleration)
  result = value + value;
  EXPECT_NEAR(static_cast<double>(value) + static_cast<double>(value), static_cast<double>(result), cDoubleNear);

  //  operator+=(::ad::physics::Acceleration)
  result = value;
  result += value;
  EXPECT_NEAR(static_cast<double>(value) + static_cast<double>(value), static_cast<double>(result), cDoubleNear);

  //  operator-(::ad::physics::Acceleration)
  result = value - value;
  EXPECT_NEAR(static_cast<double>(value) - static_cast<double>(value), static_cast<double>(result), cDoubleNear);

  //  operator-=(::ad::physics::Acceleration)
  result = value;
  result -= value;
  EXPECT_NEAR(static_cast<double>(value) - static_cast<double>(value), static_cast<double>(result), cDoubleNear);

  //  operator*(double)
  result = value * 5.;
  EXPECT_NEAR(static_cast<double>(value) * 5., static_cast<double>(result), cDoubleNear);

  //  operator*(double, ::ad::physics::Acceleration)
  result = 5. * value;
  EXPECT_NEAR(static_cast<double>(value) * 5., static_cast<double>(result), cDoubleNear);

  //  operator/(double)
  result = value / static_cast<double>(value);
  EXPECT_NEAR(static_cast<double>(value) / static_cast<double>(value), static_cast<double>(result), cDoubleNear);

  //  operator/(::ad::physics::Acceleration)
  double const doubleResult = value / value;
  EXPECT_NEAR(static_cast<double>(value) / static_cast<double>(value), doubleResult, cDoubleNear);

  //  operator-()
  if ((::ad::physics::Acceleration::cMinValue < -static_cast<double>(value))
      && (-static_cast<double>(value) < ::ad::physics::Acceleration::cMaxValue))
  {
    result = -value;
  }
  else
  {
    // not clear on how to trigger valid result if such small value is not working
  }
}
