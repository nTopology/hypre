/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/





/******************************************************************************
 *
 * Header info for CSR Block Matrix data structures
 *
 * Note: this matrix currently uses 0-based indexing.
 * Note: everything is in terms of blocks (ie. num_rows is the number
 *       of block rows)
 *
 *****************************************************************************/


#ifndef hypre_CSR_BLOCK_MATRIX_HEADER
#define hypre_CSR_BLOCK_MATRIX_HEADER

#include "seq_mv.h"
#include "_hypre_utilities.h"
                                                                                                               
#ifdef __cplusplus
extern "C" {
#endif
                                                                                                               

/*--------------------------------------------------------------------------
 * CSR Block Matrix
 *--------------------------------------------------------------------------*/

typedef struct
{
  HYPRE_Real	        *data;
  HYPRE_Int                   *i;
  HYPRE_Int                   *j;
  HYPRE_Int                   block_size;
  HYPRE_Int     		num_rows;
  HYPRE_Int     		num_cols;
  HYPRE_Int                   num_nonzeros;

  HYPRE_Int                   owns_data;

} hypre_CSRBlockMatrix;

/*--------------------------------------------------------------------------
 * Accessor functions for the CSR Block Matrix structure
 *--------------------------------------------------------------------------*/

#define hypre_CSRBlockMatrixData(matrix)         ((matrix) -> data)
#define hypre_CSRBlockMatrixI(matrix)            ((matrix) -> i)
#define hypre_CSRBlockMatrixJ(matrix)            ((matrix) -> j)
#define hypre_CSRBlockMatrixBlockSize(matrix)    ((matrix) -> block_size)
#define hypre_CSRBlockMatrixNumRows(matrix)      ((matrix) -> num_rows)
#define hypre_CSRBlockMatrixNumCols(matrix)      ((matrix) -> num_cols)
#define hypre_CSRBlockMatrixNumNonzeros(matrix)  ((matrix) -> num_nonzeros)
#define hypre_CSRBlockMatrixOwnsData(matrix)     ((matrix) -> owns_data)

/*--------------------------------------------------------------------------
 * other functions for the CSR Block Matrix structure
 *--------------------------------------------------------------------------*/

hypre_CSRBlockMatrix 
      *hypre_CSRBlockMatrixCreate(HYPRE_Int, HYPRE_Int, HYPRE_Int, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixDestroy(hypre_CSRBlockMatrix *);
HYPRE_Int hypre_CSRBlockMatrixInitialize(hypre_CSRBlockMatrix *);
HYPRE_Int hypre_CSRBlockMatrixSetDataOwner(hypre_CSRBlockMatrix *, HYPRE_Int);
hypre_CSRMatrix 
      *hypre_CSRBlockMatrixCompress(hypre_CSRBlockMatrix *);
hypre_CSRMatrix 
      *hypre_CSRBlockMatrixConvertToCSRMatrix(hypre_CSRBlockMatrix *);
hypre_CSRBlockMatrix
      *hypre_CSRBlockMatrixConvertFromCSRMatrix(hypre_CSRMatrix *, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockAdd(HYPRE_Real *, HYPRE_Real *, HYPRE_Real*, HYPRE_Int);

HYPRE_Int hypre_CSRBlockMatrixBlockMultAdd(HYPRE_Real *, HYPRE_Real *, HYPRE_Real, HYPRE_Real *, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockMultAddDiag(HYPRE_Real *, HYPRE_Real *, HYPRE_Real, HYPRE_Real *, HYPRE_Int);
HYPRE_Int
hypre_CSRBlockMatrixBlockMultAddDiag2(HYPRE_Real* i1, HYPRE_Real* i2, HYPRE_Real beta, 
                                      HYPRE_Real* o, HYPRE_Int block_size);
HYPRE_Int
hypre_CSRBlockMatrixBlockMultAddDiag3(HYPRE_Real* i1, HYPRE_Real* i2, HYPRE_Real beta, 
                                      HYPRE_Real* o, HYPRE_Int block_size);
   

HYPRE_Int hypre_CSRBlockMatrixBlockInvMult(HYPRE_Real *, HYPRE_Real *, HYPRE_Real *, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockInvMultDiag(HYPRE_Real *, HYPRE_Real *, HYPRE_Real *, HYPRE_Int);

HYPRE_Int
hypre_CSRBlockMatrixBlockInvMultDiag2(HYPRE_Real* i1, HYPRE_Real* i2, HYPRE_Real* o, HYPRE_Int block_size);
   
HYPRE_Int
hypre_CSRBlockMatrixBlockInvMultDiag3(HYPRE_Real* i1, HYPRE_Real* i2, HYPRE_Real* o, HYPRE_Int block_size);
   



HYPRE_Int hypre_CSRBlockMatrixBlockMultInv(HYPRE_Real *, HYPRE_Real *, HYPRE_Real *, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockTranspose(HYPRE_Real *, HYPRE_Real *, HYPRE_Int);

HYPRE_Int hypre_CSRBlockMatrixTranspose(hypre_CSRBlockMatrix *A,
                                  hypre_CSRBlockMatrix **AT, HYPRE_Int data);

HYPRE_Int hypre_CSRBlockMatrixBlockCopyData(HYPRE_Real*, HYPRE_Real*, HYPRE_Real, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockCopyDataDiag(HYPRE_Real*, HYPRE_Real*, HYPRE_Real, HYPRE_Int);

HYPRE_Int hypre_CSRBlockMatrixBlockAddAccumulate(HYPRE_Real*, HYPRE_Real*, HYPRE_Int);
HYPRE_Int hypre_CSRBlockMatrixBlockAddAccumulateDiag(HYPRE_Real* i1, HYPRE_Real* o, HYPRE_Int block_size);
   


HYPRE_Int
hypre_CSRBlockMatrixMatvec(HYPRE_Real alpha, hypre_CSRBlockMatrix *A,
                           hypre_Vector *x, HYPRE_Real beta, hypre_Vector *y);
   

HYPRE_Int
hypre_CSRBlockMatrixMatvecT( HYPRE_Real alpha, hypre_CSRBlockMatrix *A, hypre_Vector  *x,
                             HYPRE_Real beta, hypre_Vector *y );

HYPRE_Int
hypre_CSRBlockMatrixBlockInvMatvec(HYPRE_Real* mat, HYPRE_Real* v, 
                                   HYPRE_Real* ov, HYPRE_Int block_size);
   
HYPRE_Int 
hypre_CSRBlockMatrixBlockMatvec(HYPRE_Real alpha, HYPRE_Real* mat, HYPRE_Real* v, HYPRE_Real beta, 
                                HYPRE_Real* ov, HYPRE_Int block_size);
   

HYPRE_Int hypre_CSRBlockMatrixBlockNorm(HYPRE_Int norm_type, HYPRE_Real* data, HYPRE_Real* out, HYPRE_Int block_size);
   
HYPRE_Int hypre_CSRBlockMatrixBlockSetScalar(HYPRE_Real* o, HYPRE_Real beta, HYPRE_Int block_size);
   
HYPRE_Int hypre_CSRBlockMatrixComputeSign(HYPRE_Real *i1, HYPRE_Real *o, HYPRE_Int block_size);
HYPRE_Int hypre_CSRBlockMatrixBlockAddAccumulateDiagCheckSign(HYPRE_Real* i1, HYPRE_Real* o, HYPRE_Int block_size, HYPRE_Real *sign);
HYPRE_Int hypre_CSRBlockMatrixBlockMultAddDiagCheckSign(HYPRE_Real* i1, HYPRE_Real* i2, HYPRE_Real beta, 
                                              HYPRE_Real* o, HYPRE_Int block_size, HYPRE_Real *sign);
   




#ifdef __cplusplus
}
#endif
#endif
