#include "CircleFactory.h"
#include "Circle.h"
#include "Random.h"
#include "Constants.h"

spc CircleFactory::MakeRandom () const
{
  auto aResult = std::make_shared<Circle> ();
  aResult->Init (Random::PositiveReal ());
  return aResult;
}
