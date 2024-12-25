#include "point_manager.h"
#include  <cmath>

namespace singletones {
	double PointManager::get_distance(abstracts::Point& a, abstracts::Point& b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	bool PointManager::equal(abstracts::Point& a, abstracts::Point& b) {
		return a.x == b.x and a.y == b.y;
	}
	abstracts::Point PointManager::new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh) {
		double distance = get_distance(a, b);
		double hours = distance / speed_kmh;
		if (hours <= 1)
			return b;
		abstracts::Point result;
		result.x = a.x + (b.x - a.x) / hours;
		result.y = a.y + (b.y - a.y) / hours;
		return result;
	}
}
