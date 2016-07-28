@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=hash_substring
set file=hash_substring

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
