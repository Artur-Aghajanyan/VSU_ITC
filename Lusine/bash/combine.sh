#!/bin/bash

mkdir text
find myDir -name 'text*' -exec mv -t text {} +
