#pragma once

#include <map>
#include <vector>
#include <set>

#include "atom.h"
#include "cartesian_atomic_coordinates.h"

double MaxBoundLength();

class DistancesManager{
public:
    DistancesManager(const CartesianAtomsCoordinates& c_cords);

    size_t Size() const;

    Atom GetAtom(const Atom& main_atom, int number) const;

    Atom GetFirstAtom() const;

    double GetDistance(const Atom& atom1, const Atom& atom2) const;

    void RemoveDistance(const Atom& atom1, const Atom& atom2);

//    Atom GetAtomFromMassCenter(int number) const;

    set<Atom>::iterator begin();

    set<Atom>::iterator end();

    set<Atom>::const_iterator begin() const;

    set<Atom>::const_iterator end() const;

    bool CheckEpoxide(const Atom& atom) const;

    bool CheckFrameInternalCarbon(const Atom& atom) const;

    bool CheckFrameExternalCarbon(const Atom& atom) const;

    bool CheckFrameExternalHydrogen(const Atom& atom) const;

    bool CheckFrameInternalCarbonUnderFG(const Atom& atom) const;

    bool CheckFrameInternalCarbonUnderEpox(const Atom& atom) const;

    bool CheckFrameInternalCarbonUnderHydro(const Atom& atom) const;

    bool CheckHydroxydeOxygen(const Atom& atom) const;

    bool CheckHydroxydeHydrogen(const Atom& atom) const;


private:
    set<Atom> atoms_;
    map<Atom, vector<pair<double, Atom>>> distances_;
    map<Atom, map<Atom, double>> atoms_to_distances_;
    vector<pair<double, Atom>> to_mass_center_;

};
