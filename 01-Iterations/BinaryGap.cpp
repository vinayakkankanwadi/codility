#include <iostream>
#include <string>
#include <cassert>

std::string decToBinary(int N);

int solution(int N) {
	std::string bin;
	int largestCount = 0, counter = 0;
	bool flag = false;

	bin = decToBinary(N);
	while (!bin.empty())
	{
		if (bin[bin.length() - 1] == '1' && flag == false)
		{
			flag = true;
		}
		else if (flag == true && bin[bin.length() - 1] == '0')
		{
			counter++;
		}
		else
		{
			if (counter > largestCount)
			{
				largestCount = counter;
			}
			counter = 0;
		}
		// remove last charcater
		bin = bin.substr(0, bin.length() - 1);
	}
	return largestCount;

}

std::string decToBinary(int N)
{
	std::string bin;
	while (N > 0)
	{
		bin = std::to_string(N % 2) + bin;
		N = N / 2;
	}
	return bin;
}