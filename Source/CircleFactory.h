#pragma once

#include "CurveFactory.h"

class CircleFactory : public CurveFactory
{
public:
  spc MakeRandom () const override;
};
