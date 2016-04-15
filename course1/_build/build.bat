@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set file=lcs3

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%file%.cpp
popd
