# An UEFI Learning Environemnt with EDK II Multi Workspace Feature

This project aims to create an learning environment for Edk II, placing all learning code out of Edk repo.

By using Multi Workspace Feature, this project can help add custom modules into EDK II official Ovmf firmware.

## How to Setup Build Environment

This project is created under `Ubuntu 24.04 LTS`, using same environment is highly recommended.

1. Install required packages.

The following packages are required to setup build environments.

```bash
$ sudo apt install build-essential uuid-dev iasl git  nasm  python-is-python3
```

2. Clone repo

```bash
edk-multipath-example$ git clone --recurse-submodules git@github.com:xiaobaigou1000/edk-multipath-example.git
```

3. Setup Edk II Build Tools

```bash
edk-multipath-example$ cd edk2
edk-multipath-example/edk2$ make -C BaseTools
```

4. Change `edk2/Conf/target.txt` file.

```
ACTIVE_PLATFORM       = MyOvmfPkg/MyOvmfPkgX64.dsc
TARGET                = DEBUG
TARGET_ARCH           = X64
TOOL_CHAIN_TAG        = GCC5
```

5. Build custom Ovmf firmware.

```bash
edk-multipath-example$ source setup_build_env.sh
edk-multipath-example$ build
```