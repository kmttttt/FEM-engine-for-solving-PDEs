#include <iostream>
#include <Eigen/Sparse>
#include "mesh_generator.h"

int main() {
    // Define a sparse matrix of doubles
    Eigen::SparseMatrix<double> K(1000, 1000);
    
    std::cout << "Successfully integrated Eigen!" << std::endl;
    std::cout << "Global Stiffness Matrix K dimensions: " 
              << K.rows() << " x " << K.cols() << std::endl;
    Mesh1D mesh(1.0, 0.0, 100);
    auto uniform_mesh = mesh.generateUniform();
    std::cout << "Generated uniform mesh with " << uniform_mesh.size() << " points." << std::endl;
    return 0;
}