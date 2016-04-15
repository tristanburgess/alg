@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=tree_height
set file=tree-height

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
