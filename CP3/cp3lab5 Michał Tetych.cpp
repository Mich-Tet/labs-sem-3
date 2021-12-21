
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Color
{
	float r, g, b;

	Color();
	Color(float r, float g, float b);
	~Color();
};
class MyBitmap
{
private:
	int width{0};
	int height{0};
	vector<Color> colors;
public:
	MyBitmap(int width, int height);
	~MyBitmap();

	Color GetColor(int x, int y) const;

	void setPixel(const Color& color, int row, int col);
	void Create(const char* path) const;
	void putPixel(const char* args);

};


Color::Color() : r(0), g(0), b(0)
{

}

Color::Color(float r, float g, float b) : r(r), g(g), b(b)
{
}

Color::~Color()
{
}

MyBitmap::MyBitmap(int width, int height) : width(width), height(height), colors(vector<Color> (width * height))
{
}

MyBitmap::~MyBitmap()
{
}

Color MyBitmap::GetColor(int x, int y) const
{
	return colors[y*width + x];
}

void MyBitmap::setPixel(const Color& color,int x, int y)
{
	colors[y * width + x].r = color.r;
	colors[y * width + x].g = color.g;
	colors[y * width + x].b = color.b;
}

void MyBitmap::Create(const char* path) const
{
	ofstream f;
	f.open(path, ios::out | ios::binary);

	if (!f.is_open())
	{
		cout << "File could not be opened." << endl;
		return; 
	}
	unsigned char bmpPAD[3] = { 0,0,0 };
	const int paddingAmount = ((4 - (width * 3) % 4) % 4);
	const int fileHeaderSize = 14;
	const int informationHeaderSize = 40;
	const int fileSize = fileHeaderSize+ informationHeaderSize +width*height*3+paddingAmount*height;

	unsigned char fileHeader[fileHeaderSize];

	fileHeader[0] = 'B';
	fileHeader[1] = 'M';
	fileHeader[2] = fileSize;
	fileHeader[3] = fileSize >> 8;
	fileHeader[4] = fileSize >> 16;
	fileHeader[5] = fileSize >> 24;
	fileHeader[6] = 0;
	fileHeader[7] = 0;
	fileHeader[8] = 0;
	fileHeader[9] = 0;
	fileHeader[10] = fileHeaderSize+ informationHeaderSize;
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;

	unsigned char informationHeader[informationHeaderSize];

	informationHeader[0] = informationHeaderSize;
	informationHeader[1] = 0;
	informationHeader[2] = 0;
	informationHeader[3] = 0;
	informationHeader[4] = width;
	informationHeader[5] = width >> 8;
	informationHeader[6] = width >> 16;
	informationHeader[7] = width >> 24;
	informationHeader[8] = height;
	informationHeader[9] = height >> 8;
	informationHeader[10] = height >> 16;
	informationHeader[11] = height >> 24;
	informationHeader[12] = 1;
	informationHeader[13] = 0;
	informationHeader[14] = 24;
	informationHeader[15] = 0;
	informationHeader[16] = 0;
	informationHeader[17] = 0;
	informationHeader[18] = 0;
	informationHeader[19] = 0;
	informationHeader[20] = 0;
	informationHeader[21] = 0;
	informationHeader[22] = 0;
	informationHeader[23] = 0;
	informationHeader[24] = 0;
	informationHeader[25] = 0;
	informationHeader[26] = 0;
	informationHeader[27] = 0;
	informationHeader[28] = 0;
	informationHeader[29] = 0;
	informationHeader[30] = 0;
	informationHeader[31] = 0;
	informationHeader[32] = 0;
	informationHeader[33] = 0;
	informationHeader[34] = 0;
	informationHeader[35] = 0;
	informationHeader[36] = 0;
	informationHeader[37] = 0;
	informationHeader[38] = 0;
	informationHeader[39] = 0;
	f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
	f.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			unsigned char r = static_cast<unsigned char>(GetColor(x, y).r * 255.0f);
			unsigned char g = static_cast<unsigned char>(GetColor(x, y).g * 255.0f);
			unsigned char b = static_cast<unsigned char>(GetColor(x, y).b * 255.0f);

			unsigned char color[] = { b,g,r };
			f.write(reinterpret_cast<char*>(color), 3);

		}
		f.write(reinterpret_cast<char*>(bmpPAD), paddingAmount);

	}
	f.close();
	cout << "File created." << endl;

}
void MyBitmap::putPixel(const char* args)
{
	ofstream myfile;
	myfile.open(args, ios::in | ios::binary);
	if (!myfile.is_open())
	{
		cout << "File could not be opened." << endl;
		return;
	}

	myfile.close();
}
int main()
{
	const int width = 600;
	const int height = 800;

	MyBitmap image(width, height);

	image.Create("image3.bmp");
}
