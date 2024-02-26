#include "TetraZig.h"

TetraZig::TetraZig()
{
	this->rotations = { {{0,0}, {0,1}, {1,1}, {1,2}},
						{{0,1}, {1,1}, {1,0}, {2,0}}};
}
