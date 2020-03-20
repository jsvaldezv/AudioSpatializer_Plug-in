#pragma once

#define smoothingGeneric 0.04
#define smoothingFine 0.002

const static double MPI = 3.14159265358979323846;
const static double MPI2 = 3.14159265358979323846/2;
const static double MPI4 = 3.14159265358979323846/4;

inline float linear_interp(float v0, float v1, float t)
{
    return (1-t) * v0 + t * v1;
}
