#pragma once
struct Size_TXY{
	size_t x, y;									// Coordinates
	bool operator==(const Size_TXY& other) const {	// Compare two Size_TXY objects
		return x == other.x && y == other.y;
	}
};
struct IntXY {
	int x, y;										// Coordinates
};