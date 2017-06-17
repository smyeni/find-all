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

	std::vector<double> dvec{-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};

	Predicate predicate;
	std::vector<double> res;

	std::function< void(double) > pred = std::bind( predicate, _1, threshold, std::ref(res) );

	std::for_each( dvec.begin(), dvec.end(), pred );

	unsigned n = std::count_if( dvec.begin(), dvec.end(), [&] (const int item) { return (item >= threshold); } );
	std::cout << "\nOutput: " << res.size() << " (" << n << ") entries\n";
	for (auto elem : res)
	{
		std::cout << elem << '\n';
	}

	return 0;
}
