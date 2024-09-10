if [[ ! -e ./add_hw_interface.sh  ]]; then
    echo execute $0 from src dir
    exit 1
fi

if [[ $# != 1 ]]; then
    echo usage $0 interface_name
    exit 2
fi

interface=$1
upp_inte=$(echo $interface | tr a-z A-Z)

cp -r ./dummy $interface

sed -i "s/dummy/$interface/g" ./$interface/Makefile
sed -i "s/DUMMY/$upp_inte/g" ./$interface/Makefile

sed -i "s/DUMMY/$upp_inte/g" ./$interface/dummy.c
sed -i "s/DUMMY/$upp_inte/g" ./$interface/dummy.h

mv ./$interface/dummy.c ./$interface/$interface.c
mv ./$interface/dummy.h ./$interface/$interface.h
