#include "StdAfx.h"
#include "manip_heatmap.h"
#include "Common\Mask.h"
#include<iostream>
#include<fstream>
#include "cv.h"
#include "highgui.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <strsafe.h>
#include <sstream> 
#include <io.h>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include<boost/filesystem/fstream.hpp>




using namespace cv;
using namespace std ;
using namespace boost::filesystem;


manip_heatmap::manip_heatmap(void)
{
}


manip_heatmap::~manip_heatmap(void)
{
}
void manip_heatmap::get_grayscale(const char*  file)
{
	
	IplImage* img=cvLoadImage(file,0); 
	int step =img->widthStep/sizeof(uchar);
	int channels=img->nChannels;
	uchar* data=(uchar *) img->imageData;

	for (int i=0 ; i<img->height;i++)
	{
		cout <<endl;
		for(int j=0;j<img->width;j++)
		{
			/*for(int k=0 ; k<channels;k++)
				 cout << data[i*step+j*channels+k] << " ";*/
			CvScalar s;
			s=cvGet2D(img,i,j);
			cout <<s.val[0] <<" ";
			
		}
}
}

void manip_heatmap::generate_mask(const char* file , double  threshold , vector<Mask>& mask_table , int fileId)
{
	IplImage* img=cvLoadImage(file,0); 
	int step =img->widthStep;
	int channels=img->nChannels;
	for (double i=0 ; i<img->height-1;i++)
	{
	for(double j=0;j<img->width-1;j++)
		{
			
			Mask msk;
			CvScalar s;
			s=cvGet2D(img,i,j);
			//cout <<s.val[0]<<" ";
			if (s.val[0] > threshold)
			{
			msk.set_mask(1);
			}
			else msk.set_mask(0);
			msk.set_x_value(j);
			msk.set_y_value(i);
			msk.set_threshold(threshold);
			msk.set_fileId(fileId);
			mask_table.push_back(msk);
			
		}
	}
	cout <<" mask is generated successfully \n" ;
}
void manip_heatmap::generate_mutli_mask(vector <const char *>& files , double threshold , vector < vector <Mask>> &T_mask)
{
	vector <Mask> mask_table;
	for (int i=0; i<files.size() ; i++)
	{
		generate_mask(files[i],threshold,mask_table ,i);
		T_mask.push_back(mask_table);
		mask_table.clear();
	}
}

void manip_heatmap::filter_sift_pts( vector<Mask> &img_mask, double threshold , vector < vector <float>> & SIFT_data, vector <vector <float>> & result, int  img_id )
{
	for (int  k=0; k < SIFT_data.size() ; k++)
	{		
			//cout <<" SIFT pt ( "<<k << " ) " <<SIFT_data[k][0] << "  " << SIFT_data[k][1] << "  "  <<SIFT_data[k][3]<< " "  <<endl;
				for (int i=0;i<img_mask.size() ; i++)
					{
					
					if( (floor(SIFT_data[k][0])==img_mask.at(i).get_x_value()) && (floor(SIFT_data[k][1])==img_mask.at(i).get_y_value()))
						{
						//cout << " pts ( " <<k<<") " << img_mask[i].get_x_value() << " , " << img_mask[i].get_y_value()<<" ," << img_mask[i].get_mask()<< "\n"; 
						if(img_mask.at(i).get_mask()==1)
							{
								
								result.push_back(SIFT_data[k]);
								
							}
							
						}
	
					}
			}
	cout <<"the SIFT descriptor has been filtered successfully \n" ;
}