CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(UNP_SERVER)

MACRO(source_group_by_dir source_files)
	SET(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
	FOREACH(sgbd_file ${${source_files}})
		STRING(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
		STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
		STRING(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
		IF(MSVC)
			string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
		ENDIF(MSVC)
		IF(sgbd_nogroup)
			SET(sgbd_group_name "\\")
		ENDIF(sgbd_nogroup)
		SOURCE_GROUP(${sgbd_group_name} FILES ${sgbd_file})
	ENDFOREACH(sgbd_file)
ENDMACRO(source_group_by_dir)




SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin/")

INCLUDE_DIRECTORIES(
  ./include
  )

SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c99 -Wall -g" )

FILE(GLOB_RECURSE all_files
  ./include/*.h
  ./src/*.c
  ./main.c
  )


ADD_EXECUTABLE(UNP_server ${all_files})
  


