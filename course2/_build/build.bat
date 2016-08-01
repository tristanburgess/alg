@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=rope
set file=rope

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
