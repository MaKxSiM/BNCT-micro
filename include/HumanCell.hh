#ifndef HumanCell_h
#define HumanCell_h 1

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Ellipsoid.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4UserLimits.hh"


#include "globals.hh"
#include "G4TwoVector.hh"


class HumanCell{
public:

  HumanCell(G4String, G4double, G4double, G4double, G4LogicalVolume*, G4double);
  ~HumanCell();

  G4double El_axisX = 12 * um;
  G4double El_axisY = 18 * um;
  G4double El_axisZ = 18 * um;

  G4double Box_axisX = 10 * um;
  G4double Box_axisY = 10 * um;
  G4double Box_axisZ = 20 * um;


  G4double El_Nuc_axisX = 6 * um;
  G4double El_Nuc_axisY = 8 * um;
  G4double El_Nuc_axisZ = 8 * um;

  G4double Nuc_X = 0 * um;
  G4double Nuc_Y = 0 * um;
  G4double Nuc_Z = 0 * um;


private:

};

#endif
