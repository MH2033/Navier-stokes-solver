#include "NavierStokes.hpp"

// Main function.
int
main(int argc, char *argv[])
{
  Utilities::MPI::MPI_InitFinalize mpi_init(argc, argv);
  
  std::cout << "Working" << std::endl;
  return 0;

  const std::string  mesh_file_name  = "../mesh/mesh-step-5.msh";
  const unsigned int degree_velocity = 2;
  const unsigned int degree_pressure = 1;

  NavierStokes problem(mesh_file_name, degree_velocity, degree_pressure);

  problem.setup();
  problem.assemble_matrices();
  problem.solve();

  return 0;
}