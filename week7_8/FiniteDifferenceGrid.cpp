#include <cassert>
#include "FiniteDifferenceGrid.hpp"
#include "Node.hpp"

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xMin, double xMax)
{
   double h;
   h = (xMax - xMin) / ((double) (numNodes - 1));

   for (int i = 0; i < numNodes; i++)
   {
      Node node;
      node.coordinate = xMin + i * h;
      mNodes.push_back(node);
   }
}

