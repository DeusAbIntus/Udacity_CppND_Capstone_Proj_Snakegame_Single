#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include <string>
#include <vector>

class Food
{
private: 
    std::string type{"Normal"};
    int value{1};
    std::vector<int> colour{255, 255, 0}; // vector containg the rgb values for the colour yellow
    
public:
    int x_pos, y_pos;
    Food(int x, int y) : x_pos(x), y_pos(y) {} // Constructor   
 // Getters
    std::string GetType() { return this->type; }
    int GetFoodValue() { return this->value; }
    std::vector<int> GetColour() { return this->colour; }
 // Setters
    void SetType(std::string type) { this->type = type; }
    void SetFoodValue(int n) { this->value = n; }
    void SetColour(std::vector<int>&& v) { this->colour = std::move(v); }
};




#endif

