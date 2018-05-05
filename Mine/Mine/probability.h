// probability.h
#pragma once
#include <vector>

template <typename T>
class Probability
{
public:
	Probability(size_t range = 100);
	~Probability();

	void Insert(const T * new_item);
	const T * Draw();

private:
	struct Slot
	{
		T * id;
		size_t probability;
	};

	std::vector<Slot> slots_;
	size_t range_;
};
