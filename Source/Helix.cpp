#include "Helix.h"
#include "Constants.h"

bool Helix::Init (double theStep, double theRadius)
{
  if (theStep < Constants::Tolerance () || theRadius < Constants::Tolerance ())
    return false;

  myRadius = theRadius;
  myStep = theStep;
  return true;
}

Vector3D Helix::GetPoint (double t) const
{
  return Vector3D {myRadius * cos (t), myRadius * sin (t), myStep * t / (2 * Constants::PI())};
}

Vector3D Helix::GetFirstDerivative (double t) const
{
  return Vector3D {-myRadius * sin (t), myRadius * cos (t), myStep / (2 * Constants::PI())};
}
