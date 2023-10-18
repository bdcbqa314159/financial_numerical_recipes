set(EXE_SOURCES
    main.cpp)

add_executable(${EXECUTABLE_DATES} ${EXE_SOURCES})
target_link_libraries(${EXECUTABLE_DATES} PUBLIC ${LIBRARY_IR})
