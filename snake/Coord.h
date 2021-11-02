#pragma once
struct Coord {
public:
	unsigned short x;
	unsigned short y;

	bool operator==(const Coord a);
	Coord(const unsigned short x=0, const unsigned short y=0) : x(x), y(y) {}
};