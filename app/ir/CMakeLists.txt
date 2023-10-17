set(EXE_SOURCES
    main_ir.cpp)

add_executable(${EXECUTABLE_IR} ${EXE_SOURCES})
target_link_libraries(${EXECUTABLE_IR} PUBLIC ${LIBRARY_IR})
