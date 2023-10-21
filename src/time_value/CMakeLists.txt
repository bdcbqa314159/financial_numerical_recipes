set(LIBRARY_SOURCES
    time_value.cpp
)

set(LIBRARY_HEADERS
    time_value.hpp
)

set(LIBRARY_INCLUDES
    "./"
)

add_library(${LIBRARY_TIME_VALUE} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_TIME_VALUE} PUBLIC
    ${LIBRARY_INCLUDES})
