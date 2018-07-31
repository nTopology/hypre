#pragma once

#include <HYPRE_utilities.h>

#ifdef __cplusplus
extern "C" {
#endif

NTOP_DLL_EXPORT
void ntop_hypre_init_mpi();

NTOP_DLL_EXPORT
void ntop_hypre_finalize_mpi();


#ifdef __cplusplus
}
#endif
