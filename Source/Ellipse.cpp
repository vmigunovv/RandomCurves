#include "Ellipse.h"
#include "Constants.h"

bool Ellipse::Init (double theRx, double theRy)
{
  if (theRx < Constants::Tolerance() || theRy < Constants::Tolerance())
    return false;

  myRx = theRx;
  myRy = theRy;
  return true;
}

Vector3D Ellipse::GetPoint (double t) const
{
  return Vector3D {myRx * cos (t), myRy * sin (t), 0};
}

Vector3D Ellipse::GetFirstDerivative (double t) const
{
  return Vector3D {-myRx * sin (t), myRy * cos (t), 0};
}
