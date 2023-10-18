set(LIBRARY_SOURCES
    date.cpp
)

set(LIBRARY_HEADERS
    date.hpp
)

set(LIBRARY_INCLUDES
    "./"
)

add_library(${LIBRARY_DATES} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_DATES} PUBLIC
    ${LIBRARY_INCLUDES})

# target_link_libraries(${LIBRARY_DATES} PUBLIC
#                         ${LIBRARY_RANDOM})
