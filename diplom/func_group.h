#pragma once

enum class FunctionalGroupType{
    Hydroxyl,
    Epoxide,
    Carboxyl,
    Other
};

map<FunctionalGroupType, InternalCoordinateTypeName> FUNC_GROUP_TO_INTERNAL_COORD_TYPE = {
        {FunctionalGroupType::Hydroxyl, InternalCoordinateTypeName::Type1},
        {FunctionalGroupType::Epoxide, InternalCoordinateTypeName::Type1},
        {FunctionalGroupType::Carboxyl, InternalCoordinateTypeName::Type1},
        {FunctionalGroupType::Other, InternalCoordinateTypeName::Type1}
};
