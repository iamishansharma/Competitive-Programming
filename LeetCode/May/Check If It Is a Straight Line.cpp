/*You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.*/

class Solution 
{
	public:
		    bool checkStraightLine(vector<vector<int>>& coordinates) 
		    {
		        double k = 1, k_ = 0, c = coordinates[0][0];

				if (coordinates[0][0] != coordinates[1][0]) 
				{
					double x1 = coordinates[0][0];
					double y1 = coordinates[0][1];
					double x2 = coordinates[1][0];
					double y2 = coordinates[1][1];

					k = (y2-y1)/(x1-x2);
					k_ = 1;
					c = (y1*x2-y2*x1)/(x2-x1);
				}

				for (auto& i : coordinates)
					if (k * i[0] + k_ * i[1] - c)
						return false;

				return true;
		    }
};