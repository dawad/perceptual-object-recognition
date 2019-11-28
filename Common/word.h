#pragma once
/*
*  visual vocabulary is a set of words . each words contains the cluster which a descriptor is assigned to it , the interest point, the scale and the image id .
*/

#include "nearest_clusters.h"

class word
{
private:
	nearest_clusters center;
	float ptx ;
	float pty;
	double scale ;
	float fileid;
public:
	word(void);
	~word(void);
	nearest_clusters get_nearest_cluster();
	void Initialize_word();
	float get_point_x();
	float get_point_y();
	double get_scale ();
	float get_fileid();
	void set_nearest_cluster(nearest_clusters  center);
	void set_point_x(float ptx);
	void set_point_y(float pty);
	void set_scale(double scale);
	void set_fileid(float fileid);

};

