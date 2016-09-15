#include "Containers.h"

Containers::Containers() : leftBorder(1), rightBorder(9) {
	limitDeletions = 15;
	sizeOfContainers = makeRandomDigit(15, 20);
}

Containers::Containers(size_t sizeOfContainers) : leftBorder(1), rightBorder(9) {
	this->limitDeletions = 15;
	this->sizeOfContainers = sizeOfContainers;
}

size_t Containers::makeRandomDigit(size_t leftBorder, size_t rightBorder) const {
	return rand() % rightBorder + leftBorder;
}

void Containers::randomFill() {
	srand(time(0));
	for (size_t i = 0; i < sizeOfContainers; ++i) {
		vectorContainer.push_back(makeRandomDigit(leftBorder, rightBorder));
		mapContainer.insert(pair<size_t, size_t>(i, makeRandomDigit(leftBorder, rightBorder)));
	}
}

void Containers::deleteRandomAmountOfElements() {
	if (sizeOfContainers < limitDeletions) {
		limitDeletions = sizeOfContainers;
	}
	size_t amountOfDeletions = makeRandomDigit(0, limitDeletions);

	vectorContainer.erase(vectorContainer.begin(), vectorContainer.begin() + amountOfDeletions);
	for (size_t i = 0; i < amountOfDeletions; ++i) {
		mapContainer.erase(i);
	}
}

void Containers::synchronizeContainers() {
	std::sort(vectorContainer.begin(), vectorContainer.end());
	synchronizeMap();
	synchronizeVector();
}

void Containers::synchronizeVector() {
	vector<size_t>::iterator iterVec = vectorContainer.begin();
	bool isFound = false;

	for (iterVec = vectorContainer.begin(); iterVec < vectorContainer.end();) {
		for (pair<size_t, size_t> j : mapContainer) {
			if (j.second == (*iterVec)) {
				isFound = true;
				++iterVec;
				break;
			}
		}
		if (!isFound) {
			iterVec = vectorContainer.erase(iterVec);
		}
		isFound = false;
	}
}

void Containers::synchronizeMap() {
	map<size_t, size_t>::iterator iterMap = mapContainer.begin();
	bool isFound = false;

	for (iterMap = mapContainer.begin(); iterMap != mapContainer.end();) {
		isFound = std::binary_search(vectorContainer.begin(), vectorContainer.end(), iterMap->second);
		if (!isFound) {
			iterMap = mapContainer.erase(iterMap);
		} else {
			++iterMap;
		}
	}
}

void Containers::showContainers() const {
	size_t i = 0;
	cout << "vector:\t";
	for (size_t i = 0; i < vectorContainer.size(); ++i) {
		cout << vectorContainer[i] << " ";
	}
	cout << endl << "map:\t";
	for (auto iter = mapContainer.begin(); iter != mapContainer.end(); ++iter) {
		cout << iter->second << " ";
	}
	cout << "\n\n";
}