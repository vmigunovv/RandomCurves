#pragma once

#include <stdlib.h>

#include <cmath>
#include <ctime>
#include <memory>

class Curve;
using spc = std::shared_ptr<Curve>;

struct Vector3D 
{
  double x, y, z;
};

class Curve
{
public:
  Curve () = default;
  virtual ~Curve () = default;
  virtual Vector3D GetPoint (double t) const = 0;
  virtual Vector3D GetFirstDerivative (double t) const = 0;
};

