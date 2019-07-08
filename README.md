# grpc_openenclave
Please note that this prototype is built on OE v0.5
## Build instructions
### Clone repo
`git clone https://github.com/openenclave/openenclave-grpc.git --recursive`

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

# Contributing

This project welcomes contributions and suggestions. Most contributions require you to
agree to a Contributor License Agreement (CLA) declaring that you have the right to,
and actually do, grant us the rights to use your contribution. For details, visit
https://cla.microsoft.com.

When you submit a pull request, a CLA-bot will automatically determine whether you need
to provide a CLA and decorate the PR appropriately (e.g., label, comment). Simply follow the
instructions provided by the bot. You will only need to do this once across all repositories using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/)
or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.
