#include "EllipseFactory.h"
#include "Ellipse.h"
#include "Random.h"

spc EllipseFactory::MakeRandom () const
{
  auto aResult = std::make_shared<Ellipse> ();
  aResult->Init (Random::PositiveReal (), Random::PositiveReal ());
  return aResult;
}
