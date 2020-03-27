#pragma once

#include <map>
#include <vector>

#include "cartesian_atomic_coordinates.h"

using namespace std;

double MaxBoundLength();

bool CheckEpoxide(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckFrameInternalCarbon(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckFrameExternalCarbon(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckFrameExternalHydrogen(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckFrameInternalCarbonUnderFG(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckHydroxydeOxygen(const pair<Atom, vector<pair<double, Atom>>>& item);

bool CheckHydroxydeHydrogen(const pair<Atom, vector<pair<double, Atom>>>& item);
