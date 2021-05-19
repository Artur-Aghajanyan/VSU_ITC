#!/bin/bash

sed -i.$(date +%F) '/^#/d' filename
sed -i 's:^//.*$::g' filename



