add_executable (Singleton
 
 
"main.cpp"
 "Database.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Singleton PROPERTY CXX_STANDARD 20)
endif()

