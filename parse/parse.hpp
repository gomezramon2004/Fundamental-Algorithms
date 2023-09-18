#pragma once
#include <string>
#include <vector>

struct Info {
    time_t timeValue; /* Valor que cuenta en segundos desde el 01/01/1970 hasta la fecha corrrespondiente */
    struct tm dateTime; /* Struct que poseé los datos de nuestra fecha */
    char enterPoint;
    std::string ubi;
};

std::vector<Info> parse(std::string fileName);