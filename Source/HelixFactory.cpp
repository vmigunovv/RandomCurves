#include "HelixFactory.h"
#include "Helix.h"
#include "Random.h"

spc HelixFactory::MakeRandom () const
{
  auto aResult =  std::make_shared<Helix> ();
  aResult->Init (Random::PositiveReal (), Random::PositiveReal ());
  return aResult;
}
