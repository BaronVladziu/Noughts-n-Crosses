#include "header.h"
#include "Algorithm"
#include "TestAlgorithm.h"
#include "Tab.h"

TestAlgorithm::TestAlgorithm()
{}
int TestAlgorithm::get_point_value(const int i, const int j, const Tab & tab, const Mark mark)
{
	return 0;
}
const sf::Vector2i TestAlgorithm::execute(const Tab & tab, const Mark mark)
{
	sf::Vector2i v;
	do
	{
		v = { rand() % tab.get_width(), rand() % tab.get_height() };
	} while (tab.get(v.x, v.y) != Mark::V);
	return v;
}
void TestAlgorithm::save_data()
{}
TestAlgorithm::~TestAlgorithm()
{}