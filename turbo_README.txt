hypre for Tubro
===============

This is a fork of hypre (https://github.com/LLNL/hypre) in the nTopology
organization. Minor changes have been made to hypre to build as a dll
linkable into Turbo. The changes can be tracked in the github repository
(https://github.com/nTopology/hypre). 

The minor changes include:
- exporting hypre functions needed by Turbo
- small fixes to the hypre dll build
- initializing mpi in the hypre dll

Recommended instructions to build for Turbo:

Windows
-------

Requirements:

- MSMPI SDK

Steps:

- create a new folder, say 'build'
- cd build
- cmake -G"Visual Studio 15 2017 Win64" ..\src\
- build with Visual Studio in release configuration
- run install target from Visual Studio
- compiled libraries and headers will be in src/hypre

