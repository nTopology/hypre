################################################################################

if(TARGET HYPRE)
	return()
endif()

################################################################################

set(HYPRE_SEQUENTIAL   OFF CACHE INTERNAL "" FORCE)
set(HYPRE_PRINT_ERRORS  ON CACHE INTERNAL "" FORCE)
set(HYPRE_BIGINT       OFF CACHE INTERNAL "" FORCE)
set(HYPRE_USING_FEI    OFF CACHE INTERNAL "" FORCE)
set(HYPRE_USING_OPENMP OFF CACHE INTERNAL "" FORCE)
set(HYPRE_SHARED        ON CACHE INTERNAL "" FORCE)
# set(HYPRE_LONG_DOUBLE ON)

set(HYPRE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE INTERNAL "" FORCE)
set(OLD_BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS} CACHE INTERNAL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src hypre)
set_property(TARGET HYPRE PROPERTY FOLDER "dependencies")

target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/hypre)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/blas)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lapack)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utilities)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/multivector)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/krylov)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/seq_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/parcsr_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/parcsr_block_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/distributed_matrix)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/IJ_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix_matrix)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/distributed_ls)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/distributed_ls/Euclid)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/distributed_ls/ParaSails)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/parcsr_ls)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/struct_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/struct_ls)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/sstruct_mv)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/sstruct_ls)
target_include_directories(HYPRE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/ntop_mpi)

add_library(hypre INTERFACE)
target_link_libraries(hypre INTERFACE HYPRE)

if(HYPRE_USING_OPENMP)
	find_package(OpenMP QUIET REQUIRED)
	target_link_libraries(hypre INTERFACE OpenMP::OpenMP_CXX)
endif()

if(NOT HYPRE_SEQUENTIAL)
	find_package(MPI)
	if(MPI_CXX_FOUND)
		target_link_libraries(hypre INTERFACE MPI::MPI_CXX)
	endif()
endif()

set(BUILD_SHARED_LIBS ${OLD_BUILD_SHARED_LIBS} CACHE INTERNAL "" FORCE)
