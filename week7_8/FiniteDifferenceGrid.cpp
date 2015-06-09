#include <cassert>
#include <cmath>
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

FiniteDifferenceGrid::FiniteDifferenceGrid(std::vector<Node> nodes, double xMin, double xMax)
{
   int n = nodes.size();

   assert(fabs(nodes[0].coordinate - xMin) < 1.0e-6);
   assert(fabs(nodes[n - 1].coordinate - xMax) < 1.0e-6);

   mNodes = nodes;
}
