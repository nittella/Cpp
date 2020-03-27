#include "conditions.h"

bool CheckEpoxide(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result = (item.first.type == AtomType::O
                   && item.second[0].first < MaxBoundLength()
                   && item.second[0].second.type == AtomType::C
                   && item.second[1].first < MaxBoundLength()
                   && item.second[1].second.type == AtomType::C);
    return result;
};

bool CheckFrameInternalCarbon(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result = (item.first.type == AtomType::C
                   && item.second[0].first < MaxBoundLength()
                   && item.second[0].second.type == AtomType::C
                   && item.second[1].first < MaxBoundLength()
                   && item.second[1].second.type == AtomType::C
                   && item.second[2].first < MaxBoundLength()
                   && item.second[2].second.type == AtomType::C
    );
    return result;
};

bool CheckFrameExternalCarbon(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result= (item.first.type == AtomType::C
                  && item.second[0].first < MaxBoundLength()
                  && item.second[0].second.type == AtomType::H
    );
    return result;
};

bool CheckFrameExternalHydrogen(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result = (item.first.type == AtomType::H
                   && item.second[0].first < MaxBoundLength()
                   && item.second[0].second.type == AtomType::C
    );
    return result;
}


bool CheckFrameInternalCarbonUnderFG(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result = (item.first.type == AtomType::C
    &&item.second[0].first < MaxBoundLength()
    && item.second[0].second.type == AtomType::O
    && item.second[1].first < MaxBoundLength()
    && item.second[1].second.type == AtomType::C
    && item.second[2].first < MaxBoundLength()
    && item.second[2].second.type == AtomType::C
    && item.second[3].first < MaxBoundLength()
    && item.second[3].second.type == AtomType::C
    );
    return result;
}

bool CheckHydroxydeOxygen(const pair<Atom, vector<pair<double, Atom>>>& item){
    bool result = (item.first.type == AtomType::O
                   && item.second[0].first < MaxBoundLength()
                   && item.second[0].second.type == AtomType::H
                   && item.second[1].first < MaxBoundLength()
                   && item.second[1].second.type == AtomType::C);
    return result;
};

bool CheckHydroxydeHydrogen(const pair<Atom, vector<pair<double, Atom>>>& item);