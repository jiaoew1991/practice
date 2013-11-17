#include "common/error_code.h"
#include "common/log.h"
#include <gtest/gtest.h>

struct Point
{
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
} /* optional variable list */;

class Polygon
{
public:
	Polygon();
	~Polygon();

	void pushPoint(Point& point)
	{
		mData.push_back(point);
	}
private:
	std::vector<Point> mData;
};
int outline(std::vector<Polygon>& polygons, Polygon& outlinePolygon)
{
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
