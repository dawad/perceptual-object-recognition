#include "../stdafx.h"

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
#include <string>
#include <sstream> 
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include<boost/filesystem/fstream.hpp>
#include "../Common/bins.h"
#include "arff_data\Donnees.h"
#include "../Common/roc_row.h"
using namespace cv;
using namespace std ;

class Fichiers 
{
private :

	string File_Name ; 
	/// pour lire du fichier ARff 
	std::vector<float> 	data;		/// Vecteur des donnees de l'echantillon
	std::string 		className;	/// Nom de la categorie associee a l'echantillon
	void readLine(std::string line) ;

public:
	
	Fichiers();
	Fichiers(string);
	~Fichiers();
	void read_files(const string & ,std::vector<vector<float>>&);
	void read_files(const string & ,std::vector<vector<int>>&);
	void read_txt_file(const string &, std::vector <vector<float>> & );
	void read_files(const string &name, const string categorie,  vector < const string > &data );
	void read_multi_txt_files(std::vector <boost::filesystem3::path> & descript_files , std::map<std::string ,vector<vector<float>>> & descriptors);
	void read_multi_txt_files(const boost::filesystem3::path & directory,std::vector <const string> & descript_files , std::map<std::string ,vector<vector<float>>> & descriptors);
	void readARFF(const std::string ARFFFileName);
	void read_multi_files(string [] , int  , vector <vector < float >> & );
	void read_ASCII_files(const string&,std::vector<vector<float>>&);
	void read_ASCII_files(const string&,std::vector<vector<int>>&);
	void read_ASCII_files(const string&,std::vector<vector<int>>& , int );
	void read_multi_ACII_files(string [] , int  , vector <vector < float >> & );
	void read_Dirs(const boost::filesystem3::path &  , std::vector <boost::filesystem3::path> &  ,bool recurse_into_subdirs=true);
	void read_Dirs (const boost::filesystem3::path &directory  , vector <const string> & , bool recurse_into_subdirs=true);
	void read_desc_Dirs(const boost::filesystem3::path &  , std::vector <boost::filesystem3::path> &  ,bool recurse_into_subdirs=true);
	inline void  read_desc_file(const string &, vector<vector<float>> &); 
	void read_multi_desc_files(std::vector <boost::filesystem3::path> &, std::map<std::string  ,vector<vector<float>>> & );
	void read_multi_desc_files(const boost::filesystem3::path [] , int  , vector <vector < float >> & );
	void write_txt(const string &name, vector< vector < float >> &data );
	void write_ASCII_txt(const string& ,std::vector<vector<float>>&);
	void write_ASCII_txt(const string& ,Mat data);
	void App_txt(const string& ,Mat data);
	void App_txt(const string& ,CvMat* data);
	void App_ASCII_txt (const string &,vector<bins>& , string ,float temps_calcul );
	void write_ASCII_txt(const string& ,std::vector<vector<bins>>&);
	void write_arff(const string& , std::vector<vector<bins>> &,const string&);
	void write_arff (const string &fileName, CvMat* data , CvMat*resp );
	void write_csv_File (const string &fileName, vector <roc_row> table_roc);
	void write_txt_map(const string & name ,std::map<unsigned int,vector<vector<float>> >& data);

	void write_param_txt(const string &fileName , string classe, string categ, int img_number , float avg_time_PPV , float avg_time_histog, int taille );
	void write_param_txt(const string &fileName , string classe, string categ, int img_number , float avg_time_PPV , float avg_time_histog,int threshold,int taille );
	void write_calc_time_kmean(const string &fileName , string classe,string categ,int img_number , float avg_time_kmean, double );
	void write_svm_res(const string &fileName,String classe,double , double ,double , double , double * ,double *, double AUC);
	void write_svm_res(const string &fileName,String classe,double , double, double ,double , double , double * ,double *, double AUC);
	void merge_descripteurs(std::vector<vector<float>>&,std::vector<vector<float>>&,std::vector<vector<float>>& ,std::vector<vector<float>>&);

	bool check_desc_file( const string & );
	int search_similar_file_name(std::vector <boost::filesystem3::path> & descript_files ,string name_file );//, int id_file)
    void get_heatmap_file (const char*& , const string  & , vector < const string > & );
	void get_heatmap_file (string & , const string  & , vector < boost::filesystem3::path > & );
	void read_list(const boost::filesystem3::path & directory,const string classe, string type,const string categorie, vector<const string>  &files_name);

	std::string getClassName() const;
    std::vector<float> getData() const;
	int	cols() { return data.size(); }
	
	 std::string GetFileExtension(const std::string& FileName)
		{
			if(FileName.find_last_of(".") != std::string::npos)
			 return FileName.substr(FileName.find_last_of(".")+1);
			 return "";
		}
	 bool check_char_line ( std::string line )
	 {
		 bool is_string=false;
		 const char*p=line.c_str();
		 for( int i =0; i<line.length();i++)
		 {
				if(p[0]==' ' || p[i]=='.' || p[i]=='_' )
					is_string=true;

		 }
		 return is_string;
	 }
	 double convert_from_string(const string &number)
	 {
		 std::string separator=",";
		 unsigned found=number.rfind(separator);
		 if(found!=std::string::npos)
		 {
			 number.replace(found,separator.length (),",");
				
		 }
		 double decimal=boost::lexical_cast <float>(number);
		 return decimal;
	 }
	};
