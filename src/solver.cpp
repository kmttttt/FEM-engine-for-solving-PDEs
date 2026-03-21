#include <Eigen/Sparse>
#include <vector>

#include <solver.h>

solverCN::solverCN(Eigen::SparseMatrix<double> k , Eigen::SparseMatrix<double> m){
    K = k;
    M = m;
}

std::vector<std::pair<double,Eigen::VectorXd>> solverCN::Crank_Nicolson(double b_val1, double b_val2,double t_step,double t,  Eigen::VectorXd To){
    int n = K.rows()-1;
    Eigen::VectorXd T1(n+1); // T_n+1
    T1.setZero();
    double time = 0;        //initially time is zero

    Eigen::SparseMatrix<double> A,B;
    Eigen::VectorXd F;
    A = M + (t_step/2)*K;
    B = M - (t_step/2)*K;
    A.coeffRef(0,0) = 1e15;
    A.coeffRef(n,n) = 1e15;

    A.makeCompressed();
    B.makeCompressed();

    std::vector<std::pair<double,Eigen::VectorXd>> outP;
    outP.push_back({time,To});
    time = time +t_step;

    Eigen::SparseLU<Eigen::SparseMatrix<double>> solver;
    solver.compute(A);

    while(t>=time){
        F = B*To;
        F(0) = 1e15*b_val1;
        F(n) = 1e15*b_val2;

        T1 = solver.solve(F);
        if(solver.info() != Eigen::Success) break;
        To = T1;

        outP.push_back({time,To});
        time += t_step;
    }

    return outP;
}