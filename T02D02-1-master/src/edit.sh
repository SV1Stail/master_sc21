#!/bin/bash

read  path
read  stroka
read  zamena

sed -i '' "s/${stroka}/${zamena}/g" "${path}"

#year=`date -r ${path}`

echo $year2
d=`wc -c< ${path}`
dt=`date +"%Y-%m-%d %H:%M"`
sha=`shasum -a 256 $path`
delim=" "
sha_r=${sha%$delim*}
echo "$path - $d - $dt - $sha_r- sha256">>c.log

