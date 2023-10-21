#include "time_value.hpp"

double cash_flows_pv_discrete(const std::vector<double>& cflow_times, const std::vector<double>& cflow_amounts, const double& r){

    double PV{};
    if (cflow_amounts.size()!=cflow_times.size()) return PV;
    for (int t = 0; t<cflow_times.size(); t++)
        PV+=cflow_amounts[t]/std::pow(1.+r, cflow_times[t]);
    return PV;
}

double cash_flows_irr_discrete(const std::vector<double> &cflow_times, const std::vector<double> &cflow_amounts)
{
    const double ERROR = -1e30;
    if (cflow_times.size()!=cflow_amounts.size()) return ERROR;
    const double ACCURACY = 1e-5;
    const int MAX_ITERATIONS = 50;

    double x1 = 0., x2 = 0.2;

    double f1 = cash_flows_pv_discrete(cflow_times,cflow_amounts,x1);
    double f2 = cash_flows_pv_discrete(cflow_times, cflow_amounts, x2);

    for (int i = 0; i<MAX_ITERATIONS; i++){
        if (f1*f2<0.) break;
        if (fabs(f1)<fabs(f2))
            f1 = cash_flows_pv_discrete(cflow_times, cflow_amounts, x1 += 1.6*(x1-x2));
        else
            f2 = cash_flows_pv_discrete(cflow_times, cflow_amounts, x2 += 1.6 * (x2 - x1));
    }

    if (f2*f1>0.) return ERROR;
    double f = cash_flows_pv_discrete(cflow_times, cflow_amounts, x1);
    double rtb = 0., dx = 0.;
    if (f<0.){
        rtb = x1;
        dx = x2-x1;
    }
    else{
        rtb = x2;
        dx = x1-x2;
    }

    for (int i = 0; i<MAX_ITERATIONS; i++){
        dx *= 0.5;
        double x_mid = rtb+dx;
        double f_mid = cash_flows_pv_discrete(cflow_times, cflow_amounts, x_mid);
        if (f_mid<=0.) rtb = x_mid;
        if ( fabs(f_mid)<ACCURACY || fabs(dx)<ACCURACY) return x_mid;
    }
    return ERROR;
}
