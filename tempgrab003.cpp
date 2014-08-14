#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>

int main()
{
        std::ifstream rawTempIn;
	rawTempIn.open("/sys/bus/w1/devices/28-00000566b6ac/w1_slave", std::ifstream::in);
	if(!rawTempIn.is_open())
	{
		std::cout << "didn\'t open temp probe file!" << std::endl;
		return 1;
	}

	std::string stringBuffer1;
	
	rawTempIn.seekg(69);

	char cInChar;
	while(rawTempIn.get(cInChar))
	{
		stringBuffer1 += cInChar;
	}

	int tempInt;
	double fTemp;
	std::istringstream buffer2(stringBuffer1);
	buffer2 >> tempInt;	
	fTemp = (double(tempInt)) / 1000;

	//std::cout << fTemp << std::endl;

	std::time_t tNow;
	//std::chrono::system_clock::time_point cpptNow =	std::chrono::system_clock::now();
	//tNow = std::chrono::system_clock::to_time_t(cpptNow);
	std::cout << time(&tNow) << "  " << fTemp << std::endl;

return 0;
}
