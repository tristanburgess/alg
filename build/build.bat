@echo off

set CommonCompilerFlags=-O2 -EHa
set file=min_refills

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%file%.cpp
popd
