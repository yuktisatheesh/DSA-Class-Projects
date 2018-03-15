﻿#pragma once

#include "Array_2D.h"

#ifndef CROSSING
#define EXT extern
#endif
#ifdef CROSSING
#define EXT
#endif

namespace Crossing {
	EXT short number;
	EXT bool* in;
	EXT bool* out;
	EXT short two_ways;
	EXT short no_in;
	EXT short no_out;
	EXT int possi;

	class Roads {
	public:
//		Roads(short num);
		struct route {
			short from;					//实际的来路
			short to;					//实际的去向
			int offset;					//这个走法在二维数组中的对应的编号
		};
		route* routes;
		Roads();
		void get_status();
		void init(route*& rt);
	private:

	};

	class relations :	public Array_2D<bool>
//						public Roads
	{
	public:
		relations(Roads& rd) :Array_2D<bool>(possi, possi) { This = &rd; }
//		relations();
//		relations(const int& row, const int& col) :Array_2D<bool>(row, col) {};
		virtual ~relations() = default;
		Roads* This;
		void find_relations();
		void print_rel();
	protected:
		bool compatible(Roads::route& rt1, Roads::route& rt2);
		char rela(Roads::route rt, short pos);
		short right_dist(short s1, short s2);
		short left_dist(short s1, short s2);
	};
}

