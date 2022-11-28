#pragma once

#include "CurveFactory.h"

class EllipseFactory : public CurveFactory
{
public:
  spc MakeRandom () const override;
};
