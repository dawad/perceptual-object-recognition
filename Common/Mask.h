#pragma once
class Mask
{
private :
	double x_value;
	double y_value;
	int mask;
	double threshold;
	int fileId;
public:
	Mask(void);
	~Mask(void);
	/// getters functions
	double get_x_value ();
	double get_y_value ();
	int get_mask();
	double get_threshold();
	int get_fileId();
	/// setters 
	void set_x_value( double _x);
	void set_y_value( double _y);
	void set_mask(int _mask);
	void set_threshold(double _threshold);
	void set_fileId(int _fileid);
};

