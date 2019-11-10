add_library(AutomataLibrary SHARED Automate.cpp State.cpp)

install(
        TARGETS AutomataLibrary
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
)