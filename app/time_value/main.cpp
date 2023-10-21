#include <iostream>

#include "time_value.hpp"

using namespace std;

int main()
{

    vector<double> cflows = {-100, 75, 75};
    vector<double> times = {0., 1., 2.};
    double r = 0.1;
    cout << " Present value, 10 percent discretely compounded interest = "<<endl;
    cout << cash_flows_pv_discrete(times, cflows, r)<<endl;

    cflows = {-100, 10, 110};
    r = 0.05;

    cout<<"PV, 5 per cent discretely compounded interest = "<<endl;
    cout<<cash_flows_pv_discrete(times,cflows, r)<<endl;
    cout<<"irr = "<<endl;
    cout<<cash_flows_irr_discrete(times,cflows)<<endl;;


    return 0;
}
