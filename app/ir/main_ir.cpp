#include "ir1.hpp"
#include <iostream>

using namespace std;

int main()
{

    std::cout << "Hello from Advanced Quantitative Finance with C++" << std::endl;

    double notional = 1e6;
    double K = 0.04;
    double alpha = 0.25;
    double sigma = 0.15;
    double dT = 0.25;

    int N = 3;
    int M = 1000;

    IR ir1(notional, K, alpha, sigma, dT, N, M);

    auto results = ir1.get_simulation_data();

    auto sz = results.datapoints.size();
    for (int nsim = 0; nsim < sz; nsim++)
        cout << "simIRS[" << nsim << "] = " << results.datapoints[nsim] << endl;

    cout << "IRS PV = " << results.value << endl;


    cout << "Working with a cap" << endl;

    IR ir2(0.05, 0.5, 0.15, 0.5, 4, 1000, true);
    auto results2 = ir2.get_simulation_data();
    auto sz2 = results2.datapoints.size();
    for (int nsim = 0; nsim < sz2; nsim++)
        cout << "simIRS[" << nsim << "] = " << results2.datapoints[nsim] << endl;

    cout << "IRS cap PV = " << results2.value << endl;

    return 0;
}
