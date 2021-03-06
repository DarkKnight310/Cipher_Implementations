//All inputs are harcoded
//x is the 16-bit plain text in decimal form
//k is the pointer to the 16-bit keys, and each key is is expressed in decimal form. 
//keys can also be modified by taking inputs which require a bit of change in code
//rest all is implemented using simple binary operators


#include <iostream>

using namespace std;

int main ()
{
	int i, j;
	int k[5] = {14996, 43341, 38102, 19811, 54847};
	int	x = 9911, w, u, v, y;
	int s[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
	int p[16] = {1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16};
	int a[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768}; 
	// this array helps to access the bit at any required position using a simple bit wise & operation	
	w = x;
	for(i = 0; i < 4; i++)
	{
		u = w ^ k[i];
		v = s[(u & 15)];
		u >>= 4;
		v += (s[(u & 15)]) * 16;
		u >>= 4;
		v += (s[u & 15]) * 256;
		u >>= 4;
		v += (s[u & 15]) * (256*16);
		w = 0;
		for(j = 15; j >= 0; j--)
		{
			w += ((v & a[16 - p[j]]) * a[15 - j]);
		}
	}

	y = v ^ k[4];
	cout << y << endl;
	return 0;
}
