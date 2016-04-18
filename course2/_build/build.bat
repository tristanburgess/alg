@echo off

set CommonCompilerFlags=-O2 -EHa -Zi
set dir=network_packet_processing_simulation
set file=process_packages

IF NOT EXIST %file% mkdir %file%
pushd %file%
cl %CommonCompilerFlags% ..\..\%dir%\%file%.cpp
popd
