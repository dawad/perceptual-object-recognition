#include "StdAfx.h"
#include "Donnees.h"


#include <cv.h>
#include <highgui.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <boost/algorithm/string.hpp>
#include "../Fichiers.h"
using namespace cv;
using namespace std;

/*
 * Constructeur par defaut
 */
Donnees::Donnees(void)
{
}


Donnees::~Donnees(void)
{
}
Fichiers file;
/*
 * Constructeur par fichier ARFF
 */
Donnees::Donnees(std::string ARFFFileName)
{
	file.readARFF(ARFFFileName);
	data=NULL;
	res=NULL;
}

/*
 * Methode utilitaire de transformation de
 * nom de classe en equivalent numerique
 */
 int	Donnees::classNumber(const std::string className)
{
	return (std::find(this->classeNames.begin(), this->classeNames.end(), className))
			- this->classeNames.begin() + 1;
}
/*
 * Conversion de la base des echantillons en matrice OpenCV
 *
 * ATTENTION : il faut liberer la memoire associee a data
 */
void Donnees::getDataMat(CvMat & data_mat)
{
	data = new float[this->rows()*this->cols()];
	std::copy(this->vectors.begin(),this->vectors.end(),data);
	cvInitMatHeader (&data_mat, this->rows() ,this->cols(), CV_32FC1, data);
}

/*
 * Conversion de la base des classes en vecteur OpenCV
 *
 * ATTENTION : il faut liberer la memoire associee a res
 */
void Donnees::getResMat(CvMat & res_mat)
{
	res = new int[this->rows()];
	std::copy(this->classeNumbers.begin(),this->classeNumbers.end(),res);
	cvInitMatHeader (&res_mat, this->rows() , 1, CV_32SC1, res);
}


/*
 * Getters
 */
std::vector<std::string> Donnees::getClasses() const { return classes; }
std::vector<float> Donnees::getVectors() const { return vectors; }
std::vector<std::string> Donnees::getClasseNames() const { return classeNames; }
std::vector<int> Donnees::getClasseNumbers() const { return classeNumbers; }
std::string Donnees:: get_className_by_indice (int indice ) { return this->classes[indice]; }
