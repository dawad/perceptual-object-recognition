#include<iostream>
#include "StdAfx.h"
#include <cv.h>
#include "Common\Mask.h"


#include <boost/filesystem/operations.hpp>
#include<boost/filesystem/fstream.hpp>

using namespace cv;
using namespace std ;
using namespace boost::filesystem;

class manip_heatmap
{
private:
	Mask msk;
public:
	manip_heatmap(void);
	~manip_heatmap(void);	
	/// get the grayscale value for an image
	void get_grayscale(const char*);
	/// generate a mask based on heatmap grayscale value and threshold value 
	void generate_mask(const char* , double  threshold , vector<Mask> &mask_table, int fileId=0);
	/// generate mutli masks that varies depending on the threshold value
	void generate_mutli_mask( vector < const char *> & , double threshold , vector <vector <Mask>>& T_mask );
	/// filter the sift descriptors based on Mask values 
	void filter_sift_pts ( vector<Mask> & ,double , vector < vector <float>> & , vector <vector <float>> &, int   );

};

