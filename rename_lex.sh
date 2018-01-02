#!/usr/bin/env bash
rm lexer.cc
rm ../smql/lexer.cc
mv lex.yy.cc lexer.cc
mv lexer.cc ../smql/