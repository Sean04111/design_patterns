#pragma once
#include <algorithm>
#include <array>
#include <numeric>

/* 这种传统的方式就比较蠢，如果有新增的属性的话，需要修改的函数就很多*/
class Creature_dumb
{
	int strength, agility, intelligence;
public:
	int get_strength() const
	{
		return strength;
	}

	void set_strength(int new_strength)
	{
		strength = new_strength;
	}

	int get_agility() const
	{
		return agility;
	}

	void set_agility(int new_agility)
	{
		agility = new_agility;
	}

	int get_intelligence() const
	{
		return intelligence;
	}

	void set_intelligence(int new_intelligence)
	{
		intelligence = new_intelligence;
	}


	int sum() const
	{
		return strength + agility + intelligence;
	}

	double average() const
	{
		return sum() / 3.0;
	}

	int max() const
	{
		return std::max(std::max(strength, agility), intelligence);
	}
};

/* 使用数组来管理属性 */

class Creature_nice
{
	static constexpr int count = 3;
	enum Abilities : int{ strength, agility, intelligence};
	std::array<int, count> abilities;

	int get_strength() const
	{
		return abilities[strength];
	}

	void set_strength(int new_strength)
	{
		abilities[strength] = new_strength;
	}

	int sum() const
	{
		return std::accumulate(abilities.begin(), abilities.end(), 0);
	}

	double average() const
	{
		return sum() / static_cast<double>(count);
	}

	int max() const
	{
		return *std::ranges::max_element(abilities.begin(), abilities.end());
	}

};