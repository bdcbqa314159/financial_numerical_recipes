set(EXE_SOURCES
    main.cpp)

add_executable(${EXECUTABLE_TIME_VALUE} ${EXE_SOURCES})
target_link_libraries(${EXECUTABLE_TIME_VALUE} PUBLIC ${LIBRARY_TIME_VALUE})
