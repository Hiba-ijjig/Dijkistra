#include "Point.h"
using namespace Dijkistra;
int Point::inc = 0;
Point::Point()
{
	this->id_p = inc++;
	this->change_prec();

}

vector<int> Point::find_voisins()
{
	vector<int> v;
	for (int i = 0; i < this->distance.size(); i++)
	{
		if (this->distance.at(i) != 0) v.push_back(i);
	}
	return v;
}

void Point::show() const
{
	
	for (int k = 0; k < this->distance.size(); k++)
		cout << this->distance.at(k) << "\t";
}

void Point::change_prec(int k)
{
	this->prec = k;
}

void Point::add_distance(int dis)
{
	this->distance.push_back(dis);
}

int Dijkistra::Point::dis_j(int j)
{
	return this->distance.at(j);
}

void Dijkistra::Point::show_pred()
{
	cout << this->prec;
}
