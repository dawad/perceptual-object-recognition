#include "StdAfx.h"
#include "nearest_clusters.h"


nearest_clusters::nearest_clusters(void)
{
	nearest_clusters::cluster_indice=0;
	nearest_clusters::min_distance=0;
}


nearest_clusters::~nearest_clusters(void)
{
}

float nearest_clusters::get_min_distance()
{
	return nearest_clusters::min_distance;
}

int  nearest_clusters::get_cluster_indice()
{
	return nearest_clusters::cluster_indice;
}

void nearest_clusters::set_min_distance(float dist)
{
	nearest_clusters::min_distance=dist;
}
void nearest_clusters::set_cluster_indice(int indice)
{
	nearest_clusters::cluster_indice=indice;
}