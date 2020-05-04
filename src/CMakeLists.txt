project(Flou_src)

add_executable(${PROJECT_NAME}_exe core/ValueModel.h main.cpp core/BinaryExpressionModel.h core/BinaryExpression.h fuzzy/And.h fuzzy/Or.h fuzzy/Then.h fuzzy/Agg.h fuzzy/MamdaniDeFuzz.h fuzzy/SugenoConclusion.h fuzzy/CogDefuzz.h fuzzy/AndMin.h fuzzy/AndMult.h fuzzy/OrMax.h fuzzy/OrPlus.h fuzzy/ThenMin.h fuzzy/ThenMult.h fuzzy/SugenoThen.h fuzzy/AggMax.h fuzzy/AggPlus.h fuzzy/IsGaussian.h core/ExpressionFactory.h fuzzy/FuzzyFactory.h core/BinaryShadowExpression.h core/UnaryShadowExpression.h fuzzy/IsBell.h fuzzy/SugenoConclusion.h fuzzy/SugenoDefuzz.h calculate/Commands.h calculate/Execute.h calculate/Variables.h calculate/File.h calculate/Function.h calculate/Exe_operation.h core/NaryExpressionModel.h core/NaryShadowExpression.h)

