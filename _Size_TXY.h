#pragma once
struct Size_TXY{
	size_t x, y;
	bool operator==(const Size_TXY& other) const {
		return x == other.x && y == other.y;
	}
};
struct IntXY {
	int x, y;
};