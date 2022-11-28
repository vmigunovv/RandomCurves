#pragma once

#include <ctime>

namespace Random
{
  static constexpr double Tolerance ()
  {
    return  1.e-10;
  }

  static double Real ()
  {
    double i, j;
    do { i = rand (); } while (i == 0);
    do { j = rand (); } while (j == RAND_MAX);
    return i - j / RAND_MAX;
  }
 
  static double PositiveReal (double theTolerance = Tolerance ())
  {
    double aResult = -1.;
    do { aResult = Real (); } while (aResult < theTolerance);
    return aResult;
  } 
} // namespace Random