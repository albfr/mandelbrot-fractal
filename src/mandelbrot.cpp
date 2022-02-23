#include <bits/stdc++.h>
#define R first
#define I second
typedef short int si;
using namespace std;
const int sizex = 1920*40;
const int sizey = 1080*40;
const int maxit = 50;
const int color_pattern = 10;
int color(double x, double y)
{
	pair<double, double> z;
	z = make_pair(x, y);
	double aux;
	si i=0;
	while(sqrt(z.R*z.R + z.I*z.I) < 2 && i < maxit)
	{
		aux = z.R*z.R - z.I*z.I + x; // a**2 - b**2
		z.I = 2*z.R*z.I + y; // 2ab
		z.R = aux;
		++i;
	}
	int color;
	if (i == maxit) color = 0;
	else color =  (i%color_pattern+2)*255*color_pattern / (maxit);
	return color;	
}
int main()
{
	ofstream img ("mandelbrot.ppm");
	img << "P3" << endl;
	img << sizex << " " << sizey << endl;
	img << "255" << endl;
	int pix;
	double px, py;
	for(int y=-sizey/2;y<sizey/2;++y)
	{
		for(int x=-sizex/2;x<sizex/2;++x)
		{
			px = x;
			px /= 4000;
			py = y;
			py /= 4000;	
			pix = color(px, py);
			img << pix << " " << pix << " " << pix << " ";
		}
		img << "\n";
	}
	cout << "Done :D\n";
}
