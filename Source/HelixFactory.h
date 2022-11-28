#pragma once

#include "CurveFactory.h"

class HelixFactory : public CurveFactory
{
public:
  spc MakeRandom () const override;
};
