#ifndef CONVERT_KNOTS_HPP
#define CONVERT_KNOTS_HPP

double knots_to_miles_per_minute(int knot)
{
    return knot * 6076.0 / 5280.0 / 60.0;
}

#endif