#include"DMA.h"
int main()
{
	baseDMA shirt("Port", 8);
	lacksDMA balloon("red", "blimpo", 4);
	hasDMA map("mercator", "buffalo", 5);
	cout << shirt << endl;
	cout << balloon << endl;
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "基类对象赋值给派生类" << endl;
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << map2 << endl;
}