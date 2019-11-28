/// this class returns the nearest cluster to an descriptor in image .
/// it contains the cluster indice and the distance between this cluster and a descriptor .


#pragma once
#include "../stdafx.h"
class nearest_clusters
{
private :
	float min_distance;
	int cluster_indice;
public:
	nearest_clusters(void);
	~nearest_clusters(void);
	float get_min_distance ();
	int get_cluster_indice();
	void set_min_distance(float dist);
	void  set_cluster_indice (int indice);

};

