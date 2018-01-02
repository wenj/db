cmake_minimum_required(VERSION 3.8)
project(mydb)

set(CMAKE_CXX_STANDARD 11)

set(BASE_DIR "${PROJECT_SOURCE_DIR}")
set(UTIL_DIR "utils")
set(PF_DIR "pf")
set(RM_DIR "rm")
set(IX_DIR "ix")
set(SMQL_DIR "smql")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Lexer和Parser
set(FLEX_EXECUTABLE ${LIB_DIR}/flex/flex)
set(YACC_EXECUTABLE ${LIB_DIR}/byacc/yacc)
set(FlexInput ${CMAKE_CURRENT_SOURCE_DIR}/${SMQL_DIR}/lexer.l)
set(YACCInput ${CMAKE_CURRENT_SOURCE_DIR}/${SMQL_DIR}/parser.y)
set(FlexOutput ${CMAKE_CURRENT_SOURCE_DIR}/${SMQL_DIR}/lexer.c)
set(YACCOutputHeader ${CMAKE_CURRENT_SOURCE_DIR}/${SMQL_DIR}/parser.h)
set(YACCOutputSource ${CMAKE_CURRENT_SOURCE_DIR}/${SMQL_DIR}/parser.cc)
ADD_CUSTOM_COMMAND(
        OUTPUT ${FlexOutput}
        COMMAND ${FLEX_EXECUTABLE} ${FlexInput}
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/rename_lex
        COMMENT "Generating lexer.c"
)
ADD_CUSTOM_COMMAND(
        OUTPUT ${YACCOutputHeader} ${YACCOutputSource}
        COMMAND ${YACC_EXECUTABLE} -d ${YACCInput}
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/rename_yacc
        COMMENT "Generating parser.cc"
)

set(SOURCE_FILES main.cpp
        ${UTIL_DIR}/statistics.cc
        ${PF_DIR}/pf_buffermgr.cc ${PF_DIR}/pf_error.cc ${PF_DIR}/pf_filehandle.cc ${PF_DIR}/pf_hashtable.cc
            ${PF_DIR}/pf_manager.cc ${PF_DIR}/pf_pagehandle.cc ${PF_DIR}/pf_statistics.cc
        ${RM_DIR}/rm_error.cc ${RM_DIR}/rm_filehandle.cc ${RM_DIR}/rm_filescan.cc ${RM_DIR}/rm_manager.cc
            ${RM_DIR}/rm_record.cc ${RM_DIR}/rm_rid.cc
        ${IX_DIR}/ix_indexhandle.cc ${IX_DIR}/ix_indexscan.cc ${IX_DIR}/ix_manager.cc
        ${FlexOutput} ${YACCOutputSource}
        ${SMQL_DIR}/Tree.cpp smql/YYSTYPE.h utils/IndentOstream.cpp utils/IndentOstream.h utils/strptime.cpp utils/strptime.h smql/BFParse.cpp smql/BFParse.h)

add_executable(mydb ${SOURCE_FILES})

include_directories(
        "${UTIL_DIR}"
        "${PF_DIR}"
        "${RM_DIR}"
        "${IX_DIR}"
        "${SMQL_DIR}"
)