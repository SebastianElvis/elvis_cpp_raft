add_library(Network Server.cpp)
target_link_libraries(Network -lzmqpp -lboost_system)