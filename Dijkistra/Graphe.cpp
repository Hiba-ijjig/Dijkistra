#include "Graphe.h"
using namespace Dijkistra;

void Graphe::show_gr() const
{
	for (int i = 0; i < this->nb_nd; i++)
	{
		this->gr_pt.at(i).show();
		cout << "\n";
	}
}

void Graphe::read_gr(string nameF)
{
	ifstream MyReadFile;
	MyReadFile.open(nameF);
	MyReadFile >> this->nb_nd;
	for (int i = 0; i < this->nb_nd; i++)
	{
		Point p;
		for (int j = 0; j < this->nb_nd; j++)
		{
			int k;
			MyReadFile >> k;
			p.add_distance(k);
		}
		this->gr_pt.push_back(p);
	}
}

vector<int> Dijkistra::Graphe::voisinage(int ind_p)
{
	return this->gr_pt.at(ind_p).find_voisins();
}

int Dijkistra::Graphe::dis_betwen_i_j(int i, int j)
{
	return this->gr_pt.at(i).dis_j(j);
}

void Dijkistra::Graphe::change_pred_pt(int pt, int nv_pred)
{
	this->gr_pt.at(pt).change_prec(nv_pred);
}

int Dijkistra::Graphe::min_not_visited(vector<int> d, vector<bool> v)
{
	vector<int> tmp;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == false) tmp.push_back(i);
	}
	int min = INT_MAX;
	int ind_min = -1;
	for (auto it : tmp)
	{
		if (d.at(it) < min)
		{
			ind_min = it;
			min = d.at(it);
		}
	}
	return ind_min;
}

bool Dijkistra::Graphe::exist_not_v(const vector<bool> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v.at(i) == false) return true;
	}
	return false;
}

void Dijkistra::Graphe::show_chemin()
{
	cout << "\n";
	cout << "les noeuds:\t\t";
	for (int i = 0; i < this->nb_nd; i++)
	{
		cout <<i <<" ";
	}
	cout << "\n";
	cout << "distance minimales:\t";
	for (auto it: this->plus_court_chemin)
	{
		cout << it << " ";
	}
	cout << "\n";
	cout << "Les prédécesseurs:\t";
	for (auto it: this->gr_pt)
	{
		it.show_pred();
		cout << " ";
	}
	cout << "\n";
}


void Graphe::Dj(int pt_d)
{
	vector<bool> visited;
	vector<int> dis;
	//initialisation des variables
	for (int i = 0; i < this->nb_nd; i++)
	{
		visited.push_back(false);
		dis.push_back(INT_MAX);
	}
	//distance vers le point de depart
	dis.at(pt_d) = 0;
	while (this->exist_not_v(visited))
	{ 
		int elem_min = min_not_visited(dis, visited);
		visited.at(elem_min) = true;
		vector<int> lst_voisins;
		lst_voisins = this->voisinage(elem_min);
		for (auto it : lst_voisins)
		{
			if (dis.at(it) > (dis[elem_min] + this->dis_betwen_i_j(elem_min, it)))
			{
				dis.at(it) = dis[elem_min] + this->dis_betwen_i_j(elem_min, it);
				this->change_pred_pt(it, elem_min);
			}
		}
	}
	this->plus_court_chemin = dis;
	this->show_chemin();
}


