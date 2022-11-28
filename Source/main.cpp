#include "Constants.h"

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include "CircleFactory.h"
#include "EllipseFactory.h"
#include "HelixFactory.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

std::vector<spc> fillVector (size_t theSize) 
{
  std::srand (static_cast<unsigned int> (time (0)));

  std::vector<spc> aResult;
  aResult.reserve (theSize);
  std::shared_ptr<CurveFactory> aFactories[3] = {std::make_shared<CircleFactory> (),
                                                 std::make_shared<EllipseFactory> (),
                                                 std::make_shared<HelixFactory> ()};

  for (size_t i = 0; i < theSize; ++i)
    aResult.push_back (aFactories[rand () % 3]->MakeRandom());
  
  return aResult;
}

int main()
{
  const size_t aSize = 100;
  std::vector<spc> aRandomCurves = fillVector (aSize);
  std::vector<std::shared_ptr<Circle>> aRandomCircles;
  const auto aPI_4 = Constants::PI() / 4.;

  for (auto aRandomCurve : aRandomCurves) 
  {
    auto aP = aRandomCurve->GetPoint (aPI_4);
    auto aD = aRandomCurve->GetFirstDerivative (aPI_4);
    std::cout << "Coordinates: " << aP.x << ' ' << aP.y << ' ' << aP.z << '\n'
              << "First derivative: " << aD.x << ' ' << aD.y << ' ' << aD.z << "\n\n";
		
    if (const auto aCircle = std::dynamic_pointer_cast<Circle> (aRandomCurve))
      aRandomCircles.push_back (aCircle);
  }

  if (aRandomCurves.empty ())
  {
    std::cout << "There aren't any circles\n";
    return 0;
  }

  std::sort (aRandomCircles.begin (),
             aRandomCircles.end (),
             [](spc c1, spc c2) {
               return std::static_pointer_cast<Circle> (c1)->GetRadius () <
               std::static_pointer_cast<Circle> (c2)->GetRadius ();
             });


  const auto SumOfRadii = std::accumulate (
                            aRandomCircles.cbegin (),
                            aRandomCircles.cend (),
                            0.,
                            [](double Sum, const std::shared_ptr<Circle>& C1) {
                              return C1->GetRadius() + Sum;
                            });

  std::cout << "Sum of rudii = " << SumOfRadii << "\n";

  return 0;
}
