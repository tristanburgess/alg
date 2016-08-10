@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=bipartite
set file=bipartite

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
