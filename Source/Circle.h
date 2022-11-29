#pragma once

#include "Curve.h"

// Parametrically defined circle:
// x = R*cos(t))
// y = R*sin(t)
// z = 0
class Circle : public Curve 
{
public:
  // Default Constructor
  Circle () : myRadius (1.) {}
  
  // Sets radius and returns true  if theRadius is positive
  bool Init (double theRadius);

  const double GetRadius () const;
  Vector3D GetPoint (double t) const override;
  Vector3D GetFirstDerivative (double t) const override;
private:
  double myRadius;
};
