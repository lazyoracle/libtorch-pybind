wget -O libtorch-installer https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.10.2%2Bcpu.zip
unzip libtorch-installer
export TORCH_PATH="$PWD/libtorch"
ltpbdir=".ltpb/lib"
mkdir -p $HOME/$ltpbdir
cp libtorch/lib/* $HOME/$ltpbdir/
rm libtorch-installer
