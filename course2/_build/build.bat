@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=set_range_sum
set file=set_range_sum

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
