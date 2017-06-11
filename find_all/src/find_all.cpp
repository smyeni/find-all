#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std::placeholders;


void predicate(double elem, double threshold, std::vector<double> &v)
{
	if (elem >= threshold)
	{
		v.push_back(elem);
		std::cout << "found " << v.size() << " entries\n";
	} 
}

int main()
{
	std::vector<double> dvec;
	dvec.push_back(0);
	dvec.push_back(1);
	dvec.push_back(2);
	dvec.push_back(3);
	dvec.push_back(4);
	dvec.push_back(5);
	dvec.push_back(6);
	dvec.push_back(7);
	dvec.push_back(8);
	dvec.push_back(9);
	dvec.push_back(10);

	std::vector<double> res;
	//std::for_each( dvec.begin(), dvec.end(), [&] (double d) { if (d>=5) {v.push_back(d);} } );
	std::function< void(double) > pred5 = std::bind( predicate, _1, 5, std::ref(res) );
	std::for_each( dvec.begin(), dvec.end(), pred5 );

	std::cout << "\nOutput: " << res.size() << " entries\n";
	for (auto elem : res)
	{
		std::cout << elem << '\n';
	}

	return 0;
}
