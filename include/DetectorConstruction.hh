//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//


#ifndef B1DetectorConstruction_h
#define B1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4UserLimits.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4PVPlacement.hh"
#include "G4HumanPhantomMaterial.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;

/// Detector construction class to define materials and geometry.


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction() override;

    G4VPhysicalVolume* Construct() override;

    std::vector<G4VPhysicalVolume*> GetScoringVolumes() const { return fScoringVolumes; }

// Detector parameters


    //const G4double cell_size_XY = 10.0*um, cell_size_Z = 10.0*um;
    const G4double env_sizeXY = 25*um, env_sizeZ = 25*um;
    const G4ThreeVector pos2 = G4ThreeVector(0*um, 0*um, 0.0*um);
    G4double world_sizeXY = 1.4*env_sizeXY;
    G4double world_sizeZ  = 1.4*env_sizeZ;

//==================================================================================

// =========== vectors of coordinates of scoring volumes =========================
std::vector<G4double> vPos_X;
std::vector<G4double> vPos_Y;
std::vector<G4double> vPos_Z;
//==============================================================================


  private:
    G4UserLimits* fStepLimit = nullptr;
    void ConstructScoringVolumes();

  protected:
    std::vector<G4VPhysicalVolume*> fScoringVolumes {};
    G4int N_vol;
};


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
