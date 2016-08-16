@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=connecting_points
set file=connecting_points

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
