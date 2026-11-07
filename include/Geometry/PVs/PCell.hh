#ifndef B1PCell_h
#define B1PCel_h 1

#include "globals.hh"
#include <vector>
#include "G4PVPlacement.hh"


class PNP;
class LCell;
class PNucleus;
class SCell;
class G4Material;

class PCell:public G4PVPlacement  {
public:
  PCell(G4RotationMatrix*, const G4ThreeVector, LCell*, const G4String, G4LogicalVolume*, G4bool, G4int, G4bool);
  ~PCell();

// custom methods

std::vector<PNP*> GetNPs(){
  return fNPs;
} 

PNucleus* GetNucleus(){
  return fNucleus;
}  

SCell* GetSolid(){
  return fSolid;
}

LCell* GetLog(){
  return fLog;
}

G4String GetName(){
  return fName;
}
void SetNPs(G4Material*);
void SetNucleus(G4Material*, G4double);

private:
  std::vector<PNP*> fNPs = {};
  PNucleus* fNucleus = nullptr;
  SCell* fSolid = nullptr;
  LCell* fLog = nullptr;
  G4String fName;
  G4Material *fNucleusMaterial; 
  G4PVPlacement* fActualPlacement;
};

#endif