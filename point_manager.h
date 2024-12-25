#pragma once
#include "point.h"
namespace singletones {
	struct PointManager{
		static double get_distance(abstracts::Point& a, abstracts::Point& b);
		static bool equal(abstracts::Point& a, abstracts::Point& b);
		static abstracts::Point new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh);
	};
}
