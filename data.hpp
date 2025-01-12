#ifndef DATA_HPP
#define DATA_HPP

struct Spacecraft {
    int id; // unique identifier
    int length; // lenght in m
    int weight; // weight in tons
	int max_speed; // max speed in km/h
	int cruise_speed; // cruise speed in km/h
	int price; // price in US dollar
    int release_year; 
	std::string brand; 
	std::string model;  
	std::string color;
	std::string type; 
};

#endif // DATA_HPP