#pragma once

#include <vector>
#include <string>
#include <cv.h>


class Donnees
{
public:
	Donnees(void);
	~Donnees(void);
	Donnees(std::string ARFFFileName);

    std::vector<std::string> 	getClasses() const;
    std::vector<float> 			getVectors() const;
    std::vector<std::string> 	getClasseNames() const;
    std::vector<int> 			getClasseNumbers() const;
    int							classNumber(std::string className);
    int							cols()	{ return col; }
    int							rows()	{ return vectors.size()/cols(); }
    void						getDataMat(CvMat & data_mat);
    void						getResMat(CvMat & res_mat);
    int							nbClasses() { return classeNames.size(); }
	void 						readARFF(std::string ARFFFileName);
    void  set_col( int colonne) { col=colonne;}
	std:: string get_className_by_indice (int indice );
private:
    int							col;
	std::vector<float> 			vectors;		// Vecteur contenant l'ensemble des echantillon
	std::vector<std::string> 	classes;		// Vecteur contenant le nom des categories associees a chaque echantillon
	std::vector<int> 			classeNumbers;	// Vecteur contenant la version numerique du vecteur precedant
	std::vector<std::string> 	classeNames;	// Liste des noms de categories
    CvMat 						data_mat;		// Matrice OpenCV equivalente
    CvMat						res_mat;		// Vecteur OpenCV equivalent
	float 						*data; 			// Pointeur interne pour conversion de donnees
	int							*res;			// Pointeur interne pour conversion de donnees
};


