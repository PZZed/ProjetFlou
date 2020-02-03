project(Flou_src)

add_executable(${PROJECT_NAME}_exe core/ValueModel.h core/UnaryExpression.h fuzzy/NotMinus1.h main.cpp fuzzy/IsTriangle.h core/UnaryExpressionModel.h)