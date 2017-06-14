#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std::placeholders;


class Predicate
{
	public:
		void operator()(double elem, double threshold, std::vector<double> &v)
		{
			if (elem >= threshold)
			{
				v.push_back(elem);
			} 
		}
};


int main( int argc, char** args )
{
	if (argc < 2)
	{
		std::cout << "\nUsage: " << args[0] << " <threshold>\n";
		return 0;
	}

	double threshold = std::stod(args[1]);

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

	Predicate predicate;
	std::vector<double> res;

	std::function< void(double) > pred = std::bind( predicate, _1, threshold, std::ref(res) );

	std::for_each( dvec.begin(), dvec.end(), pred );

	unsigned n = std::count_if( dvec.begin(), dvec.end(), [&] (const int& item) { return (item >= threshold); } );
	std::cout << "\nOutput: " << res.size() << " (" << n << ") entries\n";
	for (auto elem : res)
	{
		std::cout << elem << '\n';
	}

	return 0;
}
