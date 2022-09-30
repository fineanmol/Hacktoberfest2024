#!/bin/bash
# $1= Link
# $2= File Type
lynx -dump -listonly -nonumbers "$1" | grep -i "\.$2$"