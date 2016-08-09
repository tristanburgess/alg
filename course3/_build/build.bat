@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=bfs
set file=bfs

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
