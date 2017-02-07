/* Name: Matthew Matze
 * Date: 2-28-14
 * Class: CSC1720
 * Location:~/csc1720/assign5/vector_t.cpp
 * 
 * Vector_t Class definition.
*/

#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;


vector_t::vector_t():x(0),y(0),z(0)
{}

vector_t::vector_t(double newx,double newy, double newz):x(newx),y(newy),z(newz)
{}

vector_t::~vector_t()
{}
   
void vector_t::setx (double newx)
{
   x=newx;
}
void vector_t::sety (double newy)
{
   y=newy;
}
void vector_t::setz (double newz)
{
   z=newz;
}

double vector_t::getx(void)
{
   return x;
}
double vector_t::gety(void)
{
   return y;
}
double vector_t::getz(void)
{
   return z;
}

vector_t vector_t::operator-(const vector_t& b) const
{
   vector_t c;
   c.x = this->x - b.x;
   c.y = this->y - b.y;
   c.z = this->z - b.z;
   return c;
}
double vector_t::len()
{
   double len;
   len = sqrt((this->x * this->x)+(this->y * this->y)+(this->z * this->z));
   return len;
}

vector_t vector_t::scale(double scalenum)
{
   vector_t scale;
   scale.x = this->x * scalenum;
   scale.y = this->y * scalenum;
   scale.z = this->z * scalenum;
   return scale;
}

vector_t vector_t::unit()
{
   double len;
   len = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
   vector_t unit;
   unit.x=(1/len) * this->x;
   unit.y=(1/len) * this->y;
   unit.z=(1/len) * this->z;
   return unit;
}
double vector_t::dot(vector_t b)
{
   double dotvalue;
   vector_t dot;
   dot.x=this->x * b.x;
   dot.y=this->y * b.y;
   dot.z=this->z * b.z;
   dotvalue= dot.x + dot.y + dot.z;
   return dotvalue;
}
istream& operator>>(istream &in, vector_t &c)
{
   char i;
   double x,y,z;
   in>>i;
   if(i!='<')
      cerr<<"Not a Vector"<<endl;
   in>>x;
   c.setx(x);
   in>>i;
   if(i!=',')
      cerr<<"Not a Vector"<<endl;
   in>>y;
   c.sety(y);
   in>>i;
   if(i!=',')
      cerr<<"Not a Vector"<<endl;
   in>>z;
   c.setz(z);
   in>>i;
   if(i!='>')
      cerr<<"Not a Vector"<<endl;

    return in;

};

ostream& operator<<(ostream &out, vector_t &c)
{
   out<<'<'<<setprecision(3)<<c.getx()<<","<<c.gety()<<","<<c.getz()<<'>';
   return out;

};

   
