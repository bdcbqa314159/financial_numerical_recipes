#pragma once

#include <cmath>
#include <vector>

double cash_flows_pv_discrete(const std::vector<double> &, const std::vector<double> &, const double &);
double cash_flows_irr_discrete(const std::vector<double> &, const std::vector<double> &);
