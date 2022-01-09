#pragma once
#include "Point.h"
#include <fstream>
namespace Dijkistra {
	class Graphe
	{
	private:
		vector<Point> gr_pt;
		int nb_nd;
		vector<int> plus_court_chemin;
	public:
		void show_gr() const;
		void read_gr(string nameF);
		void Dj(int pt_d);
		vector<int> voisinage(int ind_p);
		int dis_betwen_i_j(int i, int j);
		void change_pred_pt(int pt, int nv_pred);
		static int min_not_visited(vector<int> d, vector<bool> v);
		static bool exist_not_v(vector<bool> v);
		void show_chemin();
	};
	
}
