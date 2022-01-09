#pragma once
#include <iostream>

#include <vector>
using namespace std;
namespace Dijkistra {
	class Point
	{
	protected:
		static int inc;
		int id_p;
		vector<int> distance;
		int prec;
	public:
		Point();
		vector<int> find_voisins();
		void show() const;
		void change_prec(int k = -1);
		void add_distance(int dis);
		int dis_j(int j);
		void show_pred();
	};
}
