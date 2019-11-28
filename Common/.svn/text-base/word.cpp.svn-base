#include "StdAfx.h"
#include "word.h"


word::word(void)
{
	word::center=nearest_clusters();
	word::fileid=0;
	word::ptx=0;
	word::pty=0;
	word::scale=0;
}
void word ::Initialize_word()
{
	word::center=nearest_clusters();
	word::fileid=0;
	word::ptx=0;
	word::pty=0;
	word::scale=0;


}

word::~word(void)
{
}
nearest_clusters word::get_nearest_cluster()
{
	return word::center;
}
float word::get_point_x()
{
	return word::ptx;
}
float word::get_point_y()
{
	return word::pty;
}
double word::get_scale()
{
	return word::scale;
}
float word::get_fileid()
{
	return word::fileid;
}
void word::set_nearest_cluster( nearest_clusters center1)
{
	word::center=center1;
}
void word::set_point_x( float ptx)
{
	word::ptx=ptx;
}
void word::set_point_y(float pty)
{
	word::pty=pty;
}
void word::set_scale( double scale)
{
	word::scale=scale;

}
void word::set_fileid(float imgid)
{
	word::fileid=imgid;
}

