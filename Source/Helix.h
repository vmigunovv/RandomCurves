#pragma once

#include "Curve.h"

// Parametrically defined helix:
// x = R*cos(t))
// y = R*sin(t)
// z = Kt
// K*2*PI = step
class Helix : public Curve 
{
public:
  // Default constructor
  Helix () : myStep (1.), myRadius (1.) {}

  // Sets step and radius and returns true if parameters are positive. Otherwise returns false 
  bool Init (double theStep, double theRadius);

  Vector3D GetPoint (double t) const override;
  Vector3D GetFirstDerivative (double t) const override;
private:
  double myStep, myRadius;
};

