#ifndef B1SCell_h
#define B1SCell_h 1

#include "globals.hh"
#include <vector>
#include "G4VSolid.hh"


class G4Ellipsoid;

class SCell:public G4VSolid  {
public:
  SCell(G4String,G4double, G4double);

  ~SCell();

  EInside Inside(const G4ThreeVector& p) const override;
  G4ThreeVector SurfaceNormal(const G4ThreeVector& p) const override;
  G4double DistanceToIn(const G4ThreeVector& p, const G4ThreeVector& v) const override;
  G4double DistanceToIn(const G4ThreeVector& p) const override;
  G4double DistanceToOut(const G4ThreeVector& p, const G4ThreeVector& v, const G4bool calcNorm=false, G4bool *validNorm=nullptr, 
                            G4ThreeVector *n=nullptr) const override;
  G4double DistanceToOut(const G4ThreeVector& p) const override;
  void ComputeDimensions(G4VPVParameterisation* p, const G4int n, const G4VPhysicalVolume* pRep) override;
        
  G4GeometryType GetEntityType() const override;
  G4VSolid* Clone() const override;
  std::ostream& StreamInfo(std::ostream& os) const override;
  void 	DescribeYourselfTo (G4VGraphicsScene &scene) const override;

  G4bool CalculateExtent (const EAxis pAxis, const G4VoxelLimits &pVoxelLimit, const G4AffineTransform &pTransform, G4double &pMin, G4double &pMax) const override; 

  G4ThreeVector GetPointOnSurface () const override;
  G4Polyhedron * 	CreatePolyhedron () const override;

  void BoundingLimits(G4ThreeVector& pMin, G4ThreeVector& pMax) const override;

// custom methods

  std::vector<G4double> GetDimensions(){
    return fDimensions;
  }


private:
    G4VSolid* fActualShape = nullptr;
    std::vector<G4double> fDimensions = {};

};
    
#endif