#pragma once

#include "Header.h"

constexpr char left{ 'L' };
constexpr char right{ 'R' };
constexpr char up{ 'U' };
constexpr char down{ 'D' };

struct step {
	size_t row;
	size_t col;
	char direction;
	void next_direction();
	void walk();
	step peek();
	bool operator==(step& st) {
		if (this->row == st.row&&this->col == st.col&&this->direction == st.direction) {
			return true;
		}
		return false;
	}
	void print(std::ostream& ost);
};

