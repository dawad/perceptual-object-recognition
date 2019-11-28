#pragma once

/// A histograms is a set of bins 
/// A bins is a set that contains { cluster indice , frequency of this cluster}
class bins
{
private :
	int cluster_indice ;
	int cluster_frequence ;
public:
	bins(void);
	~bins(void);
	/// these 2 functions helps to return the value of the elements of bins 
	int get_cluster_indice();
	int get_cluster_freq();
	/// these 2 functions change the value of the elements of bins 
	void set_cluster_indice(int ind);
	void set_cluster_freq(int freq);
};
