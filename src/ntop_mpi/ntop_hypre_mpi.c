
#include <ntop_hypre_mpi.h>


#ifdef __cplusplus
extern "C" {
#endif

NTOP_DLL_EXPORT
void ntop_hypre_init_mpi(int myid, int num_procs)
{
  int isInit = 0;
  MPI_Initialized(&isInit);
  int myid2, num_procs2;
  if (!isInit)
  {
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid2);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs2);
  }
  MPI_Comm_rank(MPI_COMM_WORLD, &myid2);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs2);
  myid = myid2;
  num_procs = num_procs2;
}

NTOP_DLL_EXPORT void ntop_hypre_finalize_mpi()
{
  MPI_Finalize();
}


#ifdef __cplusplus
}
#endif
