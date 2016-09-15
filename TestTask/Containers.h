#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

class Containers {
private:
	vector<size_t>		vectorContainer;
	map<size_t, size_t>	mapContainer;
	const size_t		leftBorder;
	const size_t		rightBorder;
	size_t				limitDeletions;
	size_t				sizeOfContainers;

	size_t	makeRandomDigit(const size_t leftBorder, const size_t rightBorder) const;
	void	synchronizeVector();
	void	synchronizeMap();
public:
	Containers();
	Containers(size_t sizeOfContainers);
	void randomFill();
	void deleteRandomAmountOfElements();
	void synchronizeContainers();
	void showContainers() const;
};