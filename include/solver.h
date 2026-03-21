#ifndef SOLVER_H
#define SOLVER_H

#include <Eigen/Sparse>
#include <vector>

class solverCN{
    public:

    solverCN(Eigen::SparseMatrix<double> k , Eigen::SparseMatrix<double> m);
    std::vector<std::pair<double,Eigen::VectorXd>> Crank_Nicolson(double b_val1, double b_val2,double t_step,double t,  Eigen::VectorXd To);

    private:

    Eigen::SparseMatrix<double> K ,M;
};

#endif
