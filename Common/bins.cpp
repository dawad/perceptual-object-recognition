#include "StdAfx.h"
#include "bins.h"


bins::bins(void)
{
	bins::cluster_frequence=0;
	bins::cluster_indice=0;
}


bins::~bins(void)
{
}

int bins::get_cluster_indice()
{
	return bins::cluster_indice;
}
int bins::get_cluster_freq()
{
	return bins::cluster_frequence;
}
void bins::set_cluster_freq(int freq)
{
	bins::cluster_frequence=freq;
}
void bins::set_cluster_indice(int ind)
{
	bins::cluster_indice=ind;
}