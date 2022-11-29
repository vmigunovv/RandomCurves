#pragma once

#include "Curve.h"

// Parametrically defined ellipse:
// x = Rx*cos(t))
// y = Ry*sin(t)
// z = 0
class Ellipse : public Curve 
{
public:
  // Default constructor
  Ellipse () : myRx (2.), myRy (1.) {}

  // Sets axes and returns true if parameters are positive. Otherwise returns false
  bool Init (double theAxeX, double theAxeY);

  Vector3D GetPoint (double t) const override;
  Vector3D GetFirstDerivative (double t) const override;
private:
  double myRx, myRy;
};
