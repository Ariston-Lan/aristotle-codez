#pragma once
#include <string>

float get_temp();
float faren_to_cels(float farenheit);
bool is_freezing(float farenheit);
bool is_boiling(float farenheit);
std::string get_temp_category(float F);
void temperature_analyzer();