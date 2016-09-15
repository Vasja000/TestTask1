#include "Containers.h"

void main() {
	Containers containers(30);

	containers.randomFill();
	containers.showContainers();
	containers.deleteRandomAmountOfElements();
	containers.synchronizeContainers();
	containers.showContainers();

	system("pause >> void");
}