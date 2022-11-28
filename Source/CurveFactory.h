#pragma once

#include "Curve.h"

class CurveFactory
{
public:
  virtual spc MakeRandom () const = 0;  
};
