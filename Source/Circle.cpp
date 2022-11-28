#include "Circle.h"
#include "Constants.h"

Vector3D Circle::GetPoint (double t) const
{
  return Vector3D {myRadius * cos (t), myRadius * sin (t), 0};
}

Vector3D Circle::GetFirstDerivative (double t) const
{
  return Vector3D {-myRadius * sin (t), myRadius * cos (t), 0};
}

bool Circle::Init(double theRadius)
{
  if (theRadius < Constants::Tolerance ())
    return false;

  myRadius = theRadius;
  return true;
}

const double Circle::GetRadius () const
{
  return myRadius;
}
