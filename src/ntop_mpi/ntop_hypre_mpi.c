
#include <ntop_hypre_mpi.h>


#ifdef __cplusplus
extern "C" {
#endif

NTOP_DLL_EXPORT
void ntop_hypre_init_mpi()
{
  int isInit = 0;
  MPI_Initialized(&isInit);
  if (!isInit)
  {
    int myid, num_procs;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
  }

}

NTOP_DLL_EXPORT void ntop_hypre_finalize_mpi()
{
  MPI_Finalize();
}


#ifdef __cplusplus
}
#endif
