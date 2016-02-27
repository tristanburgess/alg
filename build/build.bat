@echo off

set CommonCompilerFlags=-O2 -EHa
set file=different_summands

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%file%.cpp
popd
