#include "HumanCell.hh"
#include "G4VSolid.hh"
#include "G4ThreeVector.hh"
#include "G4MultiUnion.hh"
#include "G4Transform3D.hh"
#include "G4SystemOfUnits.hh"
//#include "CustomMaterials.hh"

HumanCell::HumanCell(G4String name, G4double x_pos, G4double y_pos, G4double z_pos, G4LogicalVolume* mother_volume_log, G4double maxStep)
{

  G4NistManager* nist = G4NistManager::Instance();
  G4Material* pCellMaterial = nist->FindOrBuildMaterial("G4_WATER");



  G4Ellipsoid* pCell_El_Solid = new G4Ellipsoid
  (
    "Cell_El_Solid",
    El_axisX,
    El_axisY,
    El_axisZ,
     0,
     0
  );

/*
  G4LogicalVolume *  pCell_El_Logic = new G4LogicalVolume
  (
    pCell_El_Solid,
    pCellMaterial,
    "Cell_El_Logic"
  );

  G4VPhysicalVolume  *pCell_El_Placement = new G4PVPlacement
   (
    nullptr,  // no rotation
    G4ThreeVector(x_pos, y_pos, z_pos),                          // at (0,0,0)
    pCell_El_Logic,                                // its logical volume
    "Cell_El_Placement",                        // its name
     mother_volume_log,                                   // its mother  volume
    false,                                     // no boolean operation
    0,                                         // copy number
    true                                       // overlaps checking
   );

*/


// ==============  cell restraining box ========================================
   G4Box* pCell_Box_Solid = new G4Box
   (
     "Cell_Box_Solid",
     Box_axisX,
     Box_axisY,
     Box_axisZ
   );


/*
   G4LogicalVolume *  pCell_Box_Logic = new G4LogicalVolume
   (
     pCell_Box_Solid,
     pCellMaterial,
     "Cell_Box_Logic"
   );

   G4VPhysicalVolume  *pCell_Box_Placement = new G4PVPlacement
    (
     nullptr,  // no rotation
     G4ThreeVector(x_pos, y_pos, z_pos),                          // at (0,0,0)
     pCell_Box_Logic,                                // its logical volume
     "Cell_Box_Placement",                        // its name
      mother_volume_log,                                   // its mother  volume
     false,                                     // no boolean operation
     0,                                         // copy number
     true                                       // overlaps checking
    );
    */
// =============================================================================



// ============== eventual  cell shape  ========================================
 G4VSolid* pCell_EventualShape_Solid = new G4IntersectionSolid("Cell_EventualShape_Solid",  pCell_El_Solid, pCell_Box_Solid, nullptr, G4ThreeVector(0, 0, 0*um));

 G4LogicalVolume *  pCell_EventualShape_Logic = new G4LogicalVolume
 (
   pCell_EventualShape_Solid,
   pCellMaterial,
   "Cell_EventualShape_Logic"
 );

 G4VPhysicalVolume  *pCell_EventualShape_Placement = new G4PVPlacement
  (
   nullptr,  // no rotation
   G4ThreeVector(x_pos, y_pos, z_pos),                          // at (0,0,0)
   pCell_EventualShape_Logic,                                // its logical volume
   "Cell_EventualShape_Placement",                        // its name
    mother_volume_log,                                   // its mother  volume
   false,                                     // no boolean operation
   0,                                         // copy number
   true                                       // overlaps checking
  );

// =============================================================================



// ====================== Cell Nucleus  ========================================
G4Ellipsoid* pCell_Nuc_Solid = new G4Ellipsoid
(
  "Cell_Nuc_Solid",
  El_Nuc_axisX,
  El_Nuc_axisY,
  El_Nuc_axisZ,
   0,
   0
);

G4LogicalVolume *  pCell_Nuc_Logic = new G4LogicalVolume
(
  pCell_Nuc_Solid,
  pCellMaterial,
  "Cell_Nuc_Logic"
);

G4VPhysicalVolume  *pCell_Nuc_Placement = new G4PVPlacement
 (
  nullptr,  // no rotation
  G4ThreeVector(Nuc_X, Nuc_X, Nuc_X),                          // at (0,0,0)
  pCell_Nuc_Logic,                                // its logical volume
  "Cell_Nuc_Placement",                          // its name
  pCell_EventualShape_Logic,                     // its mother  volume
  false,                                         // no boolean operation
  0,                                             // copy number
  true                                           // overlaps checking
 );

 // =============================================================================






   auto fStepLimit = new G4UserLimits(maxStep);
   pCell_EventualShape_Logic ->SetUserLimits(fStepLimit); // final object


}
