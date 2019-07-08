# grpc_openenclave
## Build instructions
### Clone repo
`git clone https://github.com/radhikaj/grpc_openenclave.git --recursive`

`cd ~/grpc_openenclave`

`git submodule --update`

### Apply patches to submodules
`sh apply_patch.sh`

### Build openenclave for grpc and install
`cd openenclave`

`mkdir build`

`cd build`

`cmake ..`

`make`

`cmake -DCMAKE_INSTALL_PREFIX:PATH=/opt/openenclave-grpc ..`

`sudo make install`

`. /opt/openenclave-grpc/share/openenclave/openenclaverc`

### Build grpc against OE headers
`cd ../../grpc`

`mkdir build`

`cd build`

`cmake ..`

`make`

### Build and run grpc server
`cd ../../grpcsample`

`make`

`host/helloworldhost enc/helloworldenc.so.signed`

