#!/usr/bin/env bash
rm parser.cc
rm parser.h
rm ../smql/parser.cc
rm ../smql/parser.h
mv y.tab.c parser.cc
mv y.tab.h parser.h
mv parser.cc ../smql/
mv parser.h ../smql/
