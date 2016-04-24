@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=merging_tables
set file=merging_tables

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
