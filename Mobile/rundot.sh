#!/bin/bash

# 拜占庭项目中rundot.bat的shell脚本改写
# 用于该项目在Linux下将output中的所有dot文件转化为svg图片, 并且放在同级的pic下
# 注意: 确保已经安装了graphviz

rootdir=$(pwd)
read -t 30 -p "1. transform 2. delete all svg [1/2]? " choose

if [ $choose == 1 ]; then
    for dir in $(ls -R $rootdir | grep ":" | grep "src" | cut -d ':' -f 1); do
        echo "transforming in $dir..."
        for dots in $(ls $dir); do
            # echo "Transforming $dots into ../pic/$dots.svg..."
            dot -Tsvg $dir/$dots -o $dir/../pic/$dots.svg
            # echo "done!"
        done
        echo "done in $dir"
        echo "=============================================="
    done;
    echo "Transform success"
elif [ $choose == 2 ]; then
    for dir in $(ls -R $rootdir | grep ":" | grep "pic" | cut -d ':' -f 1); do
        echo "deleting in $dir..."
        rm $dir/*.svg
        echo "done in $dir"
        echo "=============================================="
    done
    echo "Delete success"
else
    exit 10
fi

