#ifndef B1LCell_h
#define B1LCel_h 1

#include "globals.hh"
#include <vector>
#include "G4LogicalVolume.hh"


class G4Material;
class G4FieldManager;
class G4VSensitiveDetector;
class G4UserLimits;
class SCell;

class LCell:public G4LogicalVolume  {
public:
  LCell(SCell*, G4Material*,
        const G4String&,
        G4FieldManager* d=0, G4VSensitiveDetector* e=0, G4UserLimits* f=0, G4bool g=true);
  ~LCell();

// custom methods

  SCell* GetSolid(){
    return fSolid;
  }

private:
  SCell *fSolid = nullptr;
};

#endif