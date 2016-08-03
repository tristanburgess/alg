@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=connected_components
set file=connected_components

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
