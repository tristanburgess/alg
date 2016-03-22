@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set file=merge_sorting

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%file%.cpp
popd
